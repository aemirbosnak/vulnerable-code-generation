//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[256];
    int priority;
    unsigned long memory;
} Process;

Process processes[MAX_PROCESSES];
int process_count = 0;

void display_processes() {
    printf("\nPID\t\tName\t\t\tPriority\tMemory (KB)\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < process_count; i++) {
        printf("%d\t\t%-20s\t%d\t\t%lu\n", processes[i].pid,
               processes[i].name, processes[i].priority, processes[i].memory);
    }
    printf("--------------------------------------------------------------\n");
}

void optimize_processes() {
    for (int i = 0; i < process_count; i++) {
        // Example optimization: raise priority of processes using more than 512 KB of memory
        if (processes[i].memory > 512 * 1024) {
            processes[i].priority += 1;
            if (processes[i].priority > 20) {
                processes[i].priority = 20; // Set max priority
            }
            printf("Optimized %s: Raised priority to %d\n", processes[i].name, processes[i].priority);
        }
    }
}

void load_processes() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }

    FILE *proc_file = fopen("/proc/stat", "r");
    if (!proc_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), proc_file) && process_count < MAX_PROCESSES) {
        if (strstr(line, "cpu") != NULL) continue; 

        int pid;
        char name[256];
        unsigned long memory;
        sscanf(line, "%d %s %lu", &pid, name, &memory);
        processes[process_count].pid = pid;
        strncpy(processes[process_count].name, name, sizeof(name));
        processes[process_count].memory = memory;
        processes[process_count].priority = 0; // Default priority
        process_count++;
    }
    fclose(proc_file);
}

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nProgram terminated by user. Exiting...\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);

    printf("System Boot Optimizer\n");
    printf("======================\n\n");

    load_processes();
    display_processes();
    
    printf("Optimizing processes...\n");
    optimize_processes();
    
    display_processes();

    return 0;
}