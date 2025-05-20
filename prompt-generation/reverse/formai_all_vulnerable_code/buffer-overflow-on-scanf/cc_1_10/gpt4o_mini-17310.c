//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void sendCommand(int sock, const char *command) {
    write(sock, command, strlen(command));
    write(sock, "\r\n", 2);
}

void receiveResponse(int sock) {
    char buffer[BUFFER_SIZE];
    int n = read(sock, buffer, BUFFER_SIZE - 1);
    if (n < 0) error("Error reading response");
    buffer[n] = '\0';
    printf("%s", buffer);
}

void listMessages(int sock) {
    sendCommand(sock, "LIST");
    receiveResponse(sock);
}

void readMessage(int sock, int msgNumber) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d", msgNumber);
    sendCommand(sock, command);
    receiveResponse(sock);
}

void connectToServer(const char *hostname, int port, const char *username, const char *password) {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) error("Failed to create socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        close(sock);
        error("Unable to connect to server");
    }

    // Receive server greeting
    receiveResponse(sock);

    // Send user command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", username);
    sendCommand(sock, command);
    receiveResponse(sock);

    // Send pass command
    snprintf(command, sizeof(command), "PASS %s", password);
    sendCommand(sock, command);
    receiveResponse(sock);

    // List messages
    listMessages(sock);

    // Read a specific message (for example message number 1)
    printf("Enter the message number you want to read: ");
    int msgNumber;
    scanf("%d", &msgNumber);
    readMessage(sock, msgNumber);

    // Send quit command
    sendCommand(sock, "QUIT");
    receiveResponse(sock);

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    connectToServer(hostname, PORT, username, password);

    return 0;
}