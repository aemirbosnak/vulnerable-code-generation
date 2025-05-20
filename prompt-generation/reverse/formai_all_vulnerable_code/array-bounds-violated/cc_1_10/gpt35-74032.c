//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main() {
    int sock;
    struct sockaddr_in server;
    char server_reply[BUFFER_SIZE];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    printf("Connected\n");
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("recv failed");
    }
    server_reply[strlen(server_reply)-2] = '\0';
    printf("%s\n", server_reply);
    memset(server_reply, 0, sizeof(server_reply));

    // Login
    char username[BUFFER_SIZE] = "USER example@mail.com\r\n";
    char password[BUFFER_SIZE] = "PASS example_password\r\n";
    char list[BUFFER_SIZE] = "LIST\r\n";

    send(sock, username, strlen(username), 0);
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("recv failed");
    }
    server_reply[strlen(server_reply)-2] = '\0';
    printf("%s\n", server_reply);
    memset(server_reply, 0, sizeof(server_reply));

    send(sock, password, strlen(password), 0);
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("recv failed");
    }
    server_reply[strlen(server_reply)-2] = '\0';
    printf("%s\n", server_reply);
    memset(server_reply, 0, sizeof(server_reply));

    // List emails
    send(sock, list, strlen(list), 0);
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("recv failed");
    }
    server_reply[strlen(server_reply)-2] = '\0';
    printf("%s\n", server_reply);
    memset(server_reply, 0, sizeof(server_reply));

    // Close the socket
    close(sock);

    return 0;
}