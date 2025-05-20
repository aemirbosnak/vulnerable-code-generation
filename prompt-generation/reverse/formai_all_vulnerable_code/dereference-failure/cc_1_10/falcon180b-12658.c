//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct hostent *host = gethostbyname(ip_address);

    if (host == NULL) {
        printf("Invalid IP address\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received == -1) {
            printf("Error receiving data\n");
            close(sock);
            return 1;
        }

        if (bytes_received == 0) {
            printf("Server closed connection\n");
            close(sock);
            return 1;
        }

        printf("Received data: %s\n", buffer);
    }

    close(sock);
    return 0;
}