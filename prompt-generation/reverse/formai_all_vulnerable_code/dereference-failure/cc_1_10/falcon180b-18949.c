//Falcon-180B DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024

void read_file(char *filename, char *buffer) {
    int fd, bytes_read;
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }
    bytes_read = read(fd, buffer, MAX_LINE);
    if (bytes_read < 0) {
        perror("Error reading file");
        exit(1);
    }
    buffer[bytes_read] = '\0';
    close(fd);
}

void write_file(char *filename, char *buffer) {
    int fd, bytes_written;
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }
    bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written < 0) {
        perror("Error writing file");
        exit(1);
    }
    close(fd);
}

int main(int argc, char **argv) {
    char buffer[MAX_LINE];
    char *filename = argv[1];
    char *cmd = argv[2];
    pid_t pid;
    int status;
    FILE *fp;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <filename> <command>\n", argv[0]);
        exit(1);
    }

    read_file(filename, buffer);

    if (strcmp(cmd, "grep") == 0) {
        fp = popen("grep -i \"*\" ", "r");
        if (fp == NULL) {
            perror("Error executing command");
            exit(1);
        }
        fprintf(fp, "%s", buffer);
        pclose(fp);
    } else if (strcmp(cmd, "sort") == 0) {
        fp = popen("sort ", "r");
        if (fp == NULL) {
            perror("Error executing command");
            exit(1);
        }
        fprintf(fp, "%s", buffer);
        pclose(fp);
    } else {
        fprintf(stderr, "Invalid command\n");
        exit(1);
    }

    return 0;
}