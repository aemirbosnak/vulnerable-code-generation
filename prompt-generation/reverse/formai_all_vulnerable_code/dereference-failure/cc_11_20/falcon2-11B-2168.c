//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024

// Define the port list
const char* portList[] = { "22", "80", "443" };

// Define the number of ports
int numPorts = sizeof(portList) / sizeof(portList[0]);

int main(int argc, char** argv) {
    // Check if port list was provided as an argument
    if (argc > 1) {
        numPorts = argc - 1;
    }

    // Initialize the port list
    char* ports[numPorts];
    for (int i = 0; i < numPorts; i++) {
        ports[i] = strdup(portList[i]);
    }

    // Create a listening socket
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == -1) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    // Prepare the server address struct
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Example port
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(listenSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        return 1;
    }

    // Start listening on the socket
    if (listen(listenSocket, SOMAXCONN) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        return 1;
    }

    // Accept incoming connections
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(listenSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket == -1) {
        fprintf(stderr, "Error accepting connection\n");
        return 1;
    }

    // Check if the connection is allowed
    int port = ntohs(clientAddr.sin_port);
    if (port!= 8080 && port < 1024) {
        close(clientSocket);
        return 1;
    }

    // Read the packet from the client
    char packet[MAX_PACKET_SIZE];
    ssize_t packetSize = recv(clientSocket, packet, MAX_PACKET_SIZE, 0);
    if (packetSize == -1) {
        fprintf(stderr, "Error reading packet\n");
        return 1;
    }

    // Process the packet
    printf("Received packet from %s:%d:\n%s\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), packet);

    // Send a response back to the client
    if (send(clientSocket, "Hello, World!", strlen("Hello, World!"), 0) == -1) {
        fprintf(stderr, "Error sending response\n");
        return 1;
    }

    // Close the client socket
    close(clientSocket);

    return 0;
}