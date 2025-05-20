//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21

int main() {
    // Connect to FTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation error");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind error");
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        perror("Listen error");
        return 1;
    }

    int client_fd = accept(sockfd, NULL, NULL);
    if (client_fd == -1) {
        perror("Accept error");
        return 1;
    }

    printf("Connected to FTP client.\n");

    // Read command from user
    char command[100];
    printf("Enter command: ");
    scanf("%s", command);

    // Execute command
    char response[100];
    if (strcmp(command, "QUIT") == 0) {
        sprintf(response, "QUIT %s\r\n", command);
    } else if (strcmp(command, "USER") == 0) {
        sprintf(response, "USER %s\r\n", command);
    } else if (strcmp(command, "PASS") == 0) {
        sprintf(response, "PASS %s\r\n", command);
    } else if (strcmp(command, "SYST") == 0) {
        sprintf(response, "SYST %s\r\n", command);
    } else if (strcmp(command, "PORT") == 0) {
        sprintf(response, "PORT %s\r\n", command);
    } else if (strcmp(command, "PASV") == 0) {
        sprintf(response, "PASV %s\r\n", command);
    } else if (strcmp(command, "LIST") == 0) {
        sprintf(response, "LIST %s\r\n", command);
    } else if (strcmp(command, "RETR") == 0) {
        sprintf(response, "RETR %s\r\n", command);
    } else if (strcmp(command, "STOR") == 0) {
        sprintf(response, "STOR %s\r\n", command);
    } else if (strcmp(command, "ABOR") == 0) {
        sprintf(response, "ABOR\r\n");
    } else if (strcmp(command, "SIZE") == 0) {
        sprintf(response, "SIZE %s\r\n", command);
    } else if (strcmp(command, "HELP") == 0) {
        sprintf(response, "HELP\r\n");
    } else {
        sprintf(response, "Invalid command\r\n");
    }

    write(client_fd, response, strlen(response));
    close(sockfd);

    return 0;
}