//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    char command[100];
    char response[100];
    int status;
    int bytes_received;
    time_t current_time;

    printf("Enter POP3 server address: ");
    scanf("%s", server_addr.sin_addr.s_addr);

    printf("Enter POP3 server port: ");
    scanf("%d", &server_addr.sin_port);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server_addr.sin_addr.s_addr, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);

    sprintf(command, "STAT\r\n");
    send(sockfd, command, strlen(command), 0);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}