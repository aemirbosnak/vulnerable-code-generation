//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_error("Usage:./ping hostname/IP");
    }

    char *hostname = argv[1];
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        print_error("Invalid hostname/IP");
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("Socket creation failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("Connection failed");
    }

    char send_buf[BUF_SIZE] = "GET / HTTP/1.1\r\nHost: ";
    strcat(send_buf, hostname);
    strcat(send_buf, "\r\nConnection: close\r\n\r\n");

    send(sock, send_buf, strlen(send_buf), 0);

    char recv_buf[BUF_SIZE];
    int bytes_recv = recv(sock, recv_buf, BUF_SIZE, 0);
    if (bytes_recv == -1) {
        print_error("Recv failed");
    }

    printf("Response:\n%s\n", recv_buf);

    close(sock);
    return 0;
}