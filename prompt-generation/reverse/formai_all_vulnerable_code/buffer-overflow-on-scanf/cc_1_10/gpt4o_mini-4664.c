//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void clear_buffer(char *buffer, int size) {
    memset(buffer, 0, size);
}

void pop3_command(int socket, const char *cmd, char *response) {
    send(socket, cmd, strlen(cmd), 0);
    recv(socket, response, BUFFER_SIZE - 1, 0);
}

void process_response(char *response) {
    printf("%s", response);
}

int main() {
    const char *server_ip = "127.0.0.1"; // Change to your POP3 server IP
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return EXIT_FAILURE;
    }

    recv(sock, buffer, BUFFER_SIZE - 1, 0);
    process_response(buffer);
    
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    char command[BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", username);
    pop3_command(sock, command, buffer);
    process_response(buffer);

    sprintf(command, "PASS %s\r\n", password);
    pop3_command(sock, command, buffer);
    process_response(buffer);
    
    sprintf(command, "LIST\r\n");
    pop3_command(sock, command, buffer);
    process_response(buffer);
    
    int message_number;
    printf("Enter the message number you want to read: ");
    scanf("%d", &message_number);

    sprintf(command, "RETR %d\r\n", message_number);
    pop3_command(sock, command, buffer);
    process_response(buffer);
    
    sprintf(command, "QUIT\r\n");
    pop3_command(sock, command, buffer);
    process_response(buffer);
    
    close(sock);
    return EXIT_SUCCESS;
}