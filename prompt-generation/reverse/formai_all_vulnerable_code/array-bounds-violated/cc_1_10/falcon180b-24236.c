//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct addrinfo *serverinfo;
    char *server;
    char *username;
    char *password;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 5) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    server = argv[1];
    username = argv[2];
    password = argv[3];

    if ((serverinfo = getaddrinfo(server, "110", NULL, NULL)) == NULL) {
        printf("Error: cannot resolve %s\n", server);
        return 1;
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);
    if (sockfd == -1) {
        printf("Error: cannot create socket\n");
        return 1;
    }

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        printf("Error: cannot connect to %s\n", server);
        return 1;
    }

    freeaddrinfo(serverinfo);

    printf("Connected to %s\n", server);
    printf("Logging in as %s\n", username);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    memset(buffer, 0, BUFFER_SIZE);
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    memset(buffer, 0, BUFFER_SIZE);
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(sockfd);

    return 0;
}