//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_NAME_LENGTH 256
#define MAX_FILE_SIZE 100000

// Function to read a file line by line
void readFile(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        // Process the buffer contents
        printf("%s", buffer);
    }

    close(fd);
}

// Function to write a file line by line
void writeFile(const char *filename) {
    int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    char buffer[4096];
    size_t bytes_written;

    while (1) {
        printf("Enter a line: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == '\n') {
            break;
        }

        bytes_written = write(fd, buffer, strlen(buffer));
        if (bytes_written == -1) {
            perror("Error writing to file");
            break;
        }
    }

    close(fd);
}

int main() {
    // Example usage of readFile and writeFile
    char filename[MAX_NAME_LENGTH];
    printf("Enter a file name: ");
    scanf("%s", filename);

    readFile(filename);

    printf("Enter some lines to write to a new file: ");
    writeFile(filename);

    return 0;
}