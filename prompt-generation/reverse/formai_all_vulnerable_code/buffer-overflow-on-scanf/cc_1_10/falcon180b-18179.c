//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct hostent *host;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Prompt user for hostname
    printf("Enter hostname: ");
    scanf("%s", buffer);

    // Resolve hostname to IP address
    host = gethostbyname(buffer);

    // Check if hostname was resolved successfully
    if (host == NULL) {
        printf("Hostname not found.\n");
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket was created successfully
    if (sock == -1) {
        printf("Socket creation failed.\n");
        return 1;
    }

    // Connect to host
    if (connect(sock, (struct sockaddr *)host->h_addr, host->h_length) == -1) {
        printf("Connection failed.\n");
        return 1;
    }

    // Ping host
    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        // Check if host is still reachable
        if (bytes_received <= 0) {
            printf("Host not reachable.\n");
            break;
        }

        // Print response
        printf("%s", buffer);
    }

    // Close socket
    close(sock);

    return 0;
}