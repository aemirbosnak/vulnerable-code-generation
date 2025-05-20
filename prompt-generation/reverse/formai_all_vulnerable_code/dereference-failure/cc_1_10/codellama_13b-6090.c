//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: automated
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if correct number of arguments were provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <user> <pass>\n", argv[0]);
        return 1;
    }

    // Get server, user, and password from arguments
    char *server = argv[1];
    char *user = argv[2];
    char *pass = argv[3];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Initialize the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the USER command
    char cmd[100];
    sprintf(cmd, "USER %s\r\n", user);
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the PASS command
    sprintf(cmd, "PASS %s\r\n", pass);
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the STAT command
    sprintf(cmd, "STAT\r\n");
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read the response from the server
    char buf[MAX_MSG_SIZE];
    if (recv(sock, buf, MAX_MSG_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("Server response: %s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}