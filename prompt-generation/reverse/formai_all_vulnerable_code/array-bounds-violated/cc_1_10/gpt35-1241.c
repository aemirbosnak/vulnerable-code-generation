//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#define MAX_BUFF_SIZE 1024

int fd;

void read_callback(int signal) {
    char buffer[MAX_BUFF_SIZE];
    lseek(fd, 0, SEEK_SET);
    ssize_t bytes_read = read(fd, buffer, MAX_BUFF_SIZE);
    if(bytes_read < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0';
    printf("Current RAM usage: %s", buffer);
}

int main() {
    fd = open("/proc/meminfo", O_RDONLY);
    if(fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // read the initial RAM usage
    char buffer[MAX_BUFF_SIZE];
    ssize_t bytes_read = read(fd, buffer, MAX_BUFF_SIZE);
    if(bytes_read < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0';
    printf("Current RAM usage: %s", buffer);

    // set up signal handler for SIGIO
    struct sigaction sa;
    sa.sa_handler = read_callback;
    if(sigaction(SIGIO, &sa, NULL) < 0) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // set the file descriptor to be asynchronous
    if(fcntl(fd, F_SETOWN, getpid()) < 0) {
        perror("fcntl F_SETOWN");
        exit(EXIT_FAILURE);
    }
    if(fcntl(fd, F_SETFL, O_ASYNC) < 0) {
        perror("fcntl F_SETFL");
        exit(EXIT_FAILURE);
    }

    while(1) {
        sleep(1); // wait for signal
    }

    close(fd);
    return 0;
}