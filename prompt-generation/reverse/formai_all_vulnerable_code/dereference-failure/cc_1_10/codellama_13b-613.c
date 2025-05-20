//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
/*
 * pop3-client.c
 *
 * A simple POP3 client program in a medieval style.
 *
 * Usage: ./pop3-client <server> <username> <password>
 *
 * Author: [Your Name]
 * Date:   [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    // Get the server and port
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Get the username and password
    char *username = argv[3];
    char *password = argv[4];

    // Create a socket for connecting to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the username and password to the server
    char buf[BUF_SIZE];
    sprintf(buf, "USER %s\r\n", username);
    send(sock, buf, strlen(buf), 0);
    sprintf(buf, "PASS %s\r\n", password);
    send(sock, buf, strlen(buf), 0);

    // Receive the response from the server
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Disconnect from the server
    close(sock);

    return 0;
}