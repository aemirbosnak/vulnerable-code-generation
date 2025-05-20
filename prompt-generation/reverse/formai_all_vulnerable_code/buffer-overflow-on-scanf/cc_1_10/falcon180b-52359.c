//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>

#define MAX_PROCESSES 10
#define BUFFER_SIZE 1024

typedef struct {
    char name[20];
    int pid;
    int status;
} Process;

int main() {
    int numProcesses = 0;
    Process processes[MAX_PROCESSES];
    char input[BUFFER_SIZE];
    char *token;
    int i;

    printf("Enter the number of processes to monitor: ");
    scanf("%d", &numProcesses);

    printf("Enter the names of the processes to monitor (separated by spaces): ");
    fgets(input, BUFFER_SIZE, stdin);
    token = strtok(input, " ");

    for (i = 0; i < numProcesses && numProcesses < MAX_PROCESSES; i++) {
        strcpy(processes[i].name, token);
        processes[i].pid = -1;
        processes[i].status = 0;
        token = strtok(NULL, " ");
    }

    while (1) {
        printf("\n");
        for (i = 0; i < numProcesses; i++) {
            printf("%s: ", processes[i].name);

            if (processes[i].pid == -1) {
                printf("Not Running\n");
            } else {
                int status;
                waitpid(processes[i].pid, &status, WNOHANG);
                if (WIFEXITED(status)) {
                    printf("Exited with status %d\n", WEXITSTATUS(status));
                    processes[i].pid = -1;
                } else if (WIFSIGNALED(status)) {
                    printf("Killed by signal %d\n", WTERMSIG(status));
                    processes[i].pid = -1;
                } else {
                    printf("Running\n");
                }
            }
        }

        printf("\nPress any key to continue...\n");
        fgets(input, BUFFER_SIZE, stdin);
    }

    return 0;
}