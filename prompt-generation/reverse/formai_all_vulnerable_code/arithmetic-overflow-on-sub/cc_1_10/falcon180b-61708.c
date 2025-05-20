//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define CLIENT_PORT 8081

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char data[MAX_DATA_SIZE];
    int data_size;
    struct timeval start_time, end_time;
    double latency, throughput;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        gettimeofday(&start_time, NULL);
        data_size = recv(client_socket, data, MAX_DATA_SIZE, 0);
        gettimeofday(&end_time, NULL);

        if (data_size <= 0) {
            printf("Client disconnected\n");
            close(client_socket);
            continue;
        }

        latency = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
        throughput = (double)data_size / latency;

        printf("Received %d bytes from client (%s:%d)\n", data_size, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        printf("Latency: %.2f ms\n", latency);
        printf("Throughput: %.2f Mbps\n", throughput);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}