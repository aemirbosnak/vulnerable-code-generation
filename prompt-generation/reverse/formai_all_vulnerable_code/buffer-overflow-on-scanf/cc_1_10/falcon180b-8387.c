//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10
#define MAX_COMMANDS 100

typedef struct {
    char command[MAX_COMMANDS];
    int pid;
} process;

void execute(process *p) {
    int status;
    if (fork() == 0) {
        execlp(p->command, p->command, NULL);
        exit(1);
    } else {
        waitpid(p->pid, &status, WUNTRACED);
    }
}

void signal_handler(int signal) {
    int status;
    waitpid(-1, &status, WNOHANG);
}

int main() {
    int i, j, n, status;
    process processes[MAX_PROCESSES];

    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = -1;
    }

    while (1) {
        printf("Enter command: ");
        scanf("%s", processes[0].command);

        if (strcmp(processes[0].command, "exit") == 0) {
            break;
        }

        n = 1;
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].pid == -1) {
                break;
            }
        }

        if (i == MAX_PROCESSES) {
            printf("No more processes available.\n");
            continue;
        }

        processes[i].pid = fork();

        if (processes[i].pid == 0) {
            execute(&processes[i]);
            exit(0);
        } else if (processes[i].pid == -1) {
            printf("Fork failed.\n");
        } else {
            printf("Process %d started.\n", processes[i].pid);
        }
    }

    return 0;
}