//Falcon-180B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_file(int fd, char *filename) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
}

void write_file(int fd, char *filename) {
    char buffer[BUFFER_SIZE];
    int bytes_written;

    printf("Enter text to write to file: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcat(buffer, "\n");

    while ((bytes_written = write(fd, buffer, strlen(buffer))) > 0) {
        buffer[bytes_written] = '\0';
    }
}

int main() {
    int fd, bytes_read, bytes_written;
    char filename[100], buffer[BUFFER_SIZE];

    printf("Enter filename: ");
    scanf("%s", filename);

    fd = open(filename, O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter text to write to file: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcat(buffer, "\n");

    while ((bytes_written = write(fd, buffer, strlen(buffer))) > 0) {
        buffer[bytes_written] = '\0';
    }

    printf("Text written to file.\n");

    read_file(fd, filename);

    close(fd);

    return 0;
}