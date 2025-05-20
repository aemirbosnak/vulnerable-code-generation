//Falcon-180B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        execlp("sh", "sh", "-c", command, NULL);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void create_file(char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Error creating file\n");
        exit(1);
    }

    close(fd);
}

void write_to_file(char *filename, char *data) {
    int fd = open(filename, O_RDWR | O_APPEND);

    if (fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    write(fd, data, strlen(data));
    close(fd);
}

int main() {
    char command[100];
    char filename[100];

    while (1) {
        printf("Enter command (write to file): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        printf("Enter filename: ");
        scanf("%s", filename);

        execute_command(command);
        create_file(filename);
        write_to_file(filename, command);
    }

    return 0;
}