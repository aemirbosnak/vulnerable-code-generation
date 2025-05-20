//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10
#define SLEEP_TIME 2

typedef struct {
    pid_t pid; // Process ID
    int cpu_usage; // CPU usage of the process (in percentage)
} Process;

int get_cpu_usage(pid_t pid) {
    char command[256];
    snprintf(command, sizeof(command), "ps -p %d -o %%cpu | awk 'NF>1{print $NF}'", pid);

    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return -1;
    }

    char buf[128];
    if (fgets(buf, sizeof(buf), fp) == NULL) {
        perror("fgets");
        pclose(fp);
        return -1;
    }

    pclose(fp);
    return atoi(buf);
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Press Ctrl+C to exit\n\n");

    while (1) {
        pid_t pid;

        printf("Enter process ID (0 to stop): ");
        scanf("%d", &pid);

        if (pid == 0) {
            break;
        }

        // Check if the process is already being monitored
        int found = 0;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == pid) {
                printf("Process already being monitored\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            // Add process to the list
            if (num_processes >= MAX_PROCESSES) {
                printf("Maximum number of processes reached\n");
            } else {
                processes[num_processes].pid = pid;
                processes[num_processes].cpu_usage = 0;
                num_processes++;
                printf("Process added to the list\n");
            }
        }
    }

    while (1) {
        system("clear");
        printf("CPU Usage Monitor\n\n");

        // Update CPU usage for each process
        for (int i = 0; i < num_processes; i++) {
            processes[i].cpu_usage = get_cpu_usage(processes[i].pid);
            if (processes[i].cpu_usage == -1) {
                printf("Failed to get CPU usage for process %d\n", processes[i].pid);
            }
        }

        // Print CPU usage for each process
        printf("%-10s %-20s\n", "PID", "CPU Usage");
        for (int i = 0; i < num_processes; i++) {
            printf("%-10d %-20d%%\n", processes[i].pid, processes[i].cpu_usage);
        }

        sleep(SLEEP_TIME);
    }

    return 0;
}