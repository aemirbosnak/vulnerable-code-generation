//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 110

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    send(socket, "\r\n", 2, 0);
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "+OK") != NULL) {
            break;
        }
    }
}

void authenticate(int socket, const char *user, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s", user);
    send_command(socket, command);
    read_response(socket);
    
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(socket, command);
    read_response(socket);
}

void list_messages(int socket) {
    send_command(socket, "LIST");
    read_response(socket);
}

void retrieve_message(int socket, int message_number) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "RETR %d", message_number);
    send_command(socket, command);
    
    int bytes_received;
    char buffer[BUFFER_SIZE];
    
    while ((bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';        
        printf("%s", buffer);
        if (strstr(buffer, ".") != NULL) {  // End of message
            break;
        }
    }
}

void quit_session(int socket) {
    send_command(socket, "QUIT");
    read_response(socket);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server: %s\n", hostname);
    read_response(sock);

    authenticate(sock, username, password);
    list_messages(sock);

    // Retrieve first few messages
    for (int i = 1; i <= 5; i++) {
        printf("Retrieving message %d:\n", i);
        retrieve_message(sock, i);
        printf("\n");
    }

    quit_session(sock);
    close(sock);
    return 0;
}