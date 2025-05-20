//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_SERVER "pop.example.com"
#define POP3_PORT 110

int main()
{
    printf("POP3 Client Example Program\n\n");

    // Create the socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Connect to the POP3 server
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(POP3_SERVER);
    server.sin_port = htons(POP3_PORT);

    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to POP3 server %s on port %d\n", POP3_SERVER, POP3_PORT);

    // Receive the server greeting
    char buffer[1024];
    int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
    if(bytesReceived < 0) {
        printf("Error receiving server greeting\n");
        return 1;
    }

    buffer[bytesReceived] = '\0';
    printf("Server greeting: %s\n", buffer);

    // Send the username
    char username[256];
    printf("Username: ");
    scanf("%s", username);

    char command[512];
    sprintf(command, "USER %s\r\n", username);

    int bytesSent = send(sock, command, strlen(command), 0);
    if(bytesSent < 0) {
        printf("Error sending username\n");
        return 1;
    }

    // Receive the username response
    bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
    if(bytesReceived < 0) {
        printf("Error receiving username response\n");
        return 1;
    }

    buffer[bytesReceived] = '\0';
    printf("Username response: %s\n", buffer);

    // Send the password
    char password[256];
    printf("Password: ");
    scanf("%s", password);

    sprintf(command, "PASS %s\r\n", password);

    bytesSent = send(sock, command, strlen(command), 0);
    if(bytesSent < 0) {
        printf("Error sending password\n");
        return 1;
    }

    // Receive the password response
    bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
    if(bytesReceived < 0) {
        printf("Error receiving password response\n");
        return 1;
    }

    buffer[bytesReceived] = '\0';
    printf("Password response: %s\n", buffer);

    // Send the list command
    sprintf(command, "LIST\r\n");

    bytesSent = send(sock, command, strlen(command), 0);
    if(bytesSent < 0) {
        printf("Error sending list command\n");
        return 1;
    }

    // Receive the list response
    bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
    if(bytesReceived < 0) {
        printf("Error receiving list response\n");
        return 1;
    }

    buffer[bytesReceived] = '\0';
    printf("List response: %s\n", buffer);

    // Close the connection
    close(sock);

    printf("Connection closed\n");

    return 0;
}