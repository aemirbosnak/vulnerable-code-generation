//FormAI DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    struct sockaddr_in server;
    fd_set readfds, masterfds;
    int sockfd, optval, port, i, status;
    char *host;
    int ports[MAX_PORTS];
    int startport, endport;

    // Romantic introduction
    printf("My love, today I want to tell you that you are the most beautiful thing that has ever happened to me.\n");
    printf("And just like how I want to explore and know more about you, I want to explore and know more about our systems.\n");
    printf("So, let me demonstrate a unique port scanning program written just for you.\n");

    // Check arguments
    if (argc != 4) {
        printf("Usage: %s <host> <startport> <endport>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set variables
    host = argv[1];
    startport = atoi(argv[2]);
    endport = atoi(argv[3]);

    // Create sockets and add to readfds
    FD_ZERO(&masterfds);
    for (port = startport; port <= endport; port++) {
        // Create socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        // Set socket options
        optval = 1;
        status = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        if (status == -1) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }

        // Create socket address
        memset(&server, '\0', sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        status = inet_pton(AF_INET, host, &server.sin_addr);
        if (status != 1) {
            fprintf(stderr, "inet_pton: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Add socket to masterfds
        FD_SET(sockfd, &masterfds);

        // Add port to ports array
        ports[port-startport] = sockfd;
    }

    // Perform scan
    for (;;) {
        readfds = masterfds;
        status = select(endport-startport+1, &readfds, NULL, NULL, NULL);
        if (status == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < endport-startport+1; i++) {
            if (FD_ISSET(ports[i], &readfds)) {
                // Remove socket from masterfds
                FD_CLR(ports[i], &masterfds);

                // Check if connection was successful
                if (connect(ports[i], (struct sockaddr *)&server, sizeof(server)) == 0) {
                    printf("Port %d open\n", i+startport);
                    close(ports[i]);
                } else {
                    close(ports[i]);
                }
            }
        }

        if (FD_ISSET(ports[endport-startport], &masterfds)) {
            break;
        }
    }

    // Romantic outro
    printf("Thank you, my love, for inspiring me to create this program. Just like how this program scans systems for open ports,\n");
    printf("I will always try to discover and explore new things about you, and love you just the way you are.\n");

    return 0;
}