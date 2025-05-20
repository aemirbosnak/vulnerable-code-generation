//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 12345
#define MAX 100

int main(int argc, char *argv[]) {
    int sock, i, addrlen, ret, maxfd, activity, valread;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX];
    fd_set readfds;

    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Number of Packets>\n", argv[0]);
        exit(0);
    }

    if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        printf("Socket creation failed\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    for(i = 0; i < atoi(argv[2]); i++) {
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "Ping Packet %d", i+1);
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
        printf("Sent Packet %d\n", i+1);
    }

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    maxfd = sock;

    while(TRUE) {
        activity = select(maxfd+1, &readfds, NULL, NULL, NULL);

        if((activity < 0) && (errno!= EINTR)) {
            printf("Select error\n");
            exit(0);
        }

        if(FD_ISSET(sock, &readfds)) {
            memset(buffer, 0, sizeof(buffer));
            ret = recvfrom(sock, buffer, MAX, 0, NULL, NULL);

            if(ret < 0) {
                printf("Recvfrom error\n");
                exit(0);
            }

            printf("Received Packet: %s\n", buffer);
        }
    }

    close(sock);
    exit(0);
}