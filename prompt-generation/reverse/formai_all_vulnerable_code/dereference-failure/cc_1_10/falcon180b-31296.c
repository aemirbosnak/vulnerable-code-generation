//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024
#define MAX_TRIES 5
#define DELAY_MS 1000

int ping(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int bytes_sent, bytes_recv;
    int status = FALSE;
    int tries = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return FALSE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    while (tries < MAX_TRIES &&!status) {
        bytes_sent = sendto(sockfd, "PING", strlen("PING"), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (bytes_sent == -1) {
            printf("Error sending data: %s\n", strerror(errno));
            close(sockfd);
            return FALSE;
        }

        bytes_recv = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);
        if (bytes_recv == -1) {
            printf("Error receiving data: %s\n", strerror(errno));
            close(sockfd);
            return FALSE;
        } else if (bytes_recv > 0 && strncmp(buffer, "PONG", 4) == 0) {
            status = TRUE;
        }

        usleep(DELAY_MS * 1000);
        tries++;
    }

    close(sockfd);
    return status;
}

int main() {
    char *hostname;
    printf("Enter hostname to ping: ");
    scanf("%s", hostname);

    if (ping(hostname)) {
        printf("Host %s is alive!\n", hostname);
    } else {
        printf("Host %s is not responding.\n", hostname);
    }

    return 0;
}