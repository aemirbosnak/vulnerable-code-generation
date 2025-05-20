//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10
#define SERVER "speedtest.net"
#define PORT "80"

void get_server_ip(char *server, char *ip) {
    struct hostent *host;
    host = gethostbyname(server);
    strcpy(ip, inet_ntoa(*(struct in_addr *)host->h_addr));
}

double calculate_speed(double total_bytes, double elapsed_time) {
    return total_bytes / elapsed_time;
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char ip[16];
    double total_bytes = 0;
    double start_time, end_time;
    int i, bytes_received;

    get_server_ip(SERVER, ip);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    for (i = 0; i < NUM_REQUESTS; i++) {
        start_time = clock();
        send(sock, "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n"), 0);

        while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
            total_bytes += bytes_received;
        }

        end_time = clock();
        close(sock);
    }

    printf("Internet Speed: %.2f MB/s\n", calculate_speed(total_bytes, ((double)NUM_REQUESTS * CLOCKS_PER_SEC) / (end_time - start_time)));

    return 0;
}