//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "pop.example.com" //replace with the pop server address
#define PORT 110 // the pop3 server port number

int main(void) {
    int sock;
    struct sockaddr_in server_addr;
    char username[50], password[50], buffer[1024];
    char message[100];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    printf("Socket created\n");

    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        return 1;
    }

    printf("Connected to the server\n");

    // receive the welcome message from the server
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Receive failed");
        return 1;
    }

    printf("Server message: %s\n", buffer);

    // send the username to the server
    printf("Enter username: ");
    scanf("%s", username);
    sprintf(message, "USER %s\r\n", username);

    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error: send failed");
        return 1;
    }

    // receive the response from the server
    if (recv(sock, buffer, 1024, 0) < 0) {
        printf("Error: recv failed");
        return 1;
    }

    printf("Server message: %s\n", buffer);

    // send the password to the server
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(message, "PASS %s\r\n", password);

    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error: send failed");
        return 1;
    }

    // receive the response from the server
    if (recv(sock, buffer, 1024, 0) < 0) {
        printf("Error: recv failed");
        return 1;
    }

    printf("Server message: %s\n", buffer);

    // check the mailbox
    sprintf(message, "LIST\r\n");

    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error: send failed");
        return 1;
    }

    printf("Getting mailbox information...\n");

    // receive the response from the server
    if (recv(sock, buffer, 1024, 0) < 0) {
        printf("Error: recv failed");
        return 1;
    }

    printf("Server message: %s\n", buffer);

    // quit
    sprintf(message, "QUIT\r\n");

    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error: send failed");
        return 1;
    }

    // receive the response from the server
    if (recv(sock, buffer, 1024, 0) < 0) {
        printf("Error: recv failed");
        return 1;
    }

    printf("Server message: %s\n", buffer);

    close(sock);

    return 0;
}