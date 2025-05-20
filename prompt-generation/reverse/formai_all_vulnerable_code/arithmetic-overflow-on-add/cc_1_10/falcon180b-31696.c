//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 80
#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10
#define TIMEOUT 5

char *make_request(int sock) {
    char request[1024];
    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER);
    send(sock, request, strlen(request), 0);
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }
    buffer[bytes_received] = '\0';
    return strdup(buffer);
}

double get_speed(int sock, int num_requests) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    for (int i = 0; i < num_requests; i++) {
        char *response = make_request(sock);
        free(response);
    }
    gettimeofday(&end, NULL);
    return (double) (end.tv_sec - start.tv_sec) + (double) (end.tv_usec - start.tv_usec) / 1000000.0;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 2;
    }

    double speed = get_speed(sock, NUM_REQUESTS);
    printf("Internet speed: %.2f kbps\n", speed);

    close(sock);
    return 0;
}