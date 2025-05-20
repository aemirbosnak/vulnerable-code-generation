//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 256

// Structure for storing the message header
typedef struct {
    int message_id;
    int message_length;
} MessageHeader;

int main() {
    int fd1, fd2;
    char buffer[BUFFER_SIZE];
    MessageHeader header;

    // Create two processes
    pid_t child1 = fork();
    pid_t child2 = fork();

    // Check if process creation was successful
    if (child1 == -1 || child2 == -1) {
        printf("Process creation failed\n");
        exit(1);
    }

    // Determine which process is the parent and which is the child
    if (child1 == 0) {
        // Child 1 is the sender
        fd1 = open("message.txt", O_RDONLY);
        fd2 = open("pipe1", O_WRONLY);

        // Read the message from the file
        char message[BUFFER_SIZE];
        int message_length = read(fd1, message, BUFFER_SIZE);

        // Send the message to the receiver
        header.message_id = 1;
        header.message_length = message_length;
        write(fd2, &header, sizeof(header));
        write(fd2, message, message_length);

        // Close the file descriptors
        close(fd1);
        close(fd2);
        exit(0);
    }
    else if (child2 == 0) {
        // Child 2 is the receiver
        fd1 = open("pipe1", O_RDONLY);
        fd2 = open("message.txt", O_WRONLY | O_CREAT | O_TRUNC);

        // Receive the message from the sender
        read(fd1, &header, sizeof(header));
        read(fd1, buffer, header.message_length);

        // Write the message to the file
        write(fd2, buffer, header.message_length);

        // Close the file descriptors
        close(fd1);
        close(fd2);
        exit(0);
    }
    else {
        // Parent process waits for both children to finish
        wait(NULL);
        wait(NULL);
    }

    return 0;
}