//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define HTTP_PORT 80
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    // Welcome message
    printf("\nWelcome to Simple HTTP Proxy example program!\n\n");

    int clientSocket, serverSocket, i, readBytes;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serverAddr, clientAddr;

    // Verify user entered correct command line arguments
    if (argc < 4) {
        printf("Usage: %s <local_port> <dest_ip> <dest_port>\n", argv[0]);
        return 0;
    }

    // Parse command line arguments
    int localPort = atoi(argv[1]);
    char *destIp = argv[2];
    int destPort = atoi(argv[3]);

    // Create client socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Could not create socket: %s\n", strerror(errno));
        return 0;
    }

    // Bind client socket to local port
    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    clientAddr.sin_port = htons(localPort);

    if (bind(clientSocket, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) < 0) {
        printf("Could not bind to port %d: %s\n", localPort, strerror(errno));
        close(clientSocket);
        return 0;
    }

    // Listen for incoming connections
    if (listen(clientSocket, 5) < 0) {
        printf("Could not listen on socket: %s\n", strerror(errno));
        close(clientSocket);
        return 0;
    }

    printf("Listening for incoming connections on port %d...\n\n", localPort);

    while (1) {

        // Accept client connection
        socklen_t clientAddrLength = sizeof(clientAddr);
        int clientDescriptor = accept(clientSocket, (struct sockaddr *)&clientAddr, &clientAddrLength);

        if (clientDescriptor < 0) {
            printf("Could not accept client connection: %s\n", strerror(errno));
            continue;
        }

        printf("Received client connection from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        // Create server socket
        if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Could not create server socket: %s\n", strerror(errno));
            close(clientDescriptor);
            continue;
        }

        // Connect to destination server
        memset(&serverAddr, 0, sizeof(serverAddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(destIp);
        serverAddr.sin_port = htons(destPort);

        if (connect(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            printf("Could not connect to %s:%d: %s\n", destIp, destPort, strerror(errno));
            close(serverSocket);
            close(clientDescriptor);
            continue;
        }

        printf("Connected to destination server %s:%d\n\n", destIp, destPort);

        // Forward HTTP request from client to server
        readBytes = recv(clientDescriptor, buffer, BUFFER_SIZE, 0);

        if (readBytes < 0) {
            printf("Error receiving data from client: %s\n", strerror(errno));
            close(serverSocket);
            close(clientDescriptor);
            continue;
        }

        printf("Received HTTP request from client:\n%s\n", buffer);

        if (send(serverSocket, buffer, strlen(buffer), 0) < 0) {
            printf("Error forwarding request to server: %s\n", strerror(errno));
            close(serverSocket);
            close(clientDescriptor);
            continue;
        }

        // Forward HTTP response from server to client
        while ((readBytes = recv(serverSocket, buffer, BUFFER_SIZE, 0)) > 0) {

            if (send(clientDescriptor, buffer, readBytes, 0) < 0) {
                printf("Error forwarding response to client: %s\n", strerror(errno));
                break;
            }

            memset(buffer, 0, sizeof(buffer));

        }

        close(serverSocket);
        close(clientDescriptor);

        printf("\nDisconnected from client %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        printf("Disconnected from destination server %s:%d\n", destIp, destPort);

    }

    return 0;
}