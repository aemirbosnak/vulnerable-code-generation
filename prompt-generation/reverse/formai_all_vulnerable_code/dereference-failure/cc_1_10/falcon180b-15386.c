//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define PATH "/tmp/myfifo"
#define SIZE 100

int main(int argc, char *argv[]) {
    int fd;
    char buffer[SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [read|write]\n", argv[0]);
        exit(1);
    }

    fd = open(PATH, O_RDWR);
    if (fd == -1) {
        fprintf(stderr, "Error opening FIFO: %s\n", strerror(errno));
        exit(1);
    }

    if (strcmp(argv[1], "read") == 0) {
        while (1) {
            int bytes_read = read(fd, buffer, SIZE);
            if (bytes_read <= 0) {
                fprintf(stderr, "Error reading from FIFO: %s\n", strerror(errno));
                exit(1);
            }
            buffer[bytes_read] = '\0';
            printf("Received message: %s\n", buffer);
        }
    } else if (strcmp(argv[1], "write") == 0) {
        while (1) {
            printf("Enter message to send: ");
            fgets(buffer, SIZE, stdin);
            int bytes_written = write(fd, buffer, strlen(buffer));
            if (bytes_written <= 0) {
                fprintf(stderr, "Error writing to FIFO: %s\n", strerror(errno));
                exit(1);
            }
        }
    } else {
        fprintf(stderr, "Invalid argument\n");
        exit(1);
    }

    close(fd);
    return 0;
}