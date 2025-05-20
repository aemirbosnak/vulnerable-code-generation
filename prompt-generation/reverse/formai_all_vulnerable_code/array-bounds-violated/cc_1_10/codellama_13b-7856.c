//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100

int main(int argc, char *argv[]) {
    int pid, status;
    int num_processes = 0;
    char cmd[MAX_PROCESSES][256];

    while (1) {
        // Get the next command from the user
        printf("> ");
        fgets(cmd[num_processes], sizeof(cmd[num_processes]), stdin);

        // Remove the trailing newline character
        cmd[num_processes][strlen(cmd[num_processes]) - 1] = '\0';

        // If the command is "quit", exit the program
        if (strcmp(cmd[num_processes], "quit") == 0) {
            break;
        }

        // Fork the process
        pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process: execute the command
            execlp(cmd[num_processes], cmd[num_processes], NULL);
            perror("execlp failed");
            exit(1);
        } else {
            // Parent process: wait for the child process to exit
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child process %d exited with status %d\n", pid, WEXITSTATUS(status));
            } else {
                printf("Child process %d terminated abnormally\n", pid);
            }
        }

        // Increment the number of processes
        num_processes++;
    }

    return 0;
}