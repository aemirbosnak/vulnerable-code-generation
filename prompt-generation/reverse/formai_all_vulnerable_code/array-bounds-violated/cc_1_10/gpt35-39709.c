//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serverAddr;
    socklen_t addrSize;
    char *ipAddr = "192.168.1.1";
    int port = 80;
    char *host = "www.example.com";
    char request[MAX_BUF_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        return -1;
    }

    // Set up server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Unable to connect");
        return -1;
    }

    // Create HTTP request
    sprintf(request, "GET / HTTP/1.1\r\n");
    sprintf(request, "%sHost: %s\r\n", request, host);
    sprintf(request, "%sConnection: close\r\n", request);
    sprintf(request, "%s\r\n", request);

    // Send request to server
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Unable to send request");
        return -1;
    }

    // Receive response from server
    char response[MAX_BUF_SIZE];
    int numBytes;
    while ((numBytes = recv(sock, response, MAX_BUF_SIZE - 1, 0)) > 0) {
        response[numBytes] = '\0';
        printf("%s", response);
    }

    // Close socket
    close(sock);

    return 0;
}