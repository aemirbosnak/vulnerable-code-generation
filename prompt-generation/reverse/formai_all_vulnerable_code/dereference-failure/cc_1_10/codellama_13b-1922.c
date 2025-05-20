//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: shocked
// Network Ping Test Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check if the hostname was provided as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Create a socket for the ping test
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Convert the hostname to an IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", argv[1]);
        return 1;
    }

    // Create a socket address structure for the host
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the host on port 80
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a ping request to the host
    const char *ping_request = "GET / HTTP/1.0\r\nHost: %s\r\n\r\n";
    char *request = malloc(strlen(ping_request) + strlen(argv[1]) + 1);
    sprintf(request, ping_request, argv[1]);
    send(sock, request, strlen(request), 0);
    free(request);

    // Receive the ping response from the host
    char buffer[1024];
    int bytes = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes < 0) {
        perror("recv");
        return 1;
    }

    // Print the ping response
    printf("Received %d bytes from %s:\n", bytes, argv[1]);
    printf("%s\n", buffer);

    // Clean up and close the socket
    close(sock);

    return 0;
}