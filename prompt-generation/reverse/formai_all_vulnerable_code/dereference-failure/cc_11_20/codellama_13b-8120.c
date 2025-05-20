//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: lively
/*
 * A POP3 Client program in a lively style
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define POP3_PORT 110
#define BUFSIZE 1024
#define MAX_POP3_COMMANDS 100

typedef struct {
    char *command;
    char *args;
} POP3_COMMAND;

POP3_COMMAND pop3_commands[MAX_POP3_COMMANDS] = {
    { "USER", NULL },
    { "PASS", NULL },
    { "STAT", NULL },
    { "LIST", NULL },
    { "RETR", NULL },
    { "DELE", NULL },
    { "NOOP", NULL },
    { "RSET", NULL },
    { "QUIT", NULL },
};

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Initialize the address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);

    // Convert the server name to a IP address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        return 1;
    }
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Send the username and password
    char buf[BUFSIZE];
    snprintf(buf, sizeof(buf), "%s\r\n", argv[2]);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send() failed");
        return 1;
    }

    // Read the response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv() failed");
        return 1;
    }

    // Check the response
    if (strstr(buf, "+OK") == NULL) {
        fprintf(stderr, "Invalid response: %s\n", buf);
        return 1;
    }

    // Send the commands
    for (int i = 0; i < MAX_POP3_COMMANDS; i++) {
        // Send the command
        snprintf(buf, sizeof(buf), "%s\r\n", pop3_commands[i].command);
        if (send(sock, buf, strlen(buf), 0) < 0) {
            perror("send() failed");
            return 1;
        }

        // Read the response
        if (recv(sock, buf, sizeof(buf), 0) < 0) {
            perror("recv() failed");
            return 1;
        }

        // Check the response
        if (strstr(buf, "+OK") == NULL) {
            fprintf(stderr, "Invalid response: %s\n", buf);
            return 1;
        }
    }

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "%s\r\n", pop3_commands[8].command);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send() failed");
        return 1;
    }

    // Read the response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv() failed");
        return 1;
    }

    // Check the response
    if (strstr(buf, "+OK") == NULL) {
        fprintf(stderr, "Invalid response: %s\n", buf);
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}