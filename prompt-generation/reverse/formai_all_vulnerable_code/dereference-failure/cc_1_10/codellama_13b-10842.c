//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: energetic
/*
 * Unique C Port Scanner example program
 *
 * This program is written in an energetic style to showcase
 * the power of C programming language.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check if the hostname and port number are provided as arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname and port number from the arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket: %s\n", strerror(sock));
        return 1;
    }

    // Get the IP address of the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error getting IP address of %s: %s\n", hostname, hstrerror(h_errno));
        return 1;
    }

    // Set up the sockaddr_in struct for the destination
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = *((unsigned long *)host->h_addr);

    // Connect to the destination
    int res = connect(sock, (struct sockaddr *)&dest, sizeof(dest));
    if (res < 0) {
        printf("Error connecting to %s:%d: %s\n", hostname, port, strerror(res));
        return 1;
    }

    // Print a message indicating that the connection was successful
    printf("Connected to %s:%d\n", hostname, port);

    // Close the socket
    close(sock);

    return 0;
}