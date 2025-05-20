//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIME_OUT 5

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char send_data[MAX_DATA_SIZE];
    char recv_data[MAX_DATA_SIZE];
    int data_size;
    int err;
    struct timeval start_time, end_time;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(2);
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    err = connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
    if (err == -1) {
        printf("Error connecting to server\n");
        close(sock);
        exit(3);
    }

    strcpy(send_data, "PING");
    data_size = strlen(send_data);

    gettimeofday(&start_time, NULL);

    if (send(sock, send_data, data_size, 0)!= data_size) {
        printf("Error sending data\n");
        close(sock);
        exit(4);
    }

    memset(recv_data, 0, MAX_DATA_SIZE);
    data_size = recv(sock, recv_data, MAX_DATA_SIZE, 0);
    if (data_size <= 0) {
        printf("Error receiving data\n");
        close(sock);
        exit(5);
    }

    gettimeofday(&end_time, NULL);

    close(sock);

    printf("Response: %s\n", recv_data);
    printf("Round trip time: %ld microseconds\n", (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec));

    return 0;
}