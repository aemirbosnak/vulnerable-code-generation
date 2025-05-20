//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_address;
    int server_port;
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    if (argc!= 4) {
        printf("Usage:./program <server_address> <server_port> <message>\n");
        return 1;
    }

    server_address = argv[1];
    server_port = atoi(argv[2]);
    strcpy(buffer, argv[3]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(server_address, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        return 1;
    }

    snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        perror("recv");
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("Response from server: %s\n", buffer);

    strcat(buffer, "MESSAGE\r\n");
    strcat(buffer, argv[3]);
    strcat(buffer, "\r\n");

    send(sockfd, buffer, strlen(buffer), 0);

    bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        perror("recv");
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("Response from server: %s\n", buffer);

    close(sockfd);
    return 0;
}