//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";
    int server_port = 21;
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *command = "USER anonymous\r\n";
    char *response;
    int response_len;
    char *token;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Connecting to server...\n");

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    // Send USER command
    send(sockfd, command, strlen(command), 0);

    response_len = recv(sockfd, response, 1024, 0);
    response[response_len] = '\0';

    printf("Response: %s\n", response);

    token = strtok(response, " ");
    while (token!= NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    close(sockfd);

    return 0;
}