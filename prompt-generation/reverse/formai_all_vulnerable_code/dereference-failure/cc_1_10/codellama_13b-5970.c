//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
// POP3 client in a futuristic style
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, n;
    struct sockaddr_in server;
    struct hostent *host;
    char buf[MAX_MSG_SIZE];

    // Check command-line arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <username>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Look up the server's hostname
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the username
    printf("Sending username...\n");
    n = send(sock, argv[2], strlen(argv[2]), 0);
    if (n < 0) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    printf("Receiving response...\n");
    n = recv(sock, buf, MAX_MSG_SIZE, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("Response: %s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}