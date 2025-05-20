//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT_MAX 65535

int main() {
    int sockfd, port, n, i, host_port, target_port, connected = 0;
    char buf[1024], hostname[256], target_hostname[256];
    struct sockaddr_in srv_addr, client_addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter target port: ");
    scanf("%d", &target_port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(8));

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    srv_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    connected = 1;

    printf("Connected to: %s:%d\n", hostname, target_port);

    // Send and receive messages
    while (1) {
        printf("Enter message: ");
        scanf("%s", buf);

        n = send(sockfd, buf, strlen(buf) + 1, 0);

        if (n == -1) {
            perror("Error sending message");
            break;
        }

        memset(buf, 0, 1024);

        n = recv(sockfd, buf, 1024, 0);

        if (n == -1) {
            perror("Error receiving message");
            break;
        }

        printf("Received: %s\n", buf);
    }

    if (connected) {
        close(sockfd);
        printf("Connection closed.\n");
    }

    return 0;
}