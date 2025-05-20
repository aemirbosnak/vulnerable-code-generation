//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 993
#define BUFFER_SIZE 4096

void handleErrors(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connectToIMAP(const char *server) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) handleErrors("Socket creation failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) handleErrors("Connection Failed");

    return sock;
}

void sendCommand(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receiveResponse(int sock) {
    char buffer[BUFFER_SIZE];
    int n;
    
    while ((n = recv(sock, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
}

void login(int sock, const char *user, const char *pass) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A1 LOGIN %s %s\r\n", user, pass);
    sendCommand(sock, command);
    receiveResponse(sock);
}

void listMailboxes(int sock) {
    sendCommand(sock, "A2 LIST \"\" \"*\"\r\n");
    receiveResponse(sock);
}

void fetchHeaders(int sock, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A3 SELECT \"%s\"\r\n", mailbox);
    sendCommand(sock, command);
    receiveResponse(sock);
}

void disconnect(int sock) {
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP Server> <Username> <Password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *user = argv[2];
    const char *pass = argv[3];

    int sock = connectToIMAP(server);
    receiveResponse(sock);
    
    login(sock, user, pass);
    listMailboxes(sock);
    
    // Example mailbox to fetch headers from; adjust as required
    fetchHeaders(sock, "INBOX");
    
    disconnect(sock);

    return EXIT_SUCCESS;
}