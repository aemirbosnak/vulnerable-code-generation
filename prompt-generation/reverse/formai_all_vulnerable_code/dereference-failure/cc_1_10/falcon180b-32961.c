//Falcon-180B DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [file] [operation] [param]\n", argv[0]);
        return 1;
    }

    char *file = argv[1];
    char *operation = argv[2];
    char *param = argv[3];

    int fd;
    if ((fd = open(file, O_RDWR)) < 0) {
        printf("Error opening file\n");
        return 1;
    }

    if (strcmp(operation, "read") == 0) {
        char buffer[BUF_SIZE];
        int bytes_read = read(fd, buffer, BUF_SIZE);
        if (bytes_read < 0) {
            printf("Error reading file\n");
            return 1;
        }

        printf("File contents:\n%s", buffer);
    } else if (strcmp(operation, "write") == 0) {
        if (param == NULL) {
            printf("Error: no data provided for writing\n");
            return 1;
        }

        int bytes_written = write(fd, param, strlen(param));
        if (bytes_written < 0) {
            printf("Error writing file\n");
            return 1;
        }

        printf("Data written to file\n");
    } else {
        printf("Invalid operation\n");
        return 1;
    }

    close(fd);
    return 0;
}