//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command to run or type 'q' to quit:\n");
        char command[MAX_COMMAND_LENGTH];
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "q") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            continue;
        } else if (pid == 0) {
            processes[num_processes].pid = getpid();
            strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';
            num_processes++;

            execlp(command, command, NULL);
            perror("execlp");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);

            processes[num_processes - 1].status = status;
        }
    }

    print_processes(processes, num_processes);

    return 0;
}