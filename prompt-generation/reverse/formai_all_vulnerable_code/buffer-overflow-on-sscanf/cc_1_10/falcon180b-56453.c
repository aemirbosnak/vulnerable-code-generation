//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
    int exit_status;
} process_t;

void add_process(process_t *processes, int num_processes, char *command) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == 0) {
            strncpy(processes[i].command, command, MAX_COMMAND_LENGTH);
            processes[i].pid = fork();
            if (processes[i].pid == 0) {
                execlp(command, command, NULL);
                exit(1);
            } else if (processes[i].pid < 0) {
                perror("fork");
                exit(1);
            }
            break;
        }
    }
}

void remove_process(process_t *processes, int num_processes, int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            waitpid(pid, &processes[i].status, WNOHANG);
            processes[i].pid = 0;
            break;
        }
    }
}

void list_processes(process_t *processes, int num_processes) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid!= 0) {
            printf("%d: %s\n", processes[i].pid, processes[i].command);
        }
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command to add or type 'list' to list processes or'remove' followed by PID to remove process: ");
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(command, "list") == 0) {
            list_processes(processes, num_processes);
        } else if (strcmp(command, "remove") == 0) {
            int pid;
            sscanf(command, "remove %d", &pid);
            remove_process(processes, num_processes, pid);
        } else {
            add_process(processes, num_processes, command);
        }
    }

    return 0;
}