//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    struct addrinfo *server_info;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if ((server_info = getaddrinfo(host, "143", NULL, NULL)) == NULL) {
        printf("Error getting server address\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        freeaddrinfo(server_info);
        return 1;
    }

    freeaddrinfo(server_info);

    char *auth_string = "LOGIN ";
    strcat(auth_string, username);
    strcat(auth_string, " ");
    strcat(auth_string, password);
    send(sockfd, auth_string, strlen(auth_string), 0);

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    while (1) {
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            printf("Error receiving data from server\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}