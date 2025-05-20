//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: happy
// Happy C Port Scanner
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Get host and port from command line arguments
    char *host = argv[1];
    int port = 0;
    char *port_str = strchr(host, ':');
    if (port_str != NULL) {
        *port_str = '\0';
        port = atoi(port_str + 1);
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Setup address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the host
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Print the banner
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Banner: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}