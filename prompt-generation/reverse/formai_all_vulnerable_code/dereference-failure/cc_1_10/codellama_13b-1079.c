//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
/*
 * Building a IMAP Client in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 143
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *server_name = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *command = argv[4];
    char buf[BUF_SIZE];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_name);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the username and password
    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    // Send the command
    send(sock, command, strlen(command), 0);

    // Receive the response
    recv(sock, buf, BUF_SIZE, 0);
    printf("Response: %s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}