//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
/*
 * pop3client.c
 *
 * A simple POP3 client example program in a standalone style.
 *
 * Usage: ./pop3client <host> <port> <username> <password>
 *
 * Author: Mahesh Venkitachalam
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024
#define MAX_HOSTNAME_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <host> <port> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the hostname and port from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Get the server IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname(): %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the username and password
    char buf[MAX_BUF_SIZE];
    snprintf(buf, MAX_BUF_SIZE, "USER %s\r\n", username);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    snprintf(buf, MAX_BUF_SIZE, "PASS %s\r\n", password);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Get the server response
    char resp[MAX_BUF_SIZE];
    if (recv(sock, resp, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s\n", resp);

    // Close the socket
    close(sock);

    return 0;
}