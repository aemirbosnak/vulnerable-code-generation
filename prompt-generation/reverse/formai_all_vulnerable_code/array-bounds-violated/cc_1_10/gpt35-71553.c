//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF_SIZE 65536
#define PORT 8888

int main(int argc, char** argv) {
    
    // Create a UDP socket
    int sockfd;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    char buffer[MAX_BUF_SIZE] = {0};
    int len = sizeof(clientAddr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

    // Fill server information
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    while (1) {
        // Receive data from client
        int n = recvfrom(sockfd, (char *) buffer, MAX_BUF_SIZE, MSG_WAITALL, (struct sockaddr *) &clientAddr, &len);
        buffer[n] = '\0';

        // Check for error
        if (n < 0) {
            perror("Error receiving data");
            return -1;
        }

        // Print received data
        printf("Received message from %s:%d : %s\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), buffer);
    }

    close(sockfd);

    return 0;
}