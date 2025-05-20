//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024

// function to create named pipe
int create_pipe(char *name) {
    int fd;
    if ((fd = mkfifo(name, 0666)) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    return fd;
}

// function to open named pipe for reading
int open_read_pipe(char *name) {
    int fd;
    if ((fd = open(name, O_RDONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    return fd;
}

// function to open named pipe for writing
int open_write_pipe(char *name) {
    int fd;
    if ((fd = open(name, O_WRONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    return fd;
}

// function to write data to pipe
int write_to_pipe(int fd, char *data) {
    int nbytes;
    if ((nbytes = write(fd, data, strlen(data))) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    return nbytes;
}

// function to read data from pipe
int read_from_pipe(int fd, char *buffer) {
    int nbytes;
    if ((nbytes = read(fd, buffer, MAX_SIZE)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    return nbytes;
}

int main() {
    char *read_buffer = (char *) malloc(MAX_SIZE * sizeof(char));
    char *write_buffer = (char *) malloc(MAX_SIZE * sizeof(char));

    // create named pipe
    int pipe_fd = create_pipe("my_pipe");

    // open pipe for reading and writing
    int read_fd = open_read_pipe("my_pipe");
    int write_fd = open_write_pipe("my_pipe");

    // write data to pipe
    strcpy(write_buffer, "Hello, World!");
    write_to_pipe(write_fd, write_buffer);

    // read data from pipe
    read_from_pipe(read_fd, read_buffer);

    // print data read from pipe
    printf("Data read from pipe: %s\n", read_buffer);

    // close pipe file descriptors
    close(read_fd);
    close(write_fd);
    close(pipe_fd);

    return 0;
}