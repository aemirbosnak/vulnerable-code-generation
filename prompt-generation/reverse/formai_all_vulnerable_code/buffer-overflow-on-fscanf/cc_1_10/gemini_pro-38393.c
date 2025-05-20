//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

// Define the maximum number of processes to display
#define MAX_PROCESSES 100

// Define the structure of a process
typedef struct {
    pid_t pid;          // The process ID
    char *name;         // The process name
    char *state;        // The process state
    int cpu_usage;      // The CPU usage of the process
    int memory_usage;   // The memory usage of the process
} process_t;

// Define the function to compare two processes
int compare_processes(const void *a, const void *b) {
    process_t *process1 = (process_t *)a;
    process_t *process2 = (process_t *)b;

    // Sort the processes by PID
    return process1->pid - process2->pid;
}

// Define the function to get the process information
int get_process_info(process_t *processes, int *num_processes) {
    // Open the directory containing the process information
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Loop through the directory entries
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        // Skip non-numeric directory entries
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        // Get the process ID
        pid_t pid = atoi(entry->d_name);

        // Get the process name
        char *name = NULL;
        char path[256];
        snprintf(path, sizeof(path), "/proc/%d/comm", pid);
        FILE *fp = fopen(path, "r");
        if (fp != NULL) {
            fscanf(fp, "%ms", &name);
            fclose(fp);
        }

        // Get the process state
        char *state = NULL;
        snprintf(path, sizeof(path), "/proc/%d/stat", pid);
        fp = fopen(path, "r");
        if (fp != NULL) {
            char line[1024];
            if (fgets(line, sizeof(line), fp) != NULL) {
                char *ptr = line;
                while (*ptr != ' ') {
                    ptr++;
                }
                ptr++;
                state = strdup(ptr);
            }
            fclose(fp);
        }

        // Get the process CPU usage
        int cpu_usage = 0;
        snprintf(path, sizeof(path), "/proc/%d/stat", pid);
        fp = fopen(path, "r");
        if (fp != NULL) {
            char line[1024];
            if (fgets(line, sizeof(line), fp) != NULL) {
                char *ptr = line;
                while (*ptr != ' ') {
                    ptr++;
                }
                ptr++;
                while (*ptr != ' ') {
                    ptr++;
                }
                ptr++;
                while (*ptr != ' ') {
                    ptr++;
                }
                ptr++;
                while (*ptr != ' ') {
                    ptr++;
                }
                ptr++;
                cpu_usage = atoi(ptr);
            }
            fclose(fp);
        }

        // Get the process memory usage
        int memory_usage = 0;
        snprintf(path, sizeof(path), "/proc/%d/statm", pid);
        fp = fopen(path, "r");
        if (fp != NULL) {
            char line[1024];
            if (fgets(line, sizeof(line), fp) != NULL) {
                char *ptr = line;
                while (*ptr != ' ') {
                    ptr++;
                }
                ptr++;
                memory_usage = atoi(ptr);
            }
            fclose(fp);
        }

        // Add the process to the array
        processes[*num_processes].pid = pid;
        processes[*num_processes].name = name;
        processes[*num_processes].state = state;
        processes[*num_processes].cpu_usage = cpu_usage;
        processes[*num_processes].memory_usage = memory_usage;
        *num_processes = *num_processes + 1;
    }

    // Close the directory
    closedir(proc_dir);

    // Return 0 on success
    return 0;
}

// Define the function to print the process information
void print_process_info(process_t *processes, int num_processes) {
    // Print the header
    printf("PID\tName\t\tState\tCPU\tMemory\n");

    // Print the process information
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%-16s\t%s\t%d%%\t%d MB\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].cpu_usage, processes[i].memory_usage);
    }
}

// Define the main function
int main(void) {
    // Get the process information
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    if (get_process_info(processes, &num_processes) != 0) {
        return -1;
    }

    // Sort the processes by PID
    qsort(processes, num_processes, sizeof(process_t), compare_processes);

    // Print the process information
    print_process_info(processes, num_processes);

    // Free the memory allocated for the process names and states
    for (int i = 0; i < num_processes; i++) {
        free(processes[i].name);
        free(processes[i].state);
    }

    // Return 0 on success
    return 0;
}