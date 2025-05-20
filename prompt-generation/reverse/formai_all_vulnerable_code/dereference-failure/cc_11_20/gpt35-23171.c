//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT_NUMBER 8080

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket, portNumber;
    socklen_t clientLength;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serverAddress, clientAddress;

    // check for port number argument
    if (argc < 2) {
        portNumber = DEFAULT_PORT_NUMBER;
    } else {
        portNumber = atoi(argv[1]);
    }

    // create the server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // set server address to listen on all interfaces
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);

    // bind the socket to the server address
    if (bind(serverSocket, (const struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", portNumber);

    // accept incoming connections and handle them
    while (1) {
        clientLength = sizeof(clientAddress);
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientLength);
        if (clientSocket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));

        // receive request from client
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int bytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytesReceived < 0) {
            perror("Error receiving data from client");
            continue;
        }

        printf("Received request from client:\n%s", buffer);

        // create a new socket to communicate with server
        int serverSocket2 = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket2 < 0) {
            perror("Error creating server2 socket");
            exit(EXIT_FAILURE);
        }

        // connect to server
        if (connect(serverSocket2, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
            perror("Error connecting to server");
            exit(EXIT_FAILURE);
        }

        // send request to server
        if (send(serverSocket2, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending data to server");
            exit(EXIT_FAILURE);
        }

        printf("Sent request to server:\n%s", buffer);

        // receive response from server
        int bytesReceived2 = 0;
        do {
            memset(buffer, 0, MAX_BUFFER_SIZE);
            bytesReceived2 = recv(serverSocket2, buffer, MAX_BUFFER_SIZE, 0);
            if (bytesReceived2 < 0) {
                perror("Error receiving data from server");
                break;
            }
            if (bytesReceived2 > 0) {
                // send response back to client
                if (send(clientSocket, buffer, bytesReceived2, 0) < 0) {
                    perror("Error sending data to client");
                    break;
                }
                printf("Received and sent data to client:\n%s", buffer);
            }
        } while (bytesReceived2 > 0);

        close(serverSocket2);
        close(clientSocket);
    }

    close(serverSocket);

    return 0;
}