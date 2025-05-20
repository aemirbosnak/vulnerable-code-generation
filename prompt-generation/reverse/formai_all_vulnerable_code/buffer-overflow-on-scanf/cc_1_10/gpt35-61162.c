//FormAI DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int main() {
    /* Retro-style interprocess communication example */
    
    printf("WELCOME TO RETRO IPC EXAMPLE!\n");
    printf("Type 'exit' to exit the program.\n");

    while (1) { // infinite loop until user types 'exit'
        char input[256];

        printf("Enter a message: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) { // exit condition
            printf("Exiting program...\n");
            break;
        }

        pid_t pid;
        int pipefd[2];
        int result = pipe(pipefd); // create a pipe for interprocess communication

        if (result == -1) { // error handling
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        pid = fork(); // create a child process

        if (pid == -1) { // error handling
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // child process
            close(pipefd[0]); // close the read end of the pipe

            char output[256];
            strcat(output, "Child process output: ");
            strcat(output, input);

            write(pipefd[1], output, strlen(output) + 1); // write to the write end of the pipe
            close(pipefd[1]); // close the write end of the pipe
            exit(EXIT_SUCCESS);
        } else { // parent process
            close(pipefd[1]); // close the write end of the pipe

            char input_received[256];
            read(pipefd[0], input_received, sizeof(input_received)); // read from the read end of the pipe

            printf("%s\n", input_received);
            close(pipefd[0]); // close the read end of the pipe

            int status;
            pid_t result = waitpid(pid, &status, 0); // wait for child process to finish

            if (result == -1) { // error handling
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0;
}