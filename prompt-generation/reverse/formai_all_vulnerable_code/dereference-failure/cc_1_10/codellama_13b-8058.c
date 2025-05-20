//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
// IMAP client example program in an interoperable style
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define IMAP_PORT 143
#define IMAP_BUF_LEN 1024

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Get host and port from arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send IMAP command
    char cmd[IMAP_BUF_LEN];
    snprintf(cmd, sizeof(cmd), "a001 login %s\r\n", host);
    send(sock, cmd, strlen(cmd), 0);

    // Read response
    char buf[IMAP_BUF_LEN];
    int n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", buf);

    // Close socket
    close(sock);
    return 0;
}