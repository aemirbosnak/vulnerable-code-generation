//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    char name[20];
    int status;
};

void show_processes(struct process *processes, int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    char command[100];
    char *argv[3];
    int num_processes = 0;
    struct process processes[MAX_PROCESSES];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            show_processes(processes, num_processes);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            argv[0] = strtok(command, " ");
            argv[1] = strtok(NULL, " ");
            argv[2] = NULL;

            int pid = fork();

            if (pid == 0) {
                if (execvp(argv[0], argv) == -1) {
                    perror("execvp");
                }
            } else {
                int status;
                waitpid(pid, &status, 0);

                struct process *process = &processes[num_processes];
                process->pid = pid;
                strncpy(process->name, argv[0], 20);
                process->status = status;
                num_processes++;
            }
        }
    }

    return 0;
}