//Falcon-180B DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char filename[100];
    char buffer[BUFFER_SIZE];
    int fd;
    int read_bytes;
    int write_bytes;
    int append_mode = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Enter text: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    write_bytes = write(fd, buffer, strlen(buffer));
    if (write_bytes == -1) {
        printf("Error writing to file\n");
        exit(1);
    }

    printf("Do you want to append to the file? (y/n): ");
    scanf("%s", filename);

    if (strcmp(filename, "y") == 0) {
        append_mode = 1;
    }

    lseek(fd, 0, SEEK_SET);
    read_bytes = read(fd, buffer, BUFFER_SIZE);
    if (read_bytes == -1) {
        printf("Error reading from file\n");
        exit(1);
    }

    printf("File contents:\n%s", buffer);

    if (append_mode) {
        printf("Enter text to append: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        write_bytes = write(fd, buffer, strlen(buffer));
        if (write_bytes == -1) {
            printf("Error writing to file\n");
            exit(1);
        }
    }

    close(fd);

    return 0;
}