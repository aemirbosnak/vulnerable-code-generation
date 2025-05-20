//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_DEVICES 20
#define BUFFER_SIZE 1024

struct device {
    char name[32];
    char ip[16];
    int port;
};

void scan_network(char *ip) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(80);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        char request[64];
        snprintf(request, sizeof(request), "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", ip);
        send(sock, request, strlen(request), 0);

        char buffer[BUFFER_SIZE];
        int len = recv(sock, buffer, BUFFER_SIZE, 0);
        if (len > 0) {
            char *response = strstr(buffer, "SERVER:");
            if (response!= NULL) {
                response += strlen("SERVER:");
                char device_name[32];
                strncpy(device_name, response, strlen(response) - 1);
                device_name[strlen(response) - 1] = '\0';

                char device_ip[16];
                strncpy(device_ip, ip, strlen(ip) - 1);
                device_ip[strlen(ip) - 1] = '\0';

                int device_port = 80;

                struct device device = {
                   .name = device_name,
                   .ip = device_ip,
                   .port = device_port
                };

                printf("Device found: %s (%s:%d)\n", device.name, device.ip, device.port);
            }
        }

        close(sock);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    scan_network(argv[1]);

    return 0;
}