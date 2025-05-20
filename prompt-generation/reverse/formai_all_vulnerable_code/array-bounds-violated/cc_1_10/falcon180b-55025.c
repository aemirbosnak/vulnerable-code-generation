//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("socket creation failed\n");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("connection failed\n");
        exit(0);
    }

    printf("Connected to server\n");

    char *username = "anonymous";
    char *password = "anonymous@example.com";

    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    char *command = "LIST\r\n";
    send(sockfd, command, strlen(command), 0);

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (n <= 0) {
            printf("Disconnected from server\n");
            exit(0);
        }

        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}