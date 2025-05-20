//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket, n;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen = sizeof(clientAddr);

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(1234);

    // Bind the socket to the address
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(serverSocket, 5) < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening for connections...\n");

    // Accept incoming connection
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
    if (clientSocket < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("Connected to: %s\n", inet_ntoa(clientAddr.sin_addr));

    char buffer[1024];
    int len = 0;
    while (1) {
        // Receive data from client
        n = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("Error receiving data");
            exit(EXIT_FAILURE);
        }
        len += n;

        // Check for malicious activity
        if (strstr(buffer, "attack") || strstr(buffer, "malicious")) {
            printf("Detected malicious activity! Closing connection...\n");
            close(clientSocket);
            break;
        }

        // Send data back to client
        send(clientSocket, buffer, len, 0);
    }

    close(clientSocket);
    close(serverSocket);
    return 0;
}