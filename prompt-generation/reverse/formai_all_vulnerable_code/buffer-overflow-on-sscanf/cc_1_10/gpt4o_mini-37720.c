//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    long resident_set_size;
} ProcessInfo;

void clear_screen() {
    // Here we define a function to clear the screen using ANSI escape codes
    printf("\033[H\033[J");
}

void display_memory_usage(ProcessInfo processes[], int count) {
    clear_screen();
    printf("====================================\n");
    printf("    RAM Usage Monitor\n");
    printf("====================================\n");
    printf("PID\tName\t\t\tRSS (KB)\n");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s\t%ld\n", processes[i].pid, processes[i].name, processes[i].resident_set_size);
    }
    printf("====================================\n");
}

void fetch_process_info(ProcessInfo processes[], int* count) {
    FILE* file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Could not open /proc/meminfo");
        return;
    }
    
    // Initialize count
    *count = 0;

    char line[BUFFER_SIZE];
    // Read memory info and fill processes array
    while (fgets(line, sizeof(line), file) && *count < MAX_PROCESSES) {
        if (line[0] == '\0' || line[0] == '\n') continue; 

        // Add process details to the info structure by splitting
        sscanf(line, "VmSize: %ld", &processes[*count].resident_set_size);
        sscanf(line, "%*s %d", &processes[*count].pid);
        // Generate a dummy process name for now
        snprintf(processes[*count].name, sizeof(processes[*count].name), "Process_%d", processes[*count].pid);
        
        (*count)++;
    }
    fclose(file);
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int count;

    while (1) {
        fetch_process_info(processes, &count);
        display_memory_usage(processes, count);
        sleep(2); // Sleep for 2 seconds before refreshing the info
    }

    return 0;
}