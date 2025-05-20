//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *data = malloc(MAX_DATA_SIZE);
    int data_size = 0;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    if (argc!= 2) {
        printf("Usage:./speedtest <file_to_upload>\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    while ((data_size = fread(data, 1, MAX_DATA_SIZE, file)) > 0) {
        send(sock, data, data_size, 0);
        usleep(100000); // 100ms delay
    }

    close(file);
    close(sock);

    start_time = difftime(time(NULL), time(NULL));
    end_time = start_time + (double)file_size / (double)data_size * elapsed_time;

    speed = (double)file_size / (end_time - start_time);

    printf("File size: %d bytes\n", file_size);
    printf("Transfer time: %.2f seconds\n", elapsed_time);
    printf("Speed: %.2f bytes/second\n", speed);

    return 0;
}