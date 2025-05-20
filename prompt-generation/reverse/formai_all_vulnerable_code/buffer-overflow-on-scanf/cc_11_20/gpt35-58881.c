//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port = 110;
    struct sockaddr_in server;
    char user[100], pass[100], command[100], buffer[BUFFER_SIZE];
    char *response;

    if(argc < 2) {
        printf("Usage: %s ip_address [port]\n", argv[0]);
        return -1;
    }

    if(argc == 3) {
        port = atoi(argv[2]);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Could not create socket.\n");
        return -1;
    }

    printf("Socket created.\n");

    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to remote server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }

    printf("Connected to server.\n");

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Receive failed.\n");
        return -1;
    }

    printf("%s", buffer);

    // Send user command
    printf("User: ");
    scanf("%s", user);
    snprintf(command, sizeof(command), "USER %s\r\n", user);
    if(send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        return -1;
    }

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Receive failed.\n");
        return -1;
    }

    printf("%s", buffer);

    // Send pass command
    printf("Password: ");
    scanf("%s", pass);
    snprintf(command, sizeof(command), "PASS %s\r\n", pass);
    if(send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        return -1;
    }

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Receive failed.\n");
        return -1;
    }

    printf("%s", buffer);

    // Send list command
    snprintf(command, sizeof(command), "LIST\r\n");
    if(send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        return -1;
    }

    // Receive list response
    memset(buffer, 0, sizeof(buffer));
    if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Receive failed.\n");
        return -1;
    }

    printf("%s", buffer);

    // Send quit command
    snprintf(command, sizeof(command), "QUIT\r\n");
    if(send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        return -1;
    }

    // Receive quit response
    memset(buffer, 0, sizeof(buffer));
    if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
        printf("Receive failed.\n");
        return -1;
    }

    printf("%s", buffer);

    close(sock);

    printf("Disconnected from server.\n");

    return 0;
}