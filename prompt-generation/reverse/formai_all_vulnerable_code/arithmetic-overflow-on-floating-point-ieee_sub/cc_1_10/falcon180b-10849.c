//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sock, bytes_received;
    char buffer[BUFFER_SIZE];
    struct hostent *server;
    struct sockaddr_in server_addr;
    double start_time, end_time, elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    server = gethostbyname("speedtest.net");
    if (server == NULL) {
        error_handling("gethostbyname failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    start_time = difftime(time(NULL), time(NULL));
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    end_time = difftime(time(NULL), time(NULL));

    elapsed_time = end_time - start_time;
    speed = (double)bytes_received / elapsed_time;

    printf("Internet Speed: %.2lf bytes/sec\n", speed);

    close(sock);
    return 0;
}