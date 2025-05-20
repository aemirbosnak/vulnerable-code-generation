//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int status;
};

void print_processes(struct process processes[], int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command: ");
        char command[100];
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            print_processes(processes, num_processes);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            int pid = fork();

            if (pid == -1) {
                printf("Error forking process\n");
            } else if (pid == 0) {
                execlp(command, command, NULL);
                exit(1);
            } else {
                int status;
                waitpid(pid, &status, 0);

                processes[num_processes].pid = pid;
                processes[num_processes].status = status;

                strcpy(processes[num_processes].name, command);
                num_processes++;
            }
        }
    }

    return 0;
}