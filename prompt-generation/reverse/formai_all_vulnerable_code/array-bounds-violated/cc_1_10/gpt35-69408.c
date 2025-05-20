//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {
    int sockfd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    unsigned int addr_len;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(4950);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    addr_len = sizeof(struct sockaddr);

    while (1) {
        char buf[1024];
        int numbytes;

        if ((numbytes = recvfrom(sockfd, buf, 1023, 0, (struct sockaddr *)&their_addr, &addr_len)) == -1) {
            perror("recvfrom");
            exit(1);
        }

        buf[numbytes] = '\0';
        printf("Received packet from %s:%d\n", inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port));
        printf("Packet is %d bytes long\n", numbytes);
        printf("Packet contains \"%s\"\n", buf);
    }

    close(sockfd);

    return 0;
}