//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    struct hostent* host = gethostbyname(argv[1]);
    if (host == NULL) {
        herror("gethostbyname");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        close(sock);
        die("connect");
    }

    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "PING %s\r\n", argv[1]);
    send(sock, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        close(sock);
        die("recv");
    }

    response[bytes_received] = '\0';
    printf("Ping response: %s\n", response);

    close(sock);
    return 0;
}