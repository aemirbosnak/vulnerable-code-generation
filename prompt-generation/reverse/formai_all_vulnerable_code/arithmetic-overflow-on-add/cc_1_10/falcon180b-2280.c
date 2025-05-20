//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void send_request(int sock, char *buffer) {
    send(sock, buffer, strlen(buffer), 0);
}

bool receive_response(int sock, char *buffer, int max_size) {
    int bytes_received = 0;
    while (bytes_received < max_size) {
        int ret = recv(sock, buffer + bytes_received, max_size - bytes_received, 0);
        if (ret <= 0) {
            return false;
        }
        bytes_received += ret;
    }
    buffer[bytes_received] = '\0';
    return true;
}

double calculate_speed(int bytes, double duration) {
    return (double)bytes / duration;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[1024];
    sprintf(buffer, "GET /speedtest.php HTTP/1.1\r\nHost: %s:%d\r\nConnection: keep-alive\r\n\r\n", SERVER_IP, SERVER_PORT);
    send_request(sock, buffer);

    char response_buffer[1024];
    if (!receive_response(sock, response_buffer, sizeof(response_buffer))) {
        printf("Error receiving response\n");
        return 1;
    }

    char *speed_str = strstr(response_buffer, "speed:");
    if (speed_str == NULL) {
        printf("Error parsing response\n");
        return 1;
    }
    speed_str += strlen("speed:");

    char *duration_str = strstr(response_buffer, "duration:");
    if (duration_str == NULL) {
        printf("Error parsing response\n");
        return 1;
    }
    duration_str += strlen("duration:");

    double speed = calculate_speed(atoi(speed_str), atof(duration_str));

    printf("Download speed: %.2f kB/s\n", speed);

    close(sock);
    return 0;
}