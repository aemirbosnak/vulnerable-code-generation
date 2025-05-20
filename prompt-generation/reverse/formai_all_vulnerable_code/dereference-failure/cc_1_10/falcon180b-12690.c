//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5 // in seconds

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port_number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char send_data[MAX_DATA_SIZE] = "PING";
    send(sock, send_data, strlen(send_data), 0);

    char recv_data[MAX_DATA_SIZE];
    int bytes_received = recv(sock, recv_data, MAX_DATA_SIZE, 0);
    if (bytes_received <= 0) {
        print_error("recv");
    }

    recv_data[bytes_received] = '\0';
    printf("Received: %s\n", recv_data);

    close(sock);
    return 0;
}