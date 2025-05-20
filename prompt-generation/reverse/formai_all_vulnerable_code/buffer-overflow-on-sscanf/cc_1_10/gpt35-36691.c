//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main() {

    // Initialize variables
    struct sockaddr_in serverAddr;
    int clientSocket;
    char httpResponse[MAX_BUFFER_SIZE];
    char httpRequest[MAX_BUFFER_SIZE];
    char url[MAX_BUFFER_SIZE];
    char hostname[MAX_BUFFER_SIZE];
    char path[MAX_BUFFER_SIZE];
    int port = 80;

    // Get user input for HTTP request
    printf("Enter the HTTP request URL: ");
    fgets(url, MAX_BUFFER_SIZE, stdin);

    // Parse the URL for hostname and path
    sscanf(url, "http://%[^/]/%s", hostname, path);

    // Get the server IP address from hostname
    struct hostent *host = gethostbyname(hostname);
    char *serverIP = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);

    // Create the socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Set server address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Build HTTP request
    sprintf(httpRequest, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request to the server
    if (send(clientSocket, httpRequest, strlen(httpRequest), 0) < 0) {
        printf("Error: Could not send HTTP request\n");
        return 1;
    }

    // Receive the server's response
    memset(httpResponse, 0, MAX_BUFFER_SIZE);
    if (recv(clientSocket, httpResponse, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: Could not receive HTTP response\n");
        return 1;
    }

    // Display the server's response
    printf("\nHTTP Response:\n%s\n", httpResponse);

    // Close the socket
    close(clientSocket);

    return 0;
}