//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024

/* Function to print error message and exit */
void error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/* Function to read a file line by line and print its content */
void read_file(const char *filename)
{
    int fd;
    char line[MAX_LINE_LENGTH];
    ssize_t nbytes;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error("Failed to open file");
    }

    while ((nbytes = read(fd, line, MAX_LINE_LENGTH)) > 0) {
        line[nbytes] = '\0';
        printf("%s", line);
    }

    if (nbytes == -1) {
        error("Failed to read file");
    }

    close(fd);
}

/* Function to write data to a file */
void write_file(const char *filename, const char *data)
{
    int fd;
    ssize_t nbytes;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        error("Failed to open file");
    }

    nbytes = write(fd, data, strlen(data));
    if (nbytes == -1) {
        error("Failed to write file");
    }

    close(fd);
}

/* Function to create a directory */
void create_dir(const char *dirname)
{
    int ret;

    ret = mkdir(dirname, 0755);
    if (ret == -1) {
        if (errno!= EEXIST) {
            error("Failed to create directory");
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        error("Usage:./program <filename> <operation>");
    }

    const char *filename = argv[1];
    const char *operation = argv[2];

    if (strcmp(operation, "read") == 0) {
        read_file(filename);
    } else if (strcmp(operation, "write") == 0) {
        char data[MAX_LINE_LENGTH];
        printf("Enter data to write: ");
        fgets(data, MAX_LINE_LENGTH, stdin);
        write_file(filename, data);
    } else if (strcmp(operation, "create_dir") == 0) {
        create_dir(filename);
    } else {
        error("Invalid operation");
    }

    return 0;
}