//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 256

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

int add_process(char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return -1;
    }

    process_t* new_process = &processes[num_processes];
    strcpy(new_process->command, command);
    new_process->pid = fork();

    if (new_process->pid == -1) {
        printf("Error: Fork failed.\n");
        return -1;
    } else if (new_process->pid == 0) {
        execlp(command, command, NULL);
        printf("Error: Exec failed.\n");
        exit(1);
    }

    num_processes++;
    return 0;
}

int remove_process(int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            waitpid(pid, NULL, 0);
            num_processes--;
            memmove(&processes[i], &processes[i+1], sizeof(process_t) * (num_processes - i - 1));
            return 0;
        }
    }

    printf("Error: Process not found.\n");
    return -1;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char command[MAX_COMMAND_LENGTH];
            printf("Enter command to add: ");
            scanf("%s", command);
            add_process(command);
        } else if (strcmp(input, "remove") == 0) {
            int pid;
            printf("Enter PID to remove: ");
            scanf("%d", &pid);
            remove_process(pid);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}