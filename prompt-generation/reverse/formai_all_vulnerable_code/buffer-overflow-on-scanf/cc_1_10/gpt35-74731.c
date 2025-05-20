//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    printf("Welcome to the Grateful System Administration Program!\n");
    printf("This program allows you to manage your system files.\n");

    char filename[100];
    printf("Enter the name of the file you wish to create: ");
    scanf("%s", filename);

    int fd = creat(filename, 0644); // create file with read-write permissions
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    printf("File created successfully!\n");

    char buffer[100];
    printf("Enter the content you wish to write to the file: ");
    scanf("%s", buffer);

    int bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written == -1) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    printf("%d bytes written to file!\n", bytes_written);

    off_t file_size = lseek(fd, 0, SEEK_END); // get file size
    if (file_size == -1) {
        perror("Error getting file size");
        exit(EXIT_FAILURE);
    }

    printf("File size: %ld bytes\n", file_size);

    int close_status = close(fd); // close file
    if (close_status == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("File closed successfully!\n");

    return 0;
}