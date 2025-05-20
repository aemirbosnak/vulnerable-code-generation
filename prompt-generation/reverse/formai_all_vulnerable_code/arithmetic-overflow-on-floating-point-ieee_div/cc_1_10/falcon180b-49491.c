//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_LEN 256
#define MAX_PORT_LEN 6
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {

    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <data_size>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOST_LEN];
    strcpy(hostname, argv[1]);

    char port[MAX_PORT_LEN];
    strcpy(port, argv[2]);

    int data_size = atoi(argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char send_data[MAX_DATA_LEN];
    memset(send_data, 'A', data_size);

    send(sock, send_data, data_size, 0);

    char recv_data[MAX_DATA_LEN];
    int bytes_received = recv(sock, recv_data, MAX_DATA_LEN, 0);

    double speed = (double)bytes_received / (double)data_size;

    printf("Speed test results:\n");
    printf("Bytes sent: %d\n", bytes_received);
    printf("Speed: %.2f bytes/s\n", speed);

    close(sock);
    return 0;
}