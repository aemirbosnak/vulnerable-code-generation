//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TRUE 1
#define FALSE 0
#define TIMEOUT 5

int ping(char *hostname);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    int result = ping(hostname);

    if (result == 0)
        printf("Host is alive\n");
    else
        printf("Host is not reachable\n");

    return 0;
}

int ping(char *hostname)
{
    int sockfd;
    struct sockaddr_in server_addr;
    char send_data[MAX_DATA];
    char recv_data[MAX_DATA];
    int bytes_sent, bytes_recv;
    struct timeval timeout;
    int result = FALSE;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        return result;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error: Invalid hostname\n");
        close(sockfd);
        return result;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        if (errno == ECONNREFUSED) {
            result = TRUE;
        } else if (errno == ETIMEDOUT) {
            result = TRUE;
        } else {
            fprintf(stderr, "Error: Failed to connect to host\n");
        }
    } else {
        result = TRUE;
    }

    close(sockfd);
    return result;
}