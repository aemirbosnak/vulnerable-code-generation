//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to receive a response from the server
char* recv_response(int socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int n = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        printf("Error receiving response from server.\n");
        exit(EXIT_FAILURE);
    }
    return strdup(buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./pop3client <server IP address> <port>\n");
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0) {
        printf("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    char* response = recv_response(sock);
    printf("%s", response);
    free(response);

    printf("Username: ");
    char username[BUFFER_SIZE];
    scanf("%s", username);

    char command[BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);

    response = recv_response(sock);
    printf("%s", response);
    free(response);

    char password[BUFFER_SIZE];
    printf("Password: ");
    scanf("%s", password);

    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);

    response = recv_response(sock);
    printf("%s", response);
    free(response);

    // List the emails
    sprintf(command, "LIST\r\n");
    send(sock, command, strlen(command), 0);

    response = recv_response(sock);
    printf("%s", response);
    free(response);

    while (1) {
        printf("Enter an email number (or 'quit' to exit): ");
        char input[BUFFER_SIZE];
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        sprintf(command, "RETR %s\r\n", input);
        send(sock, command, strlen(command), 0);

        response = recv_response(sock);
        printf("%s", response);
        free(response);
    }

    printf("Disconnecting...\n");
    sprintf(command, "QUIT\r\n");
    send(sock, command, strlen(command), 0);

    response = recv_response(sock);
    printf("%s", response);
    free(response);

    close(sock);
    return 0;
}