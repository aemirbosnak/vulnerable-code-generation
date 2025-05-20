//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_size = 0;
    int bytes_received = 0;
    double start_time = 0.0, end_time = 0.0;
    double elapsed_time = 0.0;
    double speed = 0.0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    start_time = difftime(time(0), time(0));
    bytes_received = recv(sock, data, MAX_DATA_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Error: Could not receive data from server\n");
        exit(1);
    }

    data_size = bytes_received;
    end_time = difftime(time(0), time(0));
    elapsed_time = end_time - start_time;
    speed = (double)data_size / elapsed_time;

    printf("Data received: %d bytes\n", data_size);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Speed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}