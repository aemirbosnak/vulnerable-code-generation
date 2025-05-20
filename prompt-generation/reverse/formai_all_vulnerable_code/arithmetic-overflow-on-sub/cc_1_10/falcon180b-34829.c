//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int bytes_received = 0;
    int total_bytes = 0;
    int start_time = time(NULL);
    double elapsed_time = 0;
    double speed = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }

    while (TRUE) {
        bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes += bytes_received;
    }

    elapsed_time = (double)(time(NULL) - start_time);
    speed = (double)total_bytes / elapsed_time;

    printf("Total bytes received: %d\n", total_bytes);
    printf("Elapsed time: %f seconds\n", elapsed_time);
    printf("Speed: %f bytes/second\n", speed);

    close(sock);
    return 0;
}