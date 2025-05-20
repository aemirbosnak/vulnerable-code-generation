//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_RETRIES 5

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <number of retries>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int retries = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: failed to create socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(7); // Echo port

    int connect_retries = 0;
    while (connect_retries < retries) {
        int connect_result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (connect_result == -1) {
            if (errno == ECONNREFUSED) {
                printf("Host is down.\n");
                exit(1);
            } else if (errno == EINPROGRESS) {
                printf("Connecting...\n");
                fflush(stdout);
            } else {
                printf("Error: failed to connect to host.\n");
                exit(1);
            }
        } else {
            printf("Connected.\n");
            break;
        }
        connect_retries++;
        usleep(100000);
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            if (result == 0) {
                printf("Host is down.\n");
            } else if (errno == ECONNRESET) {
                printf("Connection reset by peer.\n");
            } else {
                printf("Error: failed to receive data.\n");
            }
            exit(1);
        }
        bytes_received += result;
    }

    close(sock);
    printf("Data received successfully.\n");
    return 0;
}