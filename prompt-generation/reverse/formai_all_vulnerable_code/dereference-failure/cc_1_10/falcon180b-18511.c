//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d - %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    char input_buffer[MAX_COMMAND_LENGTH];
    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strncmp(input_buffer, "list", 4) == 0) {
            print_processes(processes, num_processes);
        } else if (strncmp(input_buffer, "kill", 4) == 0) {
            char* pid_str = strtok(input_buffer, " ");
            int pid = atoi(pid_str);

            for (int i = 0; i < num_processes; i++) {
                if (processes[i].pid == pid) {
                    kill(pid, SIGKILL);
                    processes[i].pid = 0;
                    num_processes--;
                    break;
                }
            }
        } else {
            char* command_str = strtok(input_buffer, " ");
            strcpy(processes[num_processes].command, command_str);

            int pid = fork();

            if (pid == 0) {
                execlp(command_str, command_str, NULL);
                exit(1);
            } else {
                processes[num_processes].pid = pid;
                num_processes++;
            }
        }
    }

    return 0;
}