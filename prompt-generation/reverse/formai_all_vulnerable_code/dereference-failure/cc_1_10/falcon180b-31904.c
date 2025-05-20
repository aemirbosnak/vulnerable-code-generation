//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int opt = 1;
    int timeout = 5;
    int ret;
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket failed: %s\n", strerror(errno));
        exit(1);
    }

    // Set options
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("setsockopt failed: %s\n", strerror(errno));
        exit(1);
    }

    // Connect to server
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        printf("connect failed: %s\n", strerror(errno));
        exit(1);
    }

    // Send data
    char data[] = "PING";
    send(sock, data, strlen(data), 0);

    // Receive data
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    struct timeval timeout_val;
    timeout_val.tv_sec = timeout;
    timeout_val.tv_usec = 0;
    ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout_val, sizeof(timeout_val));
    if (ret == -1) {
        printf("setsockopt failed: %s\n", strerror(errno));
        exit(1);
    }

    ret = recv(sock, buffer, sizeof(buffer), 0);
    if (ret == -1) {
        printf("recv failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received data: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}