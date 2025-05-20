//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 2048

int main(int argc, char **argv) {
    int lfd, rfd;
    char buffer[MAX_BUFFER_SIZE];

    if (argc != 3) {
        printf("Missing arguments. Usage: ./proxy [local port] [remote host:remote port]\n");
        exit(EXIT_FAILURE);
    }

    // Get local port number
    int local_port = atoi(argv[1]);

    // Get remote host and port number
    char *remote_host = strtok(argv[2], ":");
    char *remote_port = strtok(NULL, ":");

    if (!remote_host || !remote_port) {
        printf("Invalid arguments. Usage: ./proxy [local port] [remote host:remote port]\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket for accepting incoming connections
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse the address and port
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    // Bind the socket to the local port
    struct sockaddr_in laddr = {0};
    laddr.sin_family = AF_INET;
    laddr.sin_addr.s_addr = htonl(INADDR_ANY);
    laddr.sin_port = htons(local_port);
    if (bind(lfd, (struct sockaddr *)&laddr, sizeof(laddr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections (backlog queue size = 10)
    if (listen(lfd, 10) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept an incoming connection from a client
        struct sockaddr_in caddr = {0};
        socklen_t caddr_len = sizeof(caddr);
        int cfd = accept(lfd, (struct sockaddr *)&caddr, &caddr_len);
        if (cfd < 0) {
            perror("accept() failed");
            continue;
        }

        // Resolve the address of the remote host
        struct hostent *he = gethostbyname(remote_host);
        if (!he) {
            printf("gethostbyname() failed: %s\n", hstrerror(h_errno));
            close(cfd);
            continue;
        }

        // Create a socket for connecting to the remote host
        rfd = socket(AF_INET, SOCK_STREAM, 0);
        if (rfd < 0) {
            perror("socket() failed");
            close(cfd);
            continue;
        }

        // Connect to the remote host
        struct sockaddr_in raddr = {0};
        raddr.sin_family = AF_INET;
        raddr.sin_port = htons(atoi(remote_port));
        raddr.sin_addr = *((struct in_addr *)he->h_addr);
        if (connect(rfd, (struct sockaddr *)&raddr, sizeof(raddr)) < 0) {
            perror("connect() failed");
            close(cfd);
            close(rfd);
            continue;
        }

        // Read from client and write to remote host
        while (1) {
            ssize_t nread = recv(cfd, buffer, MAX_BUFFER_SIZE, 0);
            if (nread == 0) {
                break;
            }
            if (nread < 0) {
                perror("recv() failed");
                break;
            }
            ssize_t nwrite = send(rfd, buffer, nread, 0);
            if (nwrite != nread) {
                printf("send() failed");
                break;
            }
        }

        // Read from remote host and write to client
        while (1) {
            ssize_t nread = recv(rfd, buffer, MAX_BUFFER_SIZE, 0);
            if (nread == 0) {
                break;
            }
            if (nread < 0) {
                perror("recv() failed");
                break;
            }
            ssize_t nwrite = send(cfd, buffer, nread, 0);
            if (nwrite != nread) {
                printf("send() failed");
                break;
            }
        }

        // Close sockets
        close(cfd);
        close(rfd);
    }

    return 0;
}