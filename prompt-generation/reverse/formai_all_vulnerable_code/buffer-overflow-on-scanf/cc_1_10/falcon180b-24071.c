//Falcon-180B DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int file_desc;
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter file name: ");
    scanf("%s", buffer);

    file_desc = open(buffer, O_RDWR);
    if (file_desc == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    while (1) {
        printf("Enter command: read, write, close\n");
        scanf("%s", buffer);

        if (strcmp(buffer, "read") == 0) {
            int bytes_read;
            bytes_read = read(file_desc, buffer, MAX_BUFFER_SIZE);
            if (bytes_read == -1) {
                printf("Error reading file\n");
                exit(1);
            }
            printf("File content:\n%s\n", buffer);
        } else if (strcmp(buffer, "write") == 0) {
            printf("Enter data to write: ");
            scanf("%s", buffer);
            int bytes_written;
            bytes_written = write(file_desc, buffer, strlen(buffer));
            if (bytes_written == -1) {
                printf("Error writing file\n");
                exit(1);
            }
        } else if (strcmp(buffer, "close") == 0) {
            close(file_desc);
            printf("File closed\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}