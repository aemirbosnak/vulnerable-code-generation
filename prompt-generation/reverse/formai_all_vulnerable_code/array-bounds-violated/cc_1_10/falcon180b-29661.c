//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>

#define MAX_EVENTS 10

struct pollfd poll_fds[MAX_EVENTS];

int add_poll_fd(int fd) {
    int i;
    for (i = 0; i < MAX_EVENTS; i++) {
        if (poll_fds[i].fd == -1) {
            poll_fds[i].fd = fd;
            poll_fds[i].events = POLLIN;
            return 0;
        }
    }
    return -1;
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    while (1) {
        int n = recv(sock, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            break;
        }
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sock);
    return 0;
}