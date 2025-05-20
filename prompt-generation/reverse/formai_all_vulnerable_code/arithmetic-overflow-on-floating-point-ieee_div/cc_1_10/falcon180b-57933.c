//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        exit(1);
    }

    start_time = difftime(time(NULL), time(NULL));
    bytes_received = 0;

    while (1) {
        bytes_received += recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received >= BUFFER_SIZE) {
            break;
        }
    }

    end_time = difftime(time(NULL), time(NULL));
    elapsed_time = end_time - start_time;
    speed = (double)bytes_received / elapsed_time;

    printf("Download speed: %.2lf bytes/sec\n", speed);

    close(sock);
    return 0;
}