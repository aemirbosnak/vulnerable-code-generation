//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    struct hostent *host;
    struct sockaddr_in server;
    char *hostaddr;

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Unable to resolve hostname %s\n", argv[1]);
        return 1;
    }

    hostaddr = inet_ntoa(*(struct in_addr *)host->h_addr);
    printf("Host address: %s\n", hostaddr);

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    inet_pton(AF_INET, hostaddr, &server.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Could not connect to %s\n", hostaddr);
        return 1;
    }

    printf("Connected to %s\n", hostaddr);

    close(sock);

    return 0;
}