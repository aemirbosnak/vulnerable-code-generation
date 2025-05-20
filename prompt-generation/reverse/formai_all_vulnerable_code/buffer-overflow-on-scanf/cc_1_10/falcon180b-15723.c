//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc!= 4) {
        printf("Usage:./ftp_client <host> <port> <username>\n");
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];
    char *username = argv[3];

    int sockfd;
    struct addrinfo *server_info;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    memset(&server_info, 0, sizeof(server_info));
    server_info->ai_family = AF_INET;
    server_info->ai_socktype = SOCK_STREAM;
    server_info->ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, port, &server_info, NULL)!= 0) {
        printf("Error resolving host.\n");
        exit(1);
    }

    connect(sockfd, server_info->ai_addr, server_info->ai_addrlen);

    char username_buffer[50];
    sprintf(username_buffer, "USER %s\r\n", username);
    send(sockfd, username_buffer, strlen(username_buffer), 0);

    char password_buffer[50];
    printf("Enter password for %s:\n", username);
    scanf("%s", password_buffer);

    char password_message[100];
    sprintf(password_message, "PASS %s\r\n", password_buffer);
    send(sockfd, password_message, strlen(password_message), 0);

    char welcome_message[BUFFER_SIZE];
    recv(sockfd, welcome_message, BUFFER_SIZE, 0);
    printf("Welcome message: %s", welcome_message);

    close(sockfd);
    return 0;
}