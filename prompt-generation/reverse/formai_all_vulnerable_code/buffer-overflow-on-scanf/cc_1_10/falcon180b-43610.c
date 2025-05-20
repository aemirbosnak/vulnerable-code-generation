//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 1000
#define DELAY 1000

int main(int argc, char *argv[]) {
    int num_processes = 0;
    int child_pid[MAX_PROCESSES];
    int status;
    char command[MAX_COMMAND_LENGTH];

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    if (num_processes > MAX_PROCESSES) {
        printf("Error: Number of processes exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter the command to be executed: ");
    scanf("%s", command);

    for (int i = 0; i < num_processes; i++) {
        child_pid[i] = fork();

        if (child_pid[i] == 0) {
            execlp(command, command, NULL);
            exit(1);
        } else if (child_pid[i] < 0) {
            printf("Error: Fork failed.\n");
            return 1;
        } else {
            printf("Process %d started with PID %d.\n", i + 1, child_pid[i]);
        }

        usleep(DELAY);
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(child_pid[i], &status, 0);
        printf("Process %d ended with status %d.\n", i + 1, status);
    }

    return 0;
}