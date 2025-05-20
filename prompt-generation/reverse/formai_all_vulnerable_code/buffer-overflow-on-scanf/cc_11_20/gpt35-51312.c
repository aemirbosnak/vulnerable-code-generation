//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// POP3 server IP address and port
#define SERVER "127.0.0.1"
#define PORT 110

#define BUFFER_SIZE 1024

int main()
{
    // Create a TCP socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive the greeting message from the server
    char buffer[BUFFER_SIZE] = {0};
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Login to the server
    char user[100], pass[100];
    printf("Username:");
    scanf("%s", user);
    printf("Password:");
    scanf("%s", pass);

    char cmd[100] = {0};
    snprintf(cmd, sizeof(cmd), "USER %s\r\n", user);
    send(sock_fd, cmd, strlen(cmd), 0);

    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", pass);
    send(sock_fd, cmd, strlen(cmd), 0);

    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // List all messages in the mailbox
    snprintf(cmd, sizeof(cmd), "LIST\r\n");
    send(sock_fd, cmd, strlen(cmd), 0);

    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Retrieve a message from the server
    int msg_id;
    printf("Message ID:");
    scanf("%d", &msg_id);

    snprintf(cmd, sizeof(cmd), "RETR %d\r\n", msg_id);
    send(sock_fd, cmd, strlen(cmd), 0);

    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Delete a message from the server
    printf("Delete message (y/n)?");
    char ans;
    scanf(" %c", &ans);

    if (ans == 'y') {
        snprintf(cmd, sizeof(cmd), "DELE %d\r\n", msg_id);
        send(sock_fd, cmd, strlen(cmd), 0);

        if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            exit(1);
        }

        printf("%s", buffer);
    }

    // Quit the session
    snprintf(cmd, sizeof(cmd), "QUIT\r\n");
    send(sock_fd, cmd, strlen(cmd), 0);

    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Close the socket
    close(sock_fd);

    return 0;
}