//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 8080

int main() {
    int sock, bytes_received;
    char buffer[1024];
    struct sockaddr_in server_addr;
    double start_time, end_time, total_time;
    int total_bytes_received = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = difftime(time(NULL), time(NULL));
    while (1) {
        bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }
    end_time = difftime(time(NULL), time(NULL));
    total_time = end_time - start_time;

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Internet speed: %.2f bytes/second\n", (total_bytes_received / total_time));

    close(sock);
    return 0;
}