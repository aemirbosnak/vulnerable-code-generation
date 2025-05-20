//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_DATA_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    int total_bytes_received = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        printf("Invalid server IP address\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = difftime(time(NULL), 0);

    while (1) {
        bytes_received = recv(sock, buffer, MAX_DATA_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    end_time = difftime(time(NULL), 0);
    elapsed_time = end_time - start_time;

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Internet speed: %.2f bytes/second\n", (total_bytes_received / elapsed_time));

    close(sock);
    return 0;
}