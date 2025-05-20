//FormAI DATASET v1.0 Category: Interprocess communication ; Style: expert-level
// Filename: ipc_example.c
// Description: An expert-level Interprocess communication example program in C language.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd[2];
    pid_t pid;
    char message[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    // Create Pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create Child process
    pid = fork();

    if (pid == -1) { // Error occurred while forking
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // Child Process
        printf("Child process is running...\n");

        // Close unused write end of pipe
        close(fd[1]);

        // Read the message from parent process
        read(fd[0], read_buffer, sizeof(read_buffer));
        printf("Child process received message: %s", read_buffer);

        // Close read end of pipe
        close(fd[0]);

        printf("Child process is exiting...\n");
        exit(EXIT_SUCCESS);
    }
    else { // Parent Process
        printf("Parent process is running...\n");

        // Close unused read end of pipe
        close(fd[0]);

        printf("Enter the message to send to child process: ");
        scanf("%[^\n]", message);

        // Write message to pipe
        write(fd[1], message, sizeof(message));

        // Close write end of pipe
        close(fd[1]);

        printf("Waiting for child process to complete...\n");

        // Wait for child process to complete
        wait(NULL);

        printf("Parent process is exiting...\n");
        exit(EXIT_SUCCESS);
    }
    
    return 0;
}