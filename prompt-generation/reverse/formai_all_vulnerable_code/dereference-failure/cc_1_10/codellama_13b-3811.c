//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
/*
 * pop3_client.c
 *
 * A POP3 client example program in C
 *
 * Usage:
 *      ./pop3_client <hostname> <port> <username> <password>
 *
 * Example:
 *      ./pop3_client pop.gmail.com 995 username password
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_SIZE 128
#define MAX_ARGUMENT_SIZE 128
#define MAX_ARGUMENTS 10

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    // Parse the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the USER command
    char command[MAX_COMMAND_SIZE];
    sprintf(command, "USER %s", username);
    send(sock, command, strlen(command), 0);

    // Read the response
    char response[MAX_LINE_SIZE];
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Send the PASS command
    sprintf(command, "PASS %s", password);
    send(sock, command, strlen(command), 0);

    // Read the response
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Send the STAT command
    sprintf(command, "STAT");
    send(sock, command, strlen(command), 0);

    // Read the response
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Send the LIST command
    sprintf(command, "LIST");
    send(sock, command, strlen(command), 0);

    // Read the response
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Send the RETR command for the first message
    sprintf(command, "RETR 1");
    send(sock, command, strlen(command), 0);

    // Read the response
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Send the DELE command for the first message
    sprintf(command, "DELE 1");
    send(sock, command, strlen(command), 0);

    // Read the response
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Send the NOOP command
    sprintf(command, "NOOP");
    send(sock, command, strlen(command), 0);

    // Read the response
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Send the QUIT command
    sprintf(command, "QUIT");
    send(sock, command, strlen(command), 0);

    // Read the response
    read(sock, response, MAX_LINE_SIZE);
    printf("%s", response);

    // Close the socket
    close(sock);

    return 0;
}