//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in dest_addr;
    char dest_ip[16];
    int dest_port;
    char buffer[1024];
    int nbytes;

    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    strcpy(dest_ip, argv[1]);
    dest_port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(dest_port);
    inet_pton(AF_INET, dest_ip, &dest_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (ret == -1) {
        printf("Error connecting to %s:%d\n", dest_ip, dest_port);
        close(sockfd);
        return 1;
    }

    printf("Connected to %s:%d\n", dest_ip, dest_port);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
        if (nbytes <= 0) {
            printf("Error receiving data\n");
            close(sockfd);
            return 1;
        }
        printf("Received %d bytes of data: %s\n", nbytes, buffer);
    }

    close(sockfd);
    return 0;
}