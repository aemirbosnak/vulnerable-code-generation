//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s hostname/IP\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: %s is not a valid hostname or IP address\n", argv[1]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7); // Echo port
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to %s\n", argv[1]);
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send(sock, "PING", strlen("PING"), 0);

    int bytes_received = 0;
    int total_bytes_received = 0;
    while (bytes_received > 0) {
        bytes_received = recv(sock, buffer + total_bytes_received, BUFFER_SIZE - total_bytes_received, 0);
        if (bytes_received == -1) {
            printf("Error: Could not receive data\n");
            close(sock);
            return 1;
        }
        total_bytes_received += bytes_received;
        buffer[total_bytes_received] = '\0';
    }

    close(sock);

    printf("Response: %s\n", buffer);

    return 0;
}