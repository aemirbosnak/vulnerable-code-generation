//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process_info {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_info_t;

void print_process_info(process_info_t *process) {
    printf("PID: %d\n", process->pid);
    printf("Command: %s\n", process->command);
    printf("Status: %d\n", process->status);
    printf("\n");
}

int main() {
    int num_processes = 0;
    process_info_t processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        printf("Enter PID of process to monitor (or 0 to exit): ");
        int pid;
        scanf("%d", &pid);

        if (pid == 0) {
            break;
        }

        if (num_processes >= MAX_PROCESSES) {
            printf("Maximum number of processes reached.\n");
            continue;
        }

        char command[MAX_COMMAND_LENGTH];
        snprintf(command, MAX_COMMAND_LENGTH, "ps -p %d -o command=", pid);

        FILE *fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error: failed to execute command.\n");
            continue;
        }

        fgets(command, MAX_COMMAND_LENGTH, fp);
        pclose(fp);

        strtok(command, "\n");
        strcpy(processes[num_processes].command, command);
        processes[num_processes].pid = pid;
        processes[num_processes].status = -1;

        num_processes++;
    }

    while (1) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].status == -1) {
                processes[i].status = waitpid(processes[i].pid, NULL, WNOHANG);
            }
        }

        sleep(1);
    }

    return 0;
}