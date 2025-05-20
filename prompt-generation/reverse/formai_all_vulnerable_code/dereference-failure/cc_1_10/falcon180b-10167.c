//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function prototypes
void error_handling(char *message);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port_number> <destination_address>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *destination_address = argv[2];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Resolve destination address
    struct hostent *host = gethostbyname(destination_address);
    if (host == NULL) {
        error_handling("gethostbyname failed");
    }

    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    // Connect to destination address
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    printf("Connected to %s:%d\n", destination_address, port);

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        send(sock, buffer, bytes_received, 0);
    }

    close(sock);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}