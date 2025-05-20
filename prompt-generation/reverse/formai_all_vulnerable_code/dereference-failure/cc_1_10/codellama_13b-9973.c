//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_PENDING 5
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd, new_fd, portno, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_DATA_LEN];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, MAX_PENDING);

    while (1) {
        new_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (new_fd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        n = read(new_fd, buffer, MAX_DATA_LEN);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Server received %d bytes from client\n", n);

        n = write(new_fd, "Hello, client!", 13);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        printf("Server sent %d bytes to client\n", n);

        close(new_fd);
    }

    close(sockfd);
    return 0;
}