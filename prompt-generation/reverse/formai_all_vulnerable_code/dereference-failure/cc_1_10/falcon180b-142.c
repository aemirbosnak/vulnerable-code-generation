//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LEN 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LEN];
} PROCESS;

PROCESS processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(pid_t pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Process table is full.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LEN);
    num_processes++;
}

void remove_process(pid_t pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i+1], sizeof(PROCESS) * (num_processes - i - 1));
            num_processes--;
            return;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    int status;
    char input[MAX_COMMAND_LEN];

    while (1) {
        printf("\nEnter command (list, kill <PID>, exit): ");
        fgets(input, MAX_COMMAND_LEN, stdin);

        char* command = strtok(input, " ");
        if (command == NULL) {
            continue;
        }

        if (strcmp(command, "list") == 0) {
            print_processes();
        } else if (strcmp(command, "kill") == 0) {
            char* pid_str = strtok(NULL, " ");
            pid_t pid = atoi(pid_str);

            remove_process(pid);
            kill(pid, SIGKILL);
            printf("Process %d killed.\n", pid);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}