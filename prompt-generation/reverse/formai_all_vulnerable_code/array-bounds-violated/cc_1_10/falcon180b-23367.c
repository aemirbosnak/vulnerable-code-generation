//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main() {
    int sock, ret, len;
    struct sockaddr_in server;
    char data[MAX_DATA_SIZE];
    char *host = "www.google.com";
    int port = 80;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_port = htons(port);

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        printf("Error: connection failed\n");
        close(sock);
        exit(1);
    }

    printf("Connected to %s:%d\n", host, port);

    while (1) {
        ret = send(sock, "PING", 5, 0);
        if (ret == -1) {
            printf("Error: send failed\n");
            close(sock);
            exit(1);
        }

        ret = recv(sock, data, MAX_DATA_SIZE, 0);
        if (ret == -1) {
            printf("Error: recv failed\n");
            close(sock);
            exit(1);
        }

        data[ret] = '\0';
        printf("%s", data);

        if (strstr(data, "PONG")!= NULL) {
            printf("PONG received\n");
            break;
        }
    }

    close(sock);
    return 0;
}