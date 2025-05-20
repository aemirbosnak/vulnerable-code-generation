//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define SERVER "localhost"
#define PORT 110
#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *username = USERNAME;
    char *password = PASSWORD;

    if (argc!= 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    if (send(sockfd, username, strlen(username), 0) == -1) {
        printf("Error sending username\n");
        close(sockfd);
        return 1;
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        printf("Error sending password\n");
        close(sockfd);
        return 1;
    }

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}