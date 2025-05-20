//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 5353

int main() {
    int sock, count = 0;
    struct sockaddr_in server, client;
    char ip[INET_ADDRSTRLEN], buffer[1024];

    // Creating a socket
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        perror("Socket creation error.");
        exit(EXIT_FAILURE);
    }
    
    // Enable SO_REUSEADDR to allow multiple instances of the program to run on same host
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt error.");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));

    // Server details
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to the server
    if (bind(sock, (const struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind error.");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int len, n;

        // Receive message from the client
        n = recvfrom(sock, (char *) buffer, 1024, MSG_WAITALL, ( struct sockaddr *) &client, &len);
        buffer[n] = '\0';

        // Extract and print client IP
        inet_ntop(AF_INET, &(client.sin_addr), ip, INET_ADDRSTRLEN);
        printf("Client IP Address: %s\n", ip);

        // Display the message received from the client
        printf("Message Received [%d]: %s\n", ++count, buffer);
    }

    close(sock); // Close the socket
    return 0;
}