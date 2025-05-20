//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char name[256];
    int memory_usage; // Memory usage in KB
} ProcessInfo;

void clear_screen() {
    printf("\033[H\033[J");
}

void print_title() {
    printf("=======================================\n");
    printf("         RAM Usage Monitor            \n");
    printf("=======================================\n");
}

void print_processes(ProcessInfo *processes, int count) {
    printf("%-10s %-30s %-15s\n", "PID", "Process Name", "Memory Usage (KB)");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-15d\n", processes[i].pid, processes[i].name, processes[i].memory_usage);
    }
}

void gather_memory_usage(ProcessInfo *processes, int *count) {
    *count = 0;
    FILE *fp = popen("ps -eo pid,comm,rss --sort=-rss", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    char buffer[512];
    // Skip the header line
    fgets(buffer, sizeof(buffer), fp);

    while (fgets(buffer, sizeof(buffer), fp) != NULL && *count < MAX_PROCESSES) {
        sscanf(buffer, "%d %s %d", &processes[*count].pid, processes[*count].name, &processes[*count].memory_usage);
        (*count)++;
    }

    pclose(fp);
}

void display_memory_usage() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count;

    while (1) {
        clear_screen();
        print_title();
        gather_memory_usage(processes, &process_count);
        print_processes(processes, process_count);
        
        sleep(3); // Update every 3 seconds
    }
}

int main() {
    display_memory_usage();
    return 0;
}