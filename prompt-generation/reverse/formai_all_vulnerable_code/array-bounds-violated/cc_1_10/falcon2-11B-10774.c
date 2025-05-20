//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// Function to read data from a file
void read_file(char *filename, char *data) {
    FILE *fp;
    int bytes_read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    bytes_read = fread(data, 1, sizeof(data), fp);
    fclose(fp);
}

// Function to write data to a file
void write_file(char *filename, char *data) {
    int fd;
    ssize_t bytes_written;

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    bytes_written = write(fd, data, strlen(data));
    if (bytes_written!= strlen(data)) {
        fprintf(stderr, "Error writing to file '%s'\n", filename);
        exit(1);
    }

    close(fd);
}

// Function to get the current working directory
void get_cwd(char *cwd) {
    char buf[1024];
    int len = readlink("/proc/self/cwd", buf, sizeof(buf));
    if (len <= 0) {
        fprintf(stderr, "Error getting current working directory\n");
        exit(1);
    }
    buf[len] = '\0';
    strncpy(cwd, buf, sizeof(cwd));
}

// Main function
int main() {
    char cwd[1024];
    char filename[1024];
    char data[1024];

    get_cwd(cwd);
    printf("Current working directory: %s\n", cwd);

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    printf("Enter the name of the file to write: ");
    scanf("%s", filename);
    printf("Enter the data to write: ");
    scanf("%s", data);

    read_file(filename, data);
    write_file(filename, data);

    return 0;
}