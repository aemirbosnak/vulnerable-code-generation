//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 1024

struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
};

void execute_command(char* command) {
    pid_t pid = fork();

    if (pid == 0) {
        execlp(command, command, NULL);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        fprintf(stderr, "Error forking process\n");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }
}

int main() {
    srand(time(NULL));

    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Enter number of processes to run (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter command for process %d: ", i+1);
        scanf("%s", processes[i].command);
    }

    for (int i = 0; i < num_processes; i++) {
        execute_command(processes[i].command);
    }

    return 0;
}