//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "localhost"
#define PORT 110
#define USER "your_username"
#define PASSWORD "your_password"
#define BUFFER_SIZE 1024

int main(void) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        return 2;
    }

    char username[20] = USER;
    char password[20] = PASSWORD;
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            printf("Error: Connection closed by server\n");
            return 3;
        }

        if (bytes_received == -1) {
            printf("Error: Failed to receive data from server\n");
            return 4;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}