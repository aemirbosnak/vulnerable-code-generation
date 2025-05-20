//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: happy
/*
 * Building a POP3 Client in C
 *
 * This program demonstrates how to build a simple POP3 client in C
 * that can connect to a POP3 server and retrieve email messages.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock, n, i, len;
    struct sockaddr_in server_addr;
    char buffer[POP3_BUFSIZE];
    char username[64];
    char password[64];

    /* Get the username and password from the command line */
    if (argc < 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }
    strncpy(username, argv[1], sizeof(username));
    strncpy(password, argv[2], sizeof(password));

    /* Create a socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    /* Set up the server address and connect to the server */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "pop.example.com", &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    /* Send the username and password to the server */
    n = send(sock, username, strlen(username), 0);
    if (n < 0) {
        printf("Error sending username\n");
        return 1;
    }
    n = send(sock, password, strlen(password), 0);
    if (n < 0) {
        printf("Error sending password\n");
        return 1;
    }

    /* Receive the server's response */
    n = recv(sock, buffer, POP3_BUFSIZE, 0);
    if (n < 0) {
        printf("Error receiving server response\n");
        return 1;
    }

    /* Parse the server's response */
    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) == 0) {
        printf("Login successful\n");
    } else {
        printf("Login failed: %s\n", buffer);
        return 1;
    }

    /* Send the LIST command to the server */
    n = send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    if (n < 0) {
        printf("Error sending LIST command\n");
        return 1;
    }

    /* Receive the server's response */
    n = recv(sock, buffer, POP3_BUFSIZE, 0);
    if (n < 0) {
        printf("Error receiving server response\n");
        return 1;
    }

    /* Parse the server's response */
    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) == 0) {
        printf("Received LIST command response: %s\n", buffer);
    } else {
        printf("Error receiving LIST command response: %s\n", buffer);
        return 1;
    }

    /* Send the RETR command to the server */
    n = send(sock, "RETR 1\r\n", strlen("RETR 1\r\n"), 0);
    if (n < 0) {
        printf("Error sending RETR command\n");
        return 1;
    }

    /* Receive the server's response */
    n = recv(sock, buffer, POP3_BUFSIZE, 0);
    if (n < 0) {
        printf("Error receiving server response\n");
        return 1;
    }

    /* Parse the server's response */
    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) == 0) {
        printf("Received RETR command response: %s\n", buffer);
    } else {
        printf("Error receiving RETR command response: %s\n", buffer);
        return 1;
    }

    /* Close the socket */
    close(sock);

    return 0;
}