//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    int addrlen;
    char buffer[BUFFER_SIZE];
    int nbytes;
    char *message = "Hello, world!";

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    addrlen = sizeof(server_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to server.\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (nbytes == 0) {
            fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
            exit(1);
        } else if (nbytes == -1) {
            fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received message: %s\n", buffer);

        if (strcmp(buffer, "bye") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}