//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, new_socket;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int len;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            break;
        }
        buffer[len] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}