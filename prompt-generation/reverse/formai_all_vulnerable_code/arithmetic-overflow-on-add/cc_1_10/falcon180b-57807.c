//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    inet_pton(AF_INET, "imap.gmail.com", &server_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char *login_cmd = "LOGIN ";
    strcat(login_cmd, USERNAME);
    strcat(login_cmd, " ");
    strcat(login_cmd, PASSWORD);
    strcat(login_cmd, "\r\n");

    send(sockfd, login_cmd, strlen(login_cmd), 0);

    char *response = "";
    int bytes_received = 0;

    while (bytes_received < 5) {
        bytes_received += recv(sockfd, buffer, BUFFER_SIZE, 0);
        response = strncat(response, buffer, BUFFER_SIZE);
    }

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}