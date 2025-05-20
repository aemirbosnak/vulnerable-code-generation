//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#define MAX_PACKETS 100

int main() {
    struct timeval start, end;
    struct hostent *server;
    int sockfd, bytes_sent, bytes_recv, i, j;
    char buf[MAX_PACKETS + 1];
    struct sockaddr_in serv_addr;

    printf("Enter the IP address of the server: ");
    scanf("%s", &buf);
    server = gethostbyname(buf);

    if (server == NULL) {
        printf("Error: No such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        return 1;
    }

    gettimeofday(&start, NULL);

    for (i = 0; i < MAX_PACKETS; i++) {
        memset(buf, 0, sizeof(buf));
        strcpy(buf, "Hello World");

        bytes_sent = send(sockfd, buf, strlen(buf), 0);
        if (bytes_sent < 0) {
            printf("Error: Failed to send packet\n");
            return 1;
        }

        memset(buf, 0, sizeof(buf));
        bytes_recv = recv(sockfd, buf, MAX_PACKETS, 0);
        if (bytes_recv < 0) {
            printf("Error: Failed to receive packet\n");
            return 1;
        }

        printf("%s\n", buf);
    }

    gettimeofday(&end, NULL);
    printf("Latency: %lu.%06lu seconds\n", (end.tv_sec - start.tv_sec), (end.tv_usec - start.tv_usec));
    printf("Packet loss: %f%%\n", ((float) (bytes_sent - bytes_recv) / (float) bytes_sent) * 100);

    close(sockfd);
    return 0;
}