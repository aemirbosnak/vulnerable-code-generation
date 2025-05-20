//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        printf("Enter the PID of a process to monitor (or 0 to finish): ");
        int pid;
        scanf("%d", &pid);

        if (pid == 0) {
            break;
        }

        char command[MAX_COMMAND_LENGTH];
        sprintf(command, "ps -p %d -o command=", pid);

        FILE *fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error: Failed to execute command\n");
            continue;
        }

        fgets(command, MAX_COMMAND_LENGTH, fp);
        pclose(fp);

        command[strcspn(command, "\n")] = '\0';

        process_t *process = &processes[num_processes];
        process->pid = pid;
        strcpy(process->command, command);

        num_processes++;
    }

    printf("\n");

    for (int i = 0; i < num_processes; i++) {
        process_t *process = &processes[i];
        printf("%d: %s\n", process->pid, process->command);
    }

    return 0;
}