//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 256
#define RESPONSE_SIZE 1024

int main() {
    // Connect to the mail server over TCP
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110); // Use POP3 protocol
    inet_pton(AF_INET, "pop.example.com", &server_address.sin_addr); // Replace with actual server address
    connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Send server greeting
    char response[RESPONSE_SIZE];
    recv(client_socket, response, RESPONSE_SIZE, 0);
    printf("%s", response);

    // Send username
    char command[COMMAND_SIZE];
    printf("Username: ");
    scanf("%s", command);
    strcat(command, "\r\n");
    send(client_socket, command, strlen(command), 0);
    recv(client_socket, response, RESPONSE_SIZE, 0);
    printf("%s", response);

    // Send password
    printf("Password: ");
    scanf("%s", command);
    strcat(command, "\r\n");
    send(client_socket, command, strlen(command), 0);
    recv(client_socket, response, RESPONSE_SIZE, 0);
    printf("%s", response);

    // Send list command to get number of messages
    send(client_socket, "LIST\r\n", strlen("LIST\r\n"), 0);
    recv(client_socket, response, RESPONSE_SIZE, 0);
    printf("%s", response);
    int num_messages = atoi(strchr(response, ' '));

    // Print details of each message
    for (int i = 1; i <= num_messages; i++) {
        // Send RETR command to get message details
        sprintf(command, "RETR %d\r\n", i);
        send(client_socket, command, strlen(command), 0);
        recv(client_socket, response, RESPONSE_SIZE, 0);

        // Parse message and print details
        int content_length;
        char* content;
        char* token = strtok(response, "\r\n");
        while (token != NULL) {
            if (strstr(token, "Content-Length") != NULL) {
                content_length = atoi(strchr(token, ':') + 2);
                content = malloc(content_length + 1);
            } else if (content != NULL) {
                strcat(content, token);
                strcat(content, "\n");
            }
            token = strtok(NULL, "\r\n");
        }
        printf("--- Message %d ---\n%s\n", i, content);
        free(content);
    }

    // Send quit command to end session
    send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(client_socket, response, RESPONSE_SIZE, 0);
    printf("%s", response);

    // Close socket
    close(client_socket);

    return 0;
}