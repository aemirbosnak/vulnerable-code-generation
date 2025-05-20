//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10

int main() {
    int i, ping_count = 0, status;
    char host[256];

    printf("Enter the host name: ");
    scanf("%s", host);

    for (i = 0; i < MAX_PINGS; i++) {
        struct sockaddr_in sin;
        sin.sin_family = AF_INET;
        sin.sin_port = htons(53);
        sin.sin_addr.s_addr = inet_addr(host);

        if ((status = ping(sin)) == 0) {
            printf("Ping successful.\n");
            ping_count++;
        } else {
            printf("Ping failed.\n");
        }

        sleep(1);
    }

    printf("Total number of successful pings: %d\n", ping_count);

    return 0;
}

int ping(struct sockaddr_in sin) {
    int sockfd, bytes_sent, bytes_received;
    char data[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, htons(53))) < 0) {
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        close(sockfd);
        return -1;
    }

    bytes_sent = send(sockfd, data, 1024, 0);
    bytes_received = recv(sockfd, data, 1024, 0);

    close(sockfd);

    if (bytes_received > 0) {
        return 0;
    } else {
        return -1;
    }
}