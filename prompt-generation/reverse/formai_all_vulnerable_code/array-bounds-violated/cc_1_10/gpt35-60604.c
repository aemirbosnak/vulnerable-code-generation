//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
#include <stdio.h>          // Standard input/output functions
#include <stdlib.h>         // Standard library functions
#include <string.h>         // String functions
#include <unistd.h>         // UNIX standard function definitions
#include <sys/socket.h>     // Socket functions
#include <netinet/in.h>     // Internet address structures
#include <arpa/inet.h>      // Functions for returning the system's IP address

#define PORT 8080           // Default port number
#define MAXLINE 1024        // Maximum length of a message

int main(int argc, char const *argv[])
{
    int sockfd;             // Socket descriptor
    char buffer[MAXLINE];   // Buffer for incoming messages
    struct sockaddr_in servaddr, cliaddr;    // Server and client address structures

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Server address information
    servaddr.sin_family = AF_INET;      // IPv4 protocol
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    int len, n;
    len = sizeof(cliaddr);  // Size of client address structure

    while (1) {             // Keep listening for incoming messages

        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';   // Add null terminator to received message
        printf("Message Received: %s\n", buffer);

        // Send uppercase converted message back to client
        int i;
        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = buffer[i] - 32;     // Convert to uppercase
            }
        }
        sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
        printf("Message Sent: %s\n", buffer);
    }

    return 0;
}