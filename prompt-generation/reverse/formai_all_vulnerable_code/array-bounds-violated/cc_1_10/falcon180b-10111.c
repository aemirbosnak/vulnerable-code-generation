//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 1024
#define MAX_PORT 65535

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port_range>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port)!= 2) {
        if (sscanf(port_range, "%d", &start_port)!= 1) {
            error("Invalid port range");
        }
        end_port = start_port;
    }

    if (start_port < 1 || start_port > MAX_PORT || end_port < 1 || end_port > MAX_PORT || end_port < start_port) {
        error("Invalid port range");
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    server_addr.sin_port = htons(start_port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        close(sock);
        error("connect");
    }

    char buf[BUFSIZE];
    sprintf(buf, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);

    send(sock, buf, strlen(buf), 0);

    int bytes_received = 0;
    while ((bytes_received = recv(sock, buf, BUFSIZE, 0)) > 0) {
        buf[bytes_received] = '\0';
        printf("%s", buf);
    }

    close(sock);

    return 0;
}