//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    char data[MAX_DATA];
    strcpy(data, argv[2]);

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to host %s: %s\n", hostname, strerror(errno));
        return 1;
    }

    send(sockfd, data, strlen(data), 0);

    char buffer[MAX_DATA];
    int bytes_received = recv(sockfd, buffer, MAX_DATA, 0);

    if(bytes_received <= 0) {
        fprintf(stderr, "Error receiving data from host %s\n", hostname);
        return 1;
    }

    close(sockfd);

    printf("Received response from host %s:\n%s\n", hostname, buffer);

    return 0;
}