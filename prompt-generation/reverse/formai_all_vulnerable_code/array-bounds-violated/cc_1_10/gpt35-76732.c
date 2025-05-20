//FormAI DATASET v1.0 Category: System administration ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    // Ensure that the program is being run as root
    if (getuid() != 0) {
        printf("You must run this program as root!\n");
        exit(EXIT_FAILURE);
    }

    // Open a file with read/write permissions for the root user
    int file_descriptor = open("/var/log/messages", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    // Check if the file descriptor was successfully opened
    if (file_descriptor == -1) {
        printf("Could not open file!\n");
        exit(EXIT_FAILURE);
    }

    // Write a message to the file
    char* message = "This message was written by a system administrator.\n";
    ssize_t bytes_written = write(file_descriptor, message, strlen(message));

    // Check if the message was successfully written
    if (bytes_written == -1) {
        printf("Could not write message to file!\n");
        exit(EXIT_FAILURE);
    }

    // Seek to the beginning of the file
    off_t offset = lseek(file_descriptor, 0, SEEK_SET);

    // Check if the seeking operation was successful
    if (offset == -1) {
        printf("Could not seek to beginning of file!\n");
        exit(EXIT_FAILURE);
    }

    // Read the message from the file and print it to the console
    char buffer[1024];
    ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer));

    // Check if the message was successfully read
    if (bytes_read == -1) {
        printf("Could not read message from file!\n");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer to ensure it can be printed correctly
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Close the file descriptor
    close(file_descriptor);

    // Exit with success
    exit(EXIT_SUCCESS);
}