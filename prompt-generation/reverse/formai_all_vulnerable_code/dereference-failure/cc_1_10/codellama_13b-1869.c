//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
/*
 * Building a POP3 Client
 * in a surrealist style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send username and password
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "USER %s\r\n", argv[3]);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }
    sprintf(buffer, "PASS %s\r\n", argv[4]);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    // Wait for server response
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print server response
    printf("%s", buffer);

    // Close socket
    close(sock);

    return 0;
}