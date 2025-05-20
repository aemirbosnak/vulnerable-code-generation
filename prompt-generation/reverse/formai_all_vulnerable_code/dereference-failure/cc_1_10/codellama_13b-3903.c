//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
// imap_client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    const char *server = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the address struct
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the IMAP command
    char *command = "A001 CAPABILITY\r\n";
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response
    char buffer[1024];
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("%s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}