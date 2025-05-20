//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    char server_ip[20] = "speedtest.net";
    struct hostent *server;
    int sock;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    int total_bytes_received = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server = gethostbyname(server_ip);
    if(server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = difftime(time(NULL), time(NULL));

    while(1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    end_time = difftime(time(NULL), time(NULL));
    elapsed_time = end_time - start_time;

    double speed = (double)total_bytes_received / elapsed_time;
    printf("Internet speed: %.2lf bytes/second\n", speed);

    close(sock);
    return 0;
}