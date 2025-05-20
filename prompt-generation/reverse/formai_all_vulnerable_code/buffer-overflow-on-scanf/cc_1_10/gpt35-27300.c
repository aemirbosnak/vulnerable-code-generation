//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

// Signal handler
void sig_handler(int sig) {
    printf("Child process terminated with signal %d\n", sig);
}

// Main program
int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Error: fork() failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process started with PID %d\n", getpid());

        // Set signal handler for child process
        if (signal(SIGTERM, sig_handler) == SIG_ERR) {
           printf("Error: Unable to set signal handler for child process\n");
           return 1;
        }

        // Loop indefinitely
        while (1) {
            printf("Child process executing...\n");
            sleep(2);
        }
    } else {
        // Parent process
        printf("Parent process started with PID %d\n", getpid());

        // Set signal handler for parent process
        if (signal(SIGTERM, sig_handler) == SIG_ERR) {
            printf("Error: Unable to set signal handler for parent process\n");
            return 1;
        }

        // Wait for user input to terminate child process
        char input[10];
        printf("Press any key to terminate child process...\n");
        scanf("%s", input);

        // Kill child process
        int status = kill(pid, SIGTERM);
        if (status == 0) {
            printf("Child process terminated successfully\n");
        } else {
            printf("Error: Unable to terminate child process\n");
        }
    }
    return 0;
}