//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *target_ip;
    int target_port;
    int port;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    target_ip = argv[1];
    target_port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to target IP\n");
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        if (port == target_port)
            continue;

        memset(buffer, 0, BUFFER_SIZE);
        snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n", target_ip, port);

        send(sockfd, buffer, strlen(buffer), 0);

        int bytes_received = 0;
        char *response = NULL;

        while (bytes_received < BUFFER_SIZE) {
            int ret = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);

            if (ret == 0) {
                printf("Connection closed\n");
                return 0;
            } else if (ret == -1) {
                printf("Error receiving data\n");
                return 1;
            }

            bytes_received += ret;
            response = realloc(response, bytes_received + 1);
            strncat(response, buffer + bytes_received - ret, ret);
        }

        if (strstr(response, "200 OK"))
            printf("Port %d is open\n", port);

        free(response);
    }

    close(sockfd);
    return 0;
}