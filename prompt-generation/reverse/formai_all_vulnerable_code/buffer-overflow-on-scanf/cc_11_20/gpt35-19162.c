//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_LENGTH 1024 // Maximum length of string sent or received

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <server IP> <server port>\n", argv[0]);
        return 1;
    }

    int client_socket;
    struct sockaddr_in server_address;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Creating socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2])); // Port number
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Connecting to server");
        exit(1);
    }

    printf("Successfully connected to server!\n");

    char response[MAX_LENGTH + 1];
    memset(response, 0, sizeof(response)); // Clear response buffer

    if (recv(client_socket, response, MAX_LENGTH, 0) < 0) {
        perror("Receiving data");
        exit(1);
    }

    printf("%s\n", response);

    // Send authentication information
    char username[MAX_LENGTH + 1], password[MAX_LENGTH + 1];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    char auth[MAX_LENGTH + 1];
    snprintf(auth, sizeof(auth), "USER %s\r\nPASS %s\r\n", username, password);

    if (send(client_socket, auth, strlen(auth), 0) < 0) {
        perror("Sending authentication info");
        exit(1);
    }

    memset(response, 0, sizeof(response));
    if (recv(client_socket, response, MAX_LENGTH, 0) < 0) {
        perror("Receiving data");
        exit(1);
    }

    printf("%s\n", response);

    // Send request for number of messages
    if (send(client_socket, "STAT\r\n", strlen("STAT\r\n"), 0) < 0) {
        perror("Sending request for number of messages");
        exit(1);
    }

    memset(response, 0, sizeof(response));
    if (recv(client_socket, response, MAX_LENGTH, 0) < 0) {
        perror("Receiving data");
        exit(1);
    }

    printf("%s\n", response);

    // Parse number of messages
    char *ptr = strtok(response, " ");
    int num_messages = atoi(strtok(NULL, " "));

    printf("Number of messages: %d\n", num_messages);

    // Send request for first message
    if (num_messages > 0) {
        if (send(client_socket, "RETR 1\r\n", strlen("RETR 1\r\n"), 0) < 0) {
            perror("Sending request for first message");
            exit(1);
        }

        memset(response, 0, sizeof(response));
        if (recv(client_socket, response, MAX_LENGTH, 0) < 0) {
            perror("Receiving data");
            exit(1);
        }

        printf("%s\n", response);
    }

    // Send quit command
    if (send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("Sending quit command");
        exit(1);
    }

    close(client_socket);

    return 0;
}