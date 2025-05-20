//FormAI DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    //Create a socket for the server.
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    //Bind the socket to a specific IP and port number.
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error binding socket: %s\n", strerror(errno));
        return -1;
    }

    //Listen for incoming connections.
    if (listen(serverSocket, 1) < 0) {
        printf("Error listening for connections: %s\n", strerror(errno));
        return -1;
    }

    printf("Waiting for connection...\n");

    //Accept incoming connections.
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &clientAddrLen);
    if (clientSocket < 0) {
        printf("Error accepting connection: %s\n", strerror(errno));
        return -1;
    }

    printf("Accepted connection from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

    //Send and receive messages.
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (1) {
        printf("Enter your romantic message:");

        //read message from the user
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';

        //send the message to the client
        if (send(clientSocket, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending message: %s\n", strerror(errno));
            return -1;
        }

        //receive message from the client
        memset(buffer, 0, sizeof(buffer));
        if (recv(clientSocket, buffer, sizeof(buffer), 0) < 0) {
            printf("Error receiving message: %s\n", strerror(errno));
            return -1;
        }

        printf("Message received: %s\n", buffer);

        //exit if message contains "bye"
        if (strstr(buffer, "bye")) {
            printf("Connection closed!\n");
            break;
        }
    }

    //Close the sockets.
    close(clientSocket);
    close(serverSocket);

    return 0;
}