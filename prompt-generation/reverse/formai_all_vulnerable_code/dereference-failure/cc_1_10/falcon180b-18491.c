//Falcon-180B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_SIZE 256

int main() {
    char command[MAX_COMMAND_SIZE];
    printf("Enter a command: ");
    fgets(command, MAX_COMMAND_SIZE, stdin);

    if (strncmp(command, "ls", 2) == 0) {
        int fd = open(".", O_RDONLY);
        if (fd == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        char buffer[4096];
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        printf("%s", buffer);

        close(fd);
    } else if (strncmp(command, "mkdir", 5) == 0) {
        char dirname[MAX_COMMAND_SIZE];
        printf("Enter directory name: ");
        fgets(dirname, MAX_COMMAND_SIZE, stdin);

        int ret = mkdir(dirname, 0777);
        if (ret == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        printf("Directory created successfully.\n");
    } else if (strncmp(command, "rmdir", 5) == 0) {
        char dirname[MAX_COMMAND_SIZE];
        printf("Enter directory name: ");
        fgets(dirname, MAX_COMMAND_SIZE, stdin);

        int ret = rmdir(dirname);
        if (ret == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        printf("Directory removed successfully.\n");
    } else if (strncmp(command, "touch", 5) == 0) {
        char filename[MAX_COMMAND_SIZE];
        printf("Enter filename: ");
        fgets(filename, MAX_COMMAND_SIZE, stdin);

        int fd = open(filename, O_CREAT | O_WRONLY, 0777);
        if (fd == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        close(fd);

        printf("File created successfully.\n");
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}