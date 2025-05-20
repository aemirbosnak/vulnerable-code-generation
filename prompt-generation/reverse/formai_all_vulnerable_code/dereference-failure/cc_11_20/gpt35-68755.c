//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
// Simple HTTP Proxy Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int proxy_port = 80;
    char *proxy_ip;
    char *target_ip;
    int target_port = 80;

    if (argc < 4) {
        printf("Usage: %s <proxy_ip> <target_ip> <url> [proxy_port] [target_port]\n", argv[0]);
        exit(-1);
    }

    proxy_ip = argv[1];
    target_ip = argv[2];
    char *url = argv[3];

    if (argc > 4) {
        proxy_port = atoi(argv[4]);
    }
    if (argc > 5) {
        target_port = atoi(argv[5]);
    }

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (proxy_socket < 0) {
        perror("Couldn't create proxy socket");
        exit(-1);
    }

    struct sockaddr_in proxy_address;
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_port = htons(proxy_port);
    inet_pton(AF_INET, proxy_ip, &(proxy_address.sin_addr));

    if (connect(proxy_socket, (struct sockaddr *) &proxy_address, sizeof(proxy_address)) < 0) {
        perror("Couldn't connect to the proxy");
        exit(-1);
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url, target_ip);

    if (send(proxy_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Couldn't send request to proxy");
        exit(-1);
    }

    int target_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (target_socket < 0) {
        perror("Couldn't create target socket");
        exit(-1);
    }

    struct sockaddr_in target_address;
    target_address.sin_family = AF_INET;
    target_address.sin_port = htons(target_port);
    inet_pton(AF_INET, target_ip, &(target_address.sin_addr));

    if (connect(target_socket, (struct sockaddr *) &target_address, sizeof(target_address)) < 0) {
        perror("Couldn't connect to the target");
        exit(-1);
    }

    while (1) {
        int bytes_received = recv(proxy_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Error receiving data from proxy");
            exit(-1);
        }

        if (bytes_received == 0) {
            break;
        }

        if (send(target_socket, buffer, bytes_received, 0) < 0) {
            perror("Couldn't send data to target");
            exit(-1);
        }
    }

    while (1) {
        int bytes_received = recv(target_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Error receiving data from target");
            exit(-1);
        }

        if (bytes_received == 0) {
            break;
        }

        if (send(proxy_socket, buffer, bytes_received, 0) < 0) {
            perror("Couldn't send data to proxy");
            exit(-1);
        }
    }

    close(proxy_socket);
    close(target_socket);

    return 0;
}