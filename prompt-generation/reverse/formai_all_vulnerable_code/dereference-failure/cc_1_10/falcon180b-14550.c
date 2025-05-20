//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[10000];
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Server not found\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    newsockfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
    if (newsockfd < 0) {
        printf("Error accepting connection\n");
        exit(0);
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(newsockfd, buffer, sizeof(buffer));
        printf("%s", buffer);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}