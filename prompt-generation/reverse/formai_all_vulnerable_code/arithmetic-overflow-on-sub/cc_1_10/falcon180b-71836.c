//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10
#define FILE_NAME "test_file.txt"

int main() {
    int sock, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    FILE *fp;
    clock_t start_time, end_time;
    double total_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    start_time = clock();

    for (int i = 0; i < NUM_REQUESTS; i++) {
        fseek(fp, 0, SEEK_SET);
        n = send(sock, buffer, BUFFER_SIZE, 0);
    }

    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    fprintf(stdout, "Total time: %.2f seconds\n", total_time);

    fclose(fp);
    close(sock);

    return 0;
}