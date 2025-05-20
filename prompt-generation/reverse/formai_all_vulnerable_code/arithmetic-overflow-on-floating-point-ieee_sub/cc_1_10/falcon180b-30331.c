//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    int total_bytes_received = 0;

    if (argc!= 3) {
        printf("Usage:./speed_test <IP Address> <Duration in seconds>\n");
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
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    time_t start_seconds, end_seconds;
    time(&start_seconds);

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    time(&end_seconds);
    start_time = difftime(start_seconds, 0);
    end_time = difftime(end_seconds, 0);
    elapsed_time = end_time - start_time;

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Data transfer rate: %.2f bytes/second\n", (double)total_bytes_received / elapsed_time);

    close(sock);
    return 0;
}