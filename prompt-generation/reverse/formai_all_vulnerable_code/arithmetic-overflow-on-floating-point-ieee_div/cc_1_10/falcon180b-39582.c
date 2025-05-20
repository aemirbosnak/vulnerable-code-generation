//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 2048
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

void print_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *response = malloc(MAX_RESPONSE_SIZE);
    int response_size = 0;
    double start_time, end_time;
    double elapsed_time;
    int bytes_received = 0;
    double speed = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        print_error("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    start_time = difftime(time(NULL), time(NULL));
    send(sock, argv[1], strlen(argv[1]), 0);
    response_size = recv(sock, response, MAX_RESPONSE_SIZE, 0);
    end_time = difftime(time(NULL), time(NULL));

    elapsed_time = end_time - start_time;
    bytes_received = response_size;
    speed = (double)bytes_received / elapsed_time;

    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Bytes received: %d\n", bytes_received);
    printf("Speed: %.2f bytes/second\n", speed);

    close(sock);
    free(response);

    return 0;
}