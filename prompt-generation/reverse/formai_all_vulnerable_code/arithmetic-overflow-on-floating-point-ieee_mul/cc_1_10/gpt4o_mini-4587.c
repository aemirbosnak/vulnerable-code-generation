//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_LENGTH 256

typedef struct {
    int pid;
    char comm[256];
    float cpu_usage;
    float mem_usage;
} Process;

int read_process_info(int pid, Process *process);
int compare_cpu_usage(const void *a, const void *b);
int compare_mem_usage(const void *a, const void *b);
void display_processes(Process *processes, int count);

int main() {
    DIR *dir;
    struct dirent *entry;
    Process processes[MAX_PROCESSES];
    int count = 0;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Could not open /proc directory");
        return EXIT_FAILURE;
    }

    // Read all process directories in /proc
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            if (read_process_info(pid, &processes[count]) == 0) {
                count++;
            }
        }
    }
    closedir(dir);

    // Sort processes by CPU usage
    qsort(processes, count, sizeof(Process), compare_cpu_usage);

    // Display the processes
    display_processes(processes, count);

    return EXIT_SUCCESS;
}

int read_process_info(int pid, Process *process) {
    char path[MAX_LINE_LENGTH];
    FILE *file;
    float mem_size = 0.0, mem_total = 0.0;
    float cpu_time = 0.0, cpu_total_time = 0.0;
    int process_mem = 0;
    // Construct the status file path
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    
    file = fopen(path, "r");
    if (file == NULL) {
        return -1; // Failed to open the file
    }
    
    // Read process information from /proc/[pid]/stat
    fscanf(file, "%d %s %*s %*s %*s %*s %d %d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d %*s %*s %f %*s", 
                  &process->pid, process->comm, &process_mem, &cpu_time);
    
    // CPU usage is computed from the time of this process
    cpu_total_time = (float) (sysconf(_SC_CLK_TCK) * cpu_time);

    // Read memory from /proc/[pid]/statm
    snprintf(path, sizeof(path), "/proc/%d/statm", pid);
    file = fopen(path, "r");
    if (file != NULL) {
        fscanf(file, "%*s %f", &mem_size);
        fclose(file);
    }

    process->cpu_usage = cpu_total_time; // For simplification, using only raw cpu time
    process->mem_usage = mem_size; // In pages, could be multiplied by the page size if needed
    return 0;
}

int compare_cpu_usage(const void *a, const void *b) {
    Process *procA = (Process *)a;
    Process *procB = (Process *)b;
    return (procB->cpu_usage - procA->cpu_usage) > 0 ? 1 : 0;
}

void display_processes(Process *processes, int count) {
    printf("%-10s %-25s %-15s %-15s\n", "PID", "COMMAND", "CPU USAGE", "MEM USAGE");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-15f %-15f\n", 
            processes[i].pid, processes[i].comm, 
            processes[i].cpu_usage, processes[i].mem_usage);
    }
}