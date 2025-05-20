//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "pop3.example.com"
#define PORT 110
#define BUFFER_SIZE 1024

void searchForClues(const char *message) {
    // A function for Sherlock to find clues in the given message 
    printf("Sherlock examines the message:\n%s\n", message);
    // Here we may pretend Sherlock deduces something from the message
    printf("Sherlock deduces there's something interesting here...\n");
}

int connectToServer(const char *server, int port) {
    int socket_desc;
    struct sockaddr_in server_addr;

    // Creating socket
    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        return -1;
    }

    // Set up server structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    // Connecting to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Connection failed: %s\n", strerror(errno));
        close(socket_desc);
        return -1;
    }

    return socket_desc;
}

void retrieveEmails(int socket) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Send USER command
    printf("Enter your username: ");
    scanf("%s", command);
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", command);
    send(socket, buffer, strlen(buffer), 0);
    recv(socket, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s", buffer);

    // Send PASS command
    printf("Enter your password: ");
    scanf("%s", command);
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", command);
    send(socket, buffer, strlen(buffer), 0);
    recv(socket, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s", buffer);

    // Send LIST command to get list of mail
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    send(socket, buffer, strlen(buffer), 0);
    recv(socket, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s", buffer);

    // Sherlock needs to read the list of emails
    printf("Sherlock is analyzing the emails...\n");
    searchForClues(buffer);

    // Send QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(socket, buffer, strlen(buffer), 0);
    recv(socket, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s", buffer);
}

int main() {
    printf("Welcome to the Sherlock Holmes POP3 Email Client\n");

    // Connect to the POP3 server
    int socket = connectToServer(SERVER, PORT);
    if (socket == -1) {
        fprintf(stderr, "Could not connect to the server. Farewell!\n");
        return 1;
    }

    // Let's retrieve emails
    retrieveEmails(socket);

    // Closing the socket
    close(socket);
    printf("Sherlock bids you adieu. Until next time!\n");
    return 0;
}