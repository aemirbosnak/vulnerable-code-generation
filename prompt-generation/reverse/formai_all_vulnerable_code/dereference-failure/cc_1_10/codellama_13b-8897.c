//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: portable
/*
 * POP3 Client Example Program
 *
 * This program demonstrates how to build a POP3 client using the POP3 protocol
 * in a portable style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_BUFSIZE 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse command-line arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Send the POP3 greeting message
    char greeting[POP3_BUFSIZE];
    if (read(sock, greeting, POP3_BUFSIZE) <= 0) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }
    printf("POP3 Greeting: %s\n", greeting);

    // Send the POP3 username
    char username[POP3_BUFSIZE];
    printf("Enter POP3 username: ");
    fgets(username, POP3_BUFSIZE, stdin);
    write(sock, username, strlen(username));

    // Send the POP3 password
    char password[POP3_BUFSIZE];
    printf("Enter POP3 password: ");
    fgets(password, POP3_BUFSIZE, stdin);
    write(sock, password, strlen(password));

    // Get the POP3 message count
    char msg_count[POP3_BUFSIZE];
    if (read(sock, msg_count, POP3_BUFSIZE) <= 0) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }
    printf("POP3 Message Count: %s\n", msg_count);

    // Get the POP3 message list
    char msg_list[POP3_BUFSIZE];
    if (read(sock, msg_list, POP3_BUFSIZE) <= 0) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }
    printf("POP3 Message List: %s\n", msg_list);

    // Close the socket
    close(sock);

    return 0;
}