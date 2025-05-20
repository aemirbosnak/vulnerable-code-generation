//FormAI DATASET v1.0 Category: Socket programming ; Style: scalable
// Server side implementation of scalable C socket programming
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT 8080 // Port used for socket communication
#define BACKLOG 10 // Maximum number of pending connections in the queue
#define MAXDATASIZE 100 // Maximum number of bytes we can get at once

void sigchld_handler(int signo) {
    // handle to prevent zombie processes
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

void *get_in_addr(struct sockaddr *sa) {
    // get IPv4 or IPv6 address from sockaddr structure
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main() {
    int sockfd, new_fd; // file descriptors for socket
    struct sockaddr_in my_addr; // server address info
    struct sockaddr_in their_addr; // client address info
    int yes = 1;
    char buf[MAXDATASIZE]; // buffer for incoming message
    int numbytes;
    socklen_t sin_size;
    struct sigaction sa;
    int rv;

    memset(&my_addr, 0, sizeof my_addr);
    my_addr.sin_family = AF_INET; // IPv4
    my_addr.sin_port = htons(PORT); // convert to network byte order
    my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
        close(sockfd);
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while(1) {
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);

        if (new_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s\n", inet_ntoa(their_addr.sin_addr));

        if (!fork()) {
            close(sockfd);
            if (send(new_fd, "Welcome, you connected to the server", 38, 0) == -1) {
                perror("send");
            }

            if ((numbytes = recv(new_fd, buf, MAXDATASIZE-1, 0)) == -1) {
                perror("recv");
                exit(1);
            }

            buf[numbytes] = '\0';

            printf("Received: %s\n", buf);

            if (send(new_fd, buf, numbytes, 0) == -1) {
                perror("send");
            }

            close(new_fd);
            exit(0);
        }

        close(new_fd);
    }

    return 0;
}