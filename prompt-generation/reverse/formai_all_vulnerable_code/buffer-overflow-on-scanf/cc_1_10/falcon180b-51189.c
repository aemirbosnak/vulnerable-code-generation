//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[100], password[100], command[100];
    char buffer[BUFFER_SIZE];
    int n;

    printf("Enter POP3 server address: ");
    scanf("%s", argv[1]);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to server\n");

    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = 0;

    printf("Server response: %s\n", buffer);

    if (strncmp(buffer, "+OK", 3) == 0) {
        send(sockfd, password, strlen(password), 0);
        send(sockfd, "\r\n", 2, 0);

        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        buffer[n] = 0;

        printf("Server response: %s\n", buffer);

        if (strncmp(buffer, "+OK", 3) == 0) {
            printf("Login successful\n");

            printf("Enter command: ");
            scanf("%s", command);

            send(sockfd, command, strlen(command), 0);
            send(sockfd, "\r\n", 2, 0);

            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            buffer[n] = 0;

            printf("Server response: %s\n", buffer);
        } else {
            printf("Login failed\n");
        }
    } else {
        printf("Login failed\n");
    }

    close(sockfd);

    return 0;
}