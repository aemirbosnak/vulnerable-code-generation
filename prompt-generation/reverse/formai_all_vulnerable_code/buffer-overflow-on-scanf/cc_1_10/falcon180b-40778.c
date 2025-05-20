//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 50
#define MAX_COMMAND_LENGTH 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    char process_name[MAX_PROCESS_NAME_LENGTH];
    int status;
} Process;

void print_processes(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d | %s | %s | %d\n", processes[i].pid, processes[i].command, processes[i].process_name, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int status;
    int max_processes_reached = 0;

    while (1) {
        printf("\nEnter command to run or type 'q' to quit: ");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "q") == 0) {
            break;
        }

        pid_t child_pid = fork();

        if (child_pid == -1) {
            printf("Error forking process\n");
            continue;
        } else if (child_pid == 0) {
            if (num_processes >= MAX_PROCESSES - 1) {
                printf("Maximum number of processes reached\n");
                exit(1);
            }

            strcpy(processes[num_processes].command, command);
            processes[num_processes].pid = getpid();
            strcpy(processes[num_processes].process_name, "Running...");
            processes[num_processes].status = 0;
            num_processes++;

            execlp("bash", "bash", "-c", command, NULL);

            perror("execlp");
            exit(1);
        } else {
            int wait_status;
            waitpid(child_pid, &wait_status, WUNTRACED);

            for (int i = 0; i < num_processes; i++) {
                if (processes[i].pid == child_pid) {
                    processes[i].status = wait_status;
                    break;
                }
            }
        }
    }

    print_processes(processes, num_processes);

    return 0;
}