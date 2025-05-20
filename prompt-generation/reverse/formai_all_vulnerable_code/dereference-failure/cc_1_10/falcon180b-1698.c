//Falcon-180B DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 80

typedef struct {
    pid_t pid;
    int status;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void add_process(pid_t pid) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached\n");
        return;
    }

    processes[num_processes].pid = pid;
    processes[num_processes].status = 0;
    num_processes++;
}

void remove_process(pid_t pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            return;
        }
    }
}

void list_processes() {
    int i;

    printf("Processes:\n");
    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            printf("%d\n", processes[i].pid);
        }
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        char *token = strtok(command, " ");

        if (strcmp(token, "list") == 0) {
            list_processes();
        } else if (strcmp(token, "add") == 0) {
            int pid;
            sscanf(command, "%s %d", token, &pid);
            add_process(pid);
        } else if (strcmp(token, "remove") == 0) {
            int pid;
            sscanf(command, "%s %d", token, &pid);
            remove_process(pid);
        } else if (strcmp(token, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}