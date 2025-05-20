//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main()
{
    // Create a TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to an address and port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept an incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1) {
        perror("accept");
        exit(1);
    }

    // Receive data from the client
    char buf[BUF_SIZE];
    int n;
    while ((n = recv(client_sock, buf, BUF_SIZE, 0)) > 0) {
        // Process the data
        buf[n] = '\0';
        printf("Received: %s\n", buf);

        // Send data back to the client
        if (send(client_sock, buf, n, 0) == -1) {
            perror("send");
            exit(1);
        }
    }

    // Close the client socket
    close(client_sock);

    // Close the server socket
    close(sock);

    return 0;
}