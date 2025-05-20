//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "speedtest.net"
#define PORT 80

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    char send_data[1024];
    int bytes_sent, bytes_received;
    double start_time, end_time;
    double total_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(send_data, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER);

    bytes_sent = send(sock, send_data, strlen(send_data), 0);

    if (bytes_sent == -1) {
        printf("Error sending data\n");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));

    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    start_time = 0.0;
    end_time = 0.0;

    while (start_time == 0.0) {
        if (fgets(buffer, sizeof(buffer), stdin)!= NULL) {
            sscanf(buffer, "%lf", &start_time);
        }
    }

    while (end_time == 0.0) {
        if (fgets(buffer, sizeof(buffer), stdin)!= NULL) {
            sscanf(buffer, "%lf", &end_time);
        }
    }

    total_time = end_time - start_time;
    speed = (double)bytes_received / total_time;

    printf("Internet Speed: %.2lf bytes/second\n", speed);

    return 0;
}