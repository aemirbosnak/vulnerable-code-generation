//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *server_ip = "speedtest.net";
    int server_port = 80;
    char buffer[1024];
    int bytes_received;
    int total_bytes_received = 0;
    int start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    start_time = time(NULL);

    while (total_bytes_received < 1024 * 1024) {
        bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            break;
        }
        total_bytes_received += bytes_received;
    }

    end_time = time(NULL);
    elapsed_time = (double) (end_time - start_time);
    speed = (double) total_bytes_received / elapsed_time;

    printf("Internet speed: %.2f Mbps\n", speed / (1024 * 1024));

    close(sock);
    return 0;
}