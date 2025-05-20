//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SERVER "speedtest.net"
#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10
#define FILENAME "output.txt"

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    FILE *fp;
    int total_bytes_recvd = 0;
    float avg_speed = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    for (int i = 0; i < NUM_REQUESTS; i++) {
        sprintf(send_buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER);
        send(sock, send_buffer, strlen(send_buffer), 0);

        memset(recv_buffer, 0, BUFFER_SIZE);
        int bytes_recvd = recv(sock, recv_buffer, BUFFER_SIZE, 0);

        if (bytes_recvd <= 0) {
            printf("Error receiving data from server\n");
            exit(1);
        }

        total_bytes_recvd += bytes_recvd;
    }

    close(sock);

    avg_speed = (float)total_bytes_recvd / NUM_REQUESTS;

    fp = fopen(FILENAME, "w");

    if (fp == NULL) {
        printf("Error creating output file\n");
        exit(1);
    }

    fprintf(fp, "Average internet speed: %.2f bytes/sec\n", avg_speed);

    fclose(fp);

    printf("Internet speed test completed. Results saved to %s.\n", FILENAME);

    return 0;
}