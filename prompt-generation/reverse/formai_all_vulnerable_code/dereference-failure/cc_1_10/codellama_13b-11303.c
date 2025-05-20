//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 8192
#define MAX_WAIT_TIME 5

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_PACKET_SIZE];
    struct sockaddr_in serveraddr;
    struct hostent *server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    while (1) {
        n = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);
        if (n < 0) {
            perror("Error receiving data");
            exit(1);
        }

        if (n == 0) {
            fprintf(stderr, "Server closed connection\n");
            exit(1);
        }

        printf("Received packet of size %d\n", n);

        if (n == MAX_PACKET_SIZE) {
            printf("Max packet size reached\n");
        }
    }

    return 0;
}