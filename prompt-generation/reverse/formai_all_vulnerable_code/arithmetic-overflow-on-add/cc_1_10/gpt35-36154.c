//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
/*
 * POP3 Client Program
 * The program uses the sockets API and provides functionality to
 * read and delete email messages from a POP3 server.
 * Author : [Your Name]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

int main(int argc, char **argv) {

    char *server_adr = "pop.domain.com"; // POP3 server address
    int port = 110;                       // POP3 service port
    char *username = "username";          // POP3 login username
    char *password = "password";          // POP3 login password
    char buffer[MAX_SIZE];                // Buffer for receiving messages

    // Creating a TCP socket for connecting to the POP3 server
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Failed to create socket.\n");
        exit(1);
    }

    // Setting up the server address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_adr);

    // Connecting to the POP3 server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to the server.\n");
        exit(1);
    }

    // Receiving the server's welcome message
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    // Sending the username to the server
    char msg[MAX_SIZE];
    sprintf(msg, "USER %s\r\n", username);
    send(client_socket, msg, strlen(msg), 0);

    // Receiving the server's response
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    // Sending the password to the server
    sprintf(msg, "PASS %s\r\n", password);
    send(client_socket, msg, strlen(msg), 0);

    // Receiving the server's response
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    // Sending the LIST command to the server
    send(client_socket, "LIST\r\n", strlen("LIST\r\n"), 0);

    // Receiving the server's response
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    // Parsing the number of messages and their sizes
    int num_messages = 0, total_size = 0;
    int sizes[MAX_SIZE];
    sscanf(buffer, "+OK %d", &num_messages);
    for (int i = 0; i < num_messages; i++) {
        scanf("%*s %d", &sizes[i]);
        total_size += sizes[i];
    }

    // Printing the number of messages and their total size
    printf("Number of messages: %d\nTotal size: %d\n", num_messages, total_size);

    // Deleting all messages
    for (int i = 0; i < num_messages; i++) {
        sprintf(msg, "DELE %d\r\n", i+1);
        send(client_socket, msg, strlen(msg), 0);
        recv(client_socket, buffer, MAX_SIZE, 0);
        printf("%s", buffer);
    }

    // Sending the QUIT command
    send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    // Closing the socket
    close(client_socket);

    return 0;
}