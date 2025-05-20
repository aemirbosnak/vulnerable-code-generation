//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *serverinfo;
    int rv;
    char *command = "USER anonymous\r\n";
    char *buffer = (char *) malloc(BUFFER_SIZE);

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <command>\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(argv[1], argv[2], &hints, &serverinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen);

    send(sockfd, command, strlen(command), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    free(buffer);
    return 0;
}