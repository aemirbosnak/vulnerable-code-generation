//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 8192

int main(int argc, char *argv[]) {
    int proxyFd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxyFd == -1) {
        perror("Socket creation failed!");
        exit(1);
    }

    if (argc < 3) {
        printf("Usage: %s <proxy-port> <server-ip> <server-port>\n", argv[0]);
        exit(0);
    }

    // Set up the proxy address
    struct sockaddr_in proxyAddr;
    proxyAddr.sin_family = AF_INET;
    proxyAddr.sin_port = htons(atoi(argv[1]));
    proxyAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the proxy address and port to the socket
    if (bind(proxyFd, (struct sockaddr *) &proxyAddr, sizeof(proxyAddr)) < 0) {
        perror("Bind failed!");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(proxyFd, 10) < 0) {
        perror("Listen failed!");
        exit(1);
    }

    while (1) {
        int clientFd;
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);

        // Accept incoming client connection
        clientFd = accept(proxyFd, (struct sockaddr *) &clientAddr, &clientAddrLen);
        if (clientFd == -1) {
            perror("Accept failed!");
            continue;
        }

        printf("Connection established! Client address: %s:%d\n", inet_ntoa(clientAddr.sin_addr),
               ntohs(clientAddr.sin_port));

        // Set up the server address
        struct sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(atoi(argv[3]));
        serverAddr.sin_addr.s_addr = inet_addr(argv[2]);

        // Connect to the server
        int serverFd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverFd == -1) {
            perror("Socket creation failed!");
            continue;
        }

        if (connect(serverFd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
            perror("Connection to server failed!");
            continue;
        }

        printf("Connection to server established!\n");

        // Forward data between client and server
        char buffer[BUFFER_SIZE];
        int bytesRead, bytesWritten;

        while ((bytesRead = read(clientFd, buffer, sizeof(buffer))) > 0) {
            bytesWritten = write(serverFd, buffer, bytesRead);
            if (bytesWritten < 0) {
                perror("Write to server failed!");
                break;
            }

            bytesRead = read(serverFd, buffer, sizeof(buffer));
            if (bytesRead < 0) {
                perror("Read from server failed!");
                break;
            }

            bytesWritten = write(clientFd, buffer, bytesRead);
            if (bytesWritten < 0) {
                perror("Write to client failed!");
                break;
            }
        }

        // Close the connection
        close(clientFd);
        close(serverFd);
        printf("Connection closed!\n");
    }

    return 0;
}