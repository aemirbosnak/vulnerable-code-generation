//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct in_addr server_addr;

    if (inet_pton(AF_INET, ip_address, &server_addr) <= 0) {
        printf("Invalid IP Address\n");
        return 1;
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("socket failed\n");
        return 1;
    }

    struct sockaddr_in server_addr_in;
    memset(&server_addr_in, 0, sizeof(server_addr_in));
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_addr.s_addr = server_addr.s_addr;
    server_addr_in.sin_port = htons(1);

    if (connect(sockfd, (struct sockaddr *)&server_addr_in, sizeof(server_addr_in)) == -1) {
        printf("connect failed\n");
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    for (int i = 1; i <= MAX_PORTS; i++) {
        snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n", ip_address, i);

        send(sockfd, buffer, strlen(buffer), 0);

        int bytes_received = 0;
        char response[BUFFER_SIZE];
        while ((bytes_received = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
            response[bytes_received] = '\0';
            if (strstr(response, "200 OK")) {
                printf("Port %d is open\n", i);
            } else {
                printf("Port %d is closed\n", i);
            }
        }
    }

    close(sockfd);
    return 0;
}