//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
// Ada Lovelace Network Ping Test Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 65535
#define MAX_DELAY_TIME 5000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct hostent *host;
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr = *((struct in_addr *)host->h_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        return 1;
    }

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = MAX_DELAY_TIME;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        return 1;
    }

    char buffer[MAX_PACKET_SIZE];
    int n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    printf("Received %d bytes from %s:%d\n", n, argv[1], 80);

    close(sock);

    return 0;
}