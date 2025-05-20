//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10

int main() {
    int i, j, ping_count = 0, success_count = 0;
    char host[256];
    struct sockaddr_in serv_addr;

    printf("Enter the host name: ");
    scanf("%s", host);

    for (i = 0; i < MAX_PINGS; i++) {
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(53);
        serv_addr.sin_addr.s_addr = inet_addr(host);

        if (ping(serv_addr) == 0) {
            success_count++;
        }

        ping_count++;
    }

    printf("Total pings: %d\n", ping_count);
    printf("Number of successful pings: %d\n", success_count);
    printf("Success rate: %.2f%%", (float)success_count / ping_count * 100);

    return 0;
}

int ping(struct sockaddr_in serv_addr) {
    int sockfd, result, flags = 1;
    char buf[128];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(53));
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    send(sockfd, "Ping", 5, flags);
    result = recv(sockfd, buf, 128, flags);

    close(sockfd);

    if (result == 5 && strcmp(buf, "Pong") == 0) {
        return 0;
    } else {
        return -1;
    }
}