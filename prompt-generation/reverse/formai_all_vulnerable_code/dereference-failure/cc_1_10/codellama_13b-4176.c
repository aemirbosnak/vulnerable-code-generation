//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
/*
 * Network Ping Test Example Program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 65535
#define TIMEOUT_SECS 2

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *host_name = "www.google.com";
    char buffer[MAX_PACKET_SIZE];
    int bytes_received;

    if (argc > 1) {
        host_name = argv[1];
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Get the address of the server
    host = gethostbyname(host_name);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a request to the server
    const char *request = "GET / HTTP/1.0\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    bytes_received = recv(sock, buffer, MAX_PACKET_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }

    // Print the response
    printf("Received %d bytes from %s\n", bytes_received, host_name);
    printf("%s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}