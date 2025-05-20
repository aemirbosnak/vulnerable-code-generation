//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define DEFAULT_PORT 80  // HTTP port
#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname or IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];

    // Get the IP address of the host
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", host);
        return EXIT_FAILURE;
    }

    // If the hostname was not resolved to an IP addres, report the error and exit
    if (host_info->h_addrtype != AF_INET) {
        fprintf(stderr, "Error: hostname '%s' does not have an IPv4 address\n", host);
        return EXIT_FAILURE;
    }

    // Get the IP address of the host
    char *ip_address = inet_ntoa(*((struct in_addr *) host_info->h_addr_list[0]));

    // Create a socket for sending and receiving data
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: socket");
        return EXIT_FAILURE;
    }

    // Set the timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("Error: setsockopt");
        return EXIT_FAILURE;
    }

    // Connect to the host
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error: connect");
        return EXIT_FAILURE;
    }

    // Send a HTTP request to the host
    char request[] = "GET / HTTP/1.1\r\nHost: "
                     "www.example.com\r\nConnection: close\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Error: send");
        return EXIT_FAILURE;
    }

    // Receive the response from the host
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv");
        return EXIT_FAILURE;
    }

    // If the response is empty, the host is not responding
    if (bytes_received == 0) {
        printf("Host '%s' is not responding\n", host);
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    // Check if the response contains the expected string
    if (strstr(buffer, "HTTP/1.1 200 OK") == NULL) {
        printf("Host '%s' is not responding with the expected content\n", host);
        return EXIT_FAILURE;
    }

    // Print the response from the host
    printf("Response from host '%s':\n%s", host, buffer);

    return EXIT_SUCCESS;
}