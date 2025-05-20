//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <mode> <filename>\n", argv[0]);
        return -1;
    }

    int mode = atoi(argv[1]);
    char *filename = argv[2];

    int fd = open(filename, mode | O_RDWR);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return -1;
    }

    char *buffer = malloc(MAX_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return -1;
    }

    switch (mode) {
        case 0: // Read mode
            while (1) {
                int bytes_read = read(fd, buffer, MAX_SIZE);
                if (bytes_read == 0) {
                    printf("End of file reached\n");
                    break;
                } else if (bytes_read == -1) {
                    printf("Error reading file: %s\n", strerror(errno));
                    return -1;
                }
                buffer[bytes_read] = '\0'; // Add null terminator
                printf("Read from file: %s\n", buffer);
            }
            break;
        case 1: // Write mode
            while (1) {
                printf("Enter text to write: ");
                fgets(buffer, MAX_SIZE, stdin);
                int bytes_written = write(fd, buffer, strlen(buffer));
                if (bytes_written == -1) {
                    printf("Error writing file: %s\n", strerror(errno));
                    return -1;
                }
            }
            break;
        case 2: // Append mode
            while (1) {
                printf("Enter text to append: ");
                fgets(buffer, MAX_SIZE, stdin);
                int bytes_written = write(fd, buffer, strlen(buffer));
                if (bytes_written == -1) {
                    printf("Error writing file: %s\n", strerror(errno));
                    return -1;
                }
            }
            break;
        default:
            printf("Invalid mode\n");
            return -1;
    }

    free(buffer);
    close(fd);

    return 0;
}