//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESS_NUM 100
#define MAX_COMMAND_LEN 1024

typedef struct {
    char command[MAX_COMMAND_LEN];
    pid_t pid;
    int status;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tCOMMAND\tSTATUS\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESS_NUM];
    int num_processes = 0;

    while (1) {
        printf("Enter a command to run or type 'q' to quit: ");
        char command[MAX_COMMAND_LEN];
        fgets(command, MAX_COMMAND_LEN, stdin);

        if (strcmp(command, "q") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == -1) {
            printf("Error forking process\n");
            continue;
        } else if (pid == 0) {
            processes[num_processes].pid = getpid();
            strcpy(processes[num_processes].command, command);
            num_processes++;

            execlp("sh", "sh", "-c", command, NULL);
            printf("Error executing command\n");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);

            processes[num_processes - 1].status = status;
            num_processes--;
        }
    }

    print_processes(processes, num_processes);

    return 0;
}