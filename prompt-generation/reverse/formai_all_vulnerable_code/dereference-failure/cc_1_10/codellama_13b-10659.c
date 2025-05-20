//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    // Check for correct usage
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    // Parse the input arguments
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Set up the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the socket
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Get the status of the socket
    int status = 0;
    socklen_t len = sizeof(status);
    if (getsockopt(sock, SOL_SOCKET, SO_ERROR, &status, &len) == -1) {
        perror("getsockopt");
        return 1;
    }

    // Check the status of the socket
    if (status != 0) {
        fprintf(stderr, "Socket is not open\n");
        return 1;
    }

    // Print the status of the socket
    printf("Socket is open\n");

    // Close the socket
    close(sock);

    return 0;
}