//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *username, *password;
    char *filename;

    if (argc!= 6) {
        printf("Usage:./ftp_client <server_ip> <port> <username> <password> <filename>\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Server not found.\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed.\n");
        exit(0);
    }

    portno = atoi(argv[2]);
    if (portno == 0) {
        printf("Invalid port number.\n");
        exit(0);
    }

    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "USER %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "PASS %s\r\n", argv[4]);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "RETR %s\r\n", argv[5]);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(sockfd);
    exit(0);
}