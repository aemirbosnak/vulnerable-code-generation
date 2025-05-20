//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: %s <serverip> <port>\n", argv[0]);
        exit(1);
    }

    char *serverIP = argv[1];
    int serverPort = atoi(argv[2]);

    // Create socket to listen for incoming connections
    int proxySocket = socket(AF_INET, SOCK_STREAM, 0);
    if(proxySocket < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Bind the socket to a specific IP and port
    struct sockaddr_in proxyAddr;
    memset(&proxyAddr, 0, sizeof(proxyAddr));
    proxyAddr.sin_family = AF_INET;
    proxyAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxyAddr.sin_port = htons(8080);

    if(bind(proxySocket, (struct sockaddr *) &proxyAddr, sizeof(proxyAddr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(proxySocket, 5) < 0) {
        perror("Failed to listen");
        exit(1);
    }

    printf("Simple HTTP Proxy started on port 8080\n");

    // Accept and process incoming connections
    while(true) {
        struct sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);
        int clientSocket = accept(proxySocket, (struct sockaddr *) &clientAddr, &clientLen);

        if(clientSocket < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Accepted client connection from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        // Read HTTP request from client
        char buffer[BUFSIZE];
        memset(buffer, 0, BUFSIZE);
        if(read(clientSocket, buffer, BUFSIZE) < 0) {
            perror("Failed to read from client socket");
            close(clientSocket);
            continue;
        }

        printf("Received HTTP request from client:\n%s", buffer);

        // Establish connection to server
        int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if(serverSocket < 0) {
            perror("Failed to create server socket");
            close(clientSocket);
            continue;
        }

        struct sockaddr_in serverAddr;
        memset(&serverAddr, 0, sizeof(serverAddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(serverPort);
        if(inet_pton(AF_INET, serverIP, &serverAddr.sin_addr) <= 0) {
            printf("Failed to convert server IP address '%s'\n", serverIP);
            close(clientSocket);
            close(serverSocket);
            continue;
        }

        printf("Connecting to server %s:%d\n", serverIP, serverPort);

        if(connect(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
            perror("Failed to connect to server");
            close(clientSocket);
            close(serverSocket);
            continue;
        }

        // Forward HTTP request to server
        if(write(serverSocket, buffer, strlen(buffer)) < 0) {
            perror("Failed to forward request to server");
            close(clientSocket);
            close(serverSocket);
            continue;
        }

        memset(buffer, 0, BUFSIZE);

        // Receive response from server and forward to client
        while(true) {
            int bytesReceived = read(serverSocket, buffer, BUFSIZE);
            if(bytesReceived < 0) {
                perror("Failed to read response from server");
                break;
            }
            if(bytesReceived == 0) {
                break;
            }
            if(write(clientSocket, buffer, bytesReceived) < 0) {
                perror("Failed to forward response to client");
                break;
            }
            memset(buffer, 0, BUFSIZE);
        }

        printf("Connection closed\n");
        close(clientSocket);
        close(serverSocket);
    }

    return 0;
}