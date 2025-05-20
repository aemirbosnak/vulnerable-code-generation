//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./ftp_client <server_ip> <file_name>\n");
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return 0;
    }

    printf("Connected to %s:%d\n", argv[1], PORT);

    send(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0);
    send(sockfd, "PASS @\r\n", strlen("PASS @\r\n"), 0);

    char command[BUFFER_SIZE];
    strcpy(command, "RETR ");
    strcat(command, argv[2]);
    strcat(command, "\r\n");

    send(sockfd, command, strlen(command), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    while (recv(sockfd, response, BUFFER_SIZE, 0) > 0) {
        printf("%s", response);
    }

    close(sockfd);

    return 0;
}