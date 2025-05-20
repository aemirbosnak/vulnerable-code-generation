//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* ip_address = argv[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        close(sock);
        die("connect");
    }

    for (int i = 1; i <= MAX_PORTS; i++) {
        char buffer[BUFFER_SIZE];
        snprintf(buffer, BUFFER_SIZE, " medieval port scanner - Port %d is ", i);

        if (send(sock, buffer, strlen(buffer), 0) == -1) {
            close(sock);
            die("send");
        }

        int bytes_received = 0;
        char response[BUFFER_SIZE];

        while (bytes_received < BUFFER_SIZE) {
            int result = recv(sock, response + bytes_received, BUFFER_SIZE - bytes_received, 0);

            if (result <= 0) {
                close(sock);
                die("recv");
            }

            bytes_received += result;
        }

        response[bytes_received - 1] = '\0';

        if (strstr(response, "open")!= NULL) {
            printf("open\n");
        } else {
            printf("closed\n");
        }
    }

    close(sock);
    return EXIT_SUCCESS;
}