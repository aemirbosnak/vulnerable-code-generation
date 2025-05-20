//GEMINI-pro DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <string.h>

#define MAX_EVENTS 10

int main() {
    int fd, epollfd;
    struct epoll_event event;
    char buffer[1024];
    int bytes_read;

    // Open the file for reading
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Create an epoll instance
    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        return EXIT_FAILURE;
    }

    // Add the file descriptor to the epoll instance
    event.events = EPOLLIN;
    event.data.fd = fd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) == -1) {
        perror("epoll_ctl");
        return EXIT_FAILURE;
    }

    // Main loop
    while (1) {
        int nfds;
        struct epoll_event events[MAX_EVENTS];

        // Wait for events
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            return EXIT_FAILURE;
        }

        // Process events
        for (int i = 0; i < nfds; i++) {
            if (events[i].events & EPOLLIN) {
                // Read data from the file
                bytes_read = read(events[i].data.fd, buffer, sizeof(buffer));
                if (bytes_read == -1) {
                    perror("read");
                    return EXIT_FAILURE;
                }

                // Write the data to stdout
                if (write(STDOUT_FILENO, buffer, bytes_read) == -1) {
                    perror("write");
                    return EXIT_FAILURE;
                }
            }
        }
    }

    // Close the file
    close(fd);

    // Close the epoll instance
    close(epollfd);

    return EXIT_SUCCESS;
}