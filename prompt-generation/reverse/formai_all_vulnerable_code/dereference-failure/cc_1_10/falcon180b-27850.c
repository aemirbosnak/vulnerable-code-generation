//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    struct hostent *hostinfo;
    char buffer[1024];

    if (argc < 3) {
        printf("Usage:./smtp_client <server_address> <port_number>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    hostinfo = gethostbyname(argv[1]);
    if (hostinfo == NULL) {
        printf("Error: Invalid server address.\n");
        close(sockfd);
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    serveraddr.sin_addr = *((struct in_addr *)hostinfo->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error: Could not connect to server.\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server.\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("Received from server: %s", buffer);
    }

    close(sockfd);
    return 0;
}