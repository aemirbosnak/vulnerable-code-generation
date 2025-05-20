//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX 1024
#define SERVER "speedtest.net"
#define PORT "8080"

int main() {
    int sock, bytes_received;
    char buffer[MAX];
    struct hostent *host;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    host = gethostbyname(SERVER);

    if (host == NULL) {
        printf("Error: Invalid server address\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    while (1) {
        bytes_received = recv(sock, buffer, MAX, 0);

        if (bytes_received <= 0) {
            printf("Error: Connection closed by server\n");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}