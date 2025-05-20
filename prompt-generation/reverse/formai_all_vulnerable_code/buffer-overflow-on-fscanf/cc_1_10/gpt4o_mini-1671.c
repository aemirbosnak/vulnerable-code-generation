//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
    float memory_usage;
} ProcessInfo;

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void print_header() {
    printf("\033[1;34m"); // Set text color to blue
    printf("PID\tNAME\t\tSTATE\t\tMEMORY (KB)\n");
    printf("-------------------------------------------------------\n");
    printf("\033[0m"); // Reset text color
}

void print_process_info(ProcessInfo process) {
    printf("%d\t%-15s\t%-10s\t%.2f\n", process.pid, process.name, process.state, process.memory_usage);
}

void fetch_process_info(ProcessInfo *process) {
    char path[BUFFER_SIZE];
    char mem_info[BUFFER_SIZE];
    
    // Fetch the process name and state
    snprintf(path, sizeof(path), "/proc/%d/stat", process->pid);
    FILE *stat_file = fopen(path, "r");
    if (stat_file) {
        fscanf(stat_file, "%d %s %s", &process->pid, process->name, process->state);
        fclose(stat_file);
        
        // Remove parentheses from process name if present
        char *name_ptr = strchr(process->name, '(');
        if (name_ptr) {
            *name_ptr = '\0'; // End the string
        }
        
        // Fetch memory information
        snprintf(path, sizeof(path), "/proc/%d/statm", process->pid);
        FILE *mem_file = fopen(path, "r");
        if (mem_file) {
            fscanf(mem_file, "%*s %f", &process->memory_usage);
            fclose(mem_file);
        } else {
            process->memory_usage = 0.0;
        }
    }
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return;
    }
    
    print_header();
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            ProcessInfo process;
            process.pid = atoi(entry->d_name);
            fetch_process_info(&process);
            
            if (process.memory_usage > 0) {
                print_process_info(process);
            }
        }
    }
    
    closedir(proc_dir);
}

int main() {
    while (1) {
        clear_screen();
        printf("\033[1;32m"); // Set text color to green
        printf("System Process Viewer\n");
        printf("\033[0m"); // Reset text color
        printf("Press Ctrl+C to exit...\n\n");
        
        list_processes();
        
        // Refresh every 2 seconds
        sleep(2);
    }
    return 0;
}