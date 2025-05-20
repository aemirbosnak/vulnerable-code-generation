//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
/*
 * C Network Quality of Service (QoS) monitor example program
 * in a unmistakable style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_PACKET_SIZE 1500

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, MAX_PACKET_SIZE);
        if (n < 0) {
            perror("read");
            exit(1);
        } else if (n == 0) {
            fprintf(stderr, "EOF\n");
            break;
        }

        printf("Received packet: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}