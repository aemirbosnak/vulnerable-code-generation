//Falcon-180B DATASET v1.0 Category: Error handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
void error_handling(char *message);
int open_file(char *filename, int mode);
int close_file(int fd);
int read_file(int fd, char *buffer, int size);
int write_file(int fd, char *buffer, int size);

int main()
{
    int fd;
    char filename[100];
    char buffer[MAX_LINE_LENGTH];

    // Get filename from user input
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fd = open_file(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // Read file contents
    while (read_file(fd, buffer, MAX_LINE_LENGTH) > 0)
    {
        printf("%s", buffer);
    }

    // Close file
    if (close_file(fd) == -1)
    {
        printf("Error closing file: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}

// Error handling function
void error_handling(char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Open file function
int open_file(char *filename, int mode)
{
    int fd;

    fd = open(filename, mode);
    if (fd == -1)
    {
        error_handling("Error opening file");
    }

    return fd;
}

// Close file function
int close_file(int fd)
{
    int result;

    result = close(fd);
    if (result == -1)
    {
        error_handling("Error closing file");
    }

    return result;
}

// Read file function
int read_file(int fd, char *buffer, int size)
{
    int result;

    result = read(fd, buffer, size);
    if (result == -1)
    {
        error_handling("Error reading file");
    }

    return result;
}

// Write file function
int write_file(int fd, char *buffer, int size)
{
    int result;

    result = write(fd, buffer, size);
    if (result == -1)
    {
        error_handling("Error writing file");
    }

    return result;
}