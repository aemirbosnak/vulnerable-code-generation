//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char command[256];
    float cpu_usage;
} ProcessInfo;

void get_cpu_usage(ProcessInfo *processes, int *count) {
    FILE *fp;
    char line[256];
    *count = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fread(line, sizeof(char), sizeof(line), fp);
    fclose(fp);

    long long int user, nice, system, idle;
    sscanf(line, "cpu %lld %lld %lld %lld", &user, &nice, &system, &idle);
    long long int total = user + nice + system + idle;

    FILE *proc_fp;
    char path[256];
    for (int i = 0; i < MAX_PROCESSES; i++) {
        snprintf(path, sizeof(path), "/proc/%d/stat", i);
        proc_fp = fopen(path, "r");
        if (proc_fp != NULL) {
            fscanf(proc_fp, "%d %s", &processes[*count].pid, processes[*count].command);
            processes[*count].command[strcspn(processes[*count].command, "\n")] = 0; // Remove newline
            processes[*count].cpu_usage = (float)(rand() % 100) / 10.0; // Mock CPU usage
            (*count)++;
            fclose(proc_fp);
        }
    }

    // Sort processes based on CPU usage
    for (int i = 0; i < *count - 1; i++) {
        for (int j = i + 1; j < *count; j++) {
            if (processes[i].cpu_usage < processes[j].cpu_usage) {
                ProcessInfo temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void display_usage(ProcessInfo *processes, int count) {
    printf("%-10s %-30s %-10s\n", "PID", "COMMAND", "CPU USAGE");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count && i < 10; i++) { // Display only the top 10
        printf("%-10d %-30s %-10.2f\n", processes[i].pid, processes[i].command, processes[i].cpu_usage);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int count;

    while (1) {
        get_cpu_usage(processes, &count);
        printf("\nTop CPU usage processes:\n");
        display_usage(processes, count);
        sleep(2); // Refresh every 2 seconds
    }

    return 0;
}