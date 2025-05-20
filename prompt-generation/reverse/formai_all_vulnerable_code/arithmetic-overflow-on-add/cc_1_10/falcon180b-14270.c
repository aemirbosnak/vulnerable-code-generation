//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define MAX_DATA_SIZE 1024
#define NUM_REQUESTS 10
#define TIME_LIMIT 10

void send_request(int sock) {
    char request[MAX_DATA_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n");
    send(sock, request, strlen(request), 0);
}

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[MAX_DATA_SIZE];
    clock_t start_time, end_time;
    double cpu_time_used;
    int num_bytes, total_bytes = 0;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("www.google.com");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    start_time = clock();
    for (int i = 0; i < NUM_REQUESTS; i++) {
        send_request(sock);
        num_bytes = recv(sock, buffer, MAX_DATA_SIZE, 0);
        total_bytes += num_bytes;
    }
    end_time = clock();

    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Total bytes received: %d\n", total_bytes);
    printf("Time taken: %.2f seconds\n", cpu_time_used);
    printf("Internet speed: %.2f bytes/second\n", (double) total_bytes / cpu_time_used);

    close(sock);
    return 0;
}