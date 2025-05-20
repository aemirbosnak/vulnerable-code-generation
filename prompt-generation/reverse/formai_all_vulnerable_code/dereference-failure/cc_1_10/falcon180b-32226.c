//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    struct addrinfo hints, *result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        printf("Error resolving %s\n", hostname);
        exit(2);
    }

    int sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(3);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (connect(sock, result->ai_addr, result->ai_addrlen)!= 0) {
        printf("Error connecting to %s\n", hostname);
        close(sock);
        exit(4);
    }

    if (send(sock, "PING", strlen("PING"), 0)!= strlen("PING")) {
        printf("Error sending PING\n");
        close(sock);
        exit(5);
    }

    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            printf("Error receiving response\n");
            close(sock);
            exit(6);
        }
        bytes_received += result;
    }

    close(sock);

    printf("Response from %s:\n%s", hostname, buffer);

    return 0;
}