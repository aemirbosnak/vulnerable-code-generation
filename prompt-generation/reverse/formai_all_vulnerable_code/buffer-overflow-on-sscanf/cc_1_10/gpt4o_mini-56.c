//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 128

typedef struct {
    int pid;
    char name[256];
    long memory;
} Process;

void display_usage(Process processes[], int count);
void sort_processes_by_memory(Process processes[], int count);
void get_process_memory(Process processes[], int *count);
void print_memory_usage(float total_memory, float used_memory);

int main() {
    Process processes[MAX_PROCESSES];
    int process_count = 0;

    while (1) {
        get_process_memory(processes, &process_count);
        sort_processes_by_memory(processes, process_count);
        display_usage(processes, process_count);

        sleep(5);  // refresh every 5 seconds
        system("clear");  // clear the console for fresh output
    }
    return 0;
}

void get_process_memory(Process processes[], int *count) {
    FILE *fp;
    char path[256];
    char line[256];
    int pid = 0;
    long memory = 0;

    *count = 0;
    fp = popen("ps -eo pid,comm,%mem --sort=-%mem", "r");
    if (fp == NULL) {
        perror("popen failed");
        exit(1);
    }

    // Skip the first line (header)
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d %s %ld", &pid, processes[*count].name, &memory);
        processes[*count].pid = pid;
        processes[*count].memory = memory;
        (*count)++;
    }

    pclose(fp);
}

void sort_processes_by_memory(Process processes[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (processes[i].memory < processes[j].memory) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void display_usage(Process processes[], int count) {
    float total_memory = 0.0;
    float used_memory = 0.0;

    printf("PID\tName\t\tMemory(%%)\n");
    printf("---------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strlen(processes[i].name) > 15) {
            printf("%d\t%.15s\t%ld%%\n", processes[i].pid, processes[i].name, processes[i].memory);
        } else {
            printf("%d\t%s\t\t%ld%%\n", processes[i].pid, processes[i].name, processes[i].memory);
        }
        used_memory += processes[i].memory;
    }
    total_memory = 100.0;  // assumed cap for example
    print_memory_usage(total_memory, used_memory);
}

void print_memory_usage(float total_memory, float used_memory) {
    printf("\nTotal Memory Usage: %.2f%% of %.2f%%\n", used_memory, total_memory);
    printf("---------------------------------\n");
}