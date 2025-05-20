//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.example.com"

void send_packet(int sock, char* data, int size) {
    int sent = 0;
    while (sent < size) {
        int result = send(sock, data + sent, size - sent, 0);
        if (result <= 0) {
            printf("Error sending data.\n");
            exit(1);
        }
        sent += result;
    }
}

void receive_packet(int sock, char* data, int size) {
    int received = 0;
    while (received < size) {
        int result = recv(sock, data + received, size - received, 0);
        if (result <= 0) {
            printf("Error receiving data.\n");
            exit(1);
        }
        received += result;
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    char* send_buffer = malloc(MAX_PACKET_SIZE);
    char* receive_buffer = malloc(MAX_PACKET_SIZE);

    int packet_size = 64;
    int num_packets = 10;

    double start_time = time(NULL);

    for (int i = 0; i < num_packets; i++) {
        memset(send_buffer, 'A' + i % 26, packet_size);
        send_packet(sock, send_buffer, packet_size);
        receive_packet(sock, receive_buffer, packet_size);
    }

    double end_time = time(NULL);
    double elapsed_time = end_time - start_time;

    double total_bytes = num_packets * packet_size;
    double bandwidth = total_bytes / elapsed_time;

    printf("Bandwidth: %.2f kB/s\n", bandwidth / 1024);

    close(sock);
    free(send_buffer);
    free(receive_buffer);

    return 0;
}