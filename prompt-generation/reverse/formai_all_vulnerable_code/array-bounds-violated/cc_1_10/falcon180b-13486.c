//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    char server_ip[MAX_HOST_LEN];
    strcpy(server_ip, argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *server_info = gethostbyname(server_ip);

    if (server_info == NULL) {
        printf("Error: Invalid server IP\n");
        close(server_socket);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error: Failed to connect to server\n");
        close(server_socket);
        return 1;
    }

    char request[MAX_DATA_LEN];
    sprintf(request, "GET /speedtest.php HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", server_ip);

    send(server_socket, request, strlen(request), 0);

    char response[MAX_DATA_LEN];
    int bytes_received = recv(server_socket, response, MAX_DATA_LEN, 0);

    if (bytes_received <= 0) {
        printf("Error: Failed to receive response from server\n");
        close(server_socket);
        return 1;
    }

    response[bytes_received] = '\0';

    int speed = 0;
    char *speed_str = strstr(response, "speed=");

    if (speed_str!= NULL) {
        speed_str += 6;
        speed = atoi(speed_str);
    }

    printf("Internet speed: %d kbps\n", speed);

    close(server_socket);

    return 0;
}