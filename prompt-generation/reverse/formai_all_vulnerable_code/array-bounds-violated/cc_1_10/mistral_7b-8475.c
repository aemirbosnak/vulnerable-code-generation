//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PIPE_NAME "oh_my_gosh_pipe"

void parent(void) {
    int fd[2]; // An array of two file descriptors
    char message[100]; // A char array to hold the message
    pid_t child_pid; // A process ID to hold the child process ID

    if (pipe(fd) == -1) { // Attempting to create a pipe, oh no!
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    child_pid = fork(); // Creating a child process, what could go wrong?

    if (child_pid < 0) { // If the fork fails, we're in trouble!
        perror("fork");
        close(fd[0]); // Close the read end of the pipe in the parent process
        close(fd[1]); // Close the write end of the pipe in the parent process
        exit(EXIT_FAILURE);
    } else if (child_pid > 0) { // If the fork was successful, we're the parent process
        close(fd[0]); // Close the read end of the pipe in the parent process

        // Write a message to the pipe, be careful not to overflow it!
        strcpy(message, "This is a message from the parent process!");
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]); // Close the write end of the pipe in the parent process

        printf("Parent process wrote message to pipe and exited!\n");
        exit(EXIT_SUCCESS);
    } else { // If the fork was successful, we're the child process
        close(fd[1]); // Close the write end of the pipe in the child process

        // Read the message from the pipe, be careful not to read past the end!
        ssize_t bytes_read;
        char received_message[101];
        bytes_read = read(fd[0], received_message, sizeof(received_message));
        if (bytes_read <= 0) { // If there's an error or the pipe is empty, something's wrong!
            perror("read");
            exit(EXIT_FAILURE);
        }
        received_message[bytes_read] = '\0'; // Null-terminate the received message

        // Print the received message and exit, but not before making a dramatic announcement!
        printf("Child process received message: %s\n", received_message);
        exit(EXIT_SUCCESS);
    }
}

int main(void) {
    printf("In a shocking turn of events, the parent process is about to call the parent function!\n");
    parent();
    printf("Parent process exited, but the story doesn't end here!\n");
    return EXIT_SUCCESS;
}