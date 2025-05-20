//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    listen(sockfd, MAX_CLIENTS);

    clilen = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
    if (new_sockfd < 0) {
        perror("accept");
        return 1;
    }

    while (1) {
        bzero(buffer, MAX_BUFFER_SIZE);
        int n = read(new_sockfd, buffer, MAX_BUFFER_SIZE);
        if (n < 0) {
            perror("read");
            return 1;
        }

        if (n == 0) {
            break;
        }

        printf("Received message: %s\n", buffer);

        char response[MAX_BUFFER_SIZE];
        sprintf(response, "Received message: %s", buffer);
        n = write(new_sockfd, response, strlen(response));
        if (n < 0) {
            perror("write");
            return 1;
        }
    }

    close(new_sockfd);
    close(sockfd);

    return 0;
}