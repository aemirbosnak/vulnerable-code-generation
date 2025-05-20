//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void print_usage(char *progname) {
    fprintf(stderr, "Usage: %s <ip_address> <port_range>\n", progname);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;
    char *token = strtok(port_range, "-");
    start_port = atoi(token);
    token = strtok(NULL, "-");
    end_port = atoi(token);

    if (end_port < start_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(start_port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", ip_address);

    send(sock, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("recv");
        exit(1);
    }

    close(sock);

    printf("Port %d is open\n", start_port);

    return 0;
}