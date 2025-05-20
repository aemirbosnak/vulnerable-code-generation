//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 4096
#define POP3_PORT 110
#define POP3_SSL_PORT 995

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    send(socket, "\r\n", 2, 0);
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "-ERR")) {
            break; // End of response
        }
    }
}

int pop3_connect(const char *host, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) error("ERROR opening socket");

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    return sock;
}

void pop3_login(int socket, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(socket, command);
    receive_response(socket);
    
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(socket, command);
    receive_response(socket);
}

void pop3_list_messages(int socket) {
    send_command(socket, "LIST");
    receive_response(socket);
}

void pop3_retrieve_message(int socket, int message_number) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "RETR %d", message_number);
    send_command(socket, command);
    receive_response(socket);
}

void pop3_quit(int socket) {
    send_command(socket, "QUIT");
    receive_response(socket);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int socket = pop3_connect(hostname, POP3_PORT);
    printf("Connected to POP3 server %s\n", hostname);

    receive_response(socket); // Read server greeting
    pop3_login(socket, username, password);
    
    printf("Logged in as %s\n", username);
    pop3_list_messages(socket);
    
    // Retrieve the first message (if available)
    pop3_retrieve_message(socket, 1);
    
    pop3_quit(socket);
    close(socket);
    return 0;
}