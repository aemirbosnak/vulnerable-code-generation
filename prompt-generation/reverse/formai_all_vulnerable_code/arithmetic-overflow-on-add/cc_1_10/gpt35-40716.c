//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <time.h>

#define SPORT 8080
#define SADDR "127.0.0.1"
#define MESSAGESIZE 1024
#define BUFSIZE 1024
#define PROTO_UDP 17
#define PROTO_TCP 6

int udpSock, tcpSock;

int initUdpSock() {
    int udpSock = socket(AF_INET, SOCK_DGRAM, PROTO_UDP);
    if (udpSock < 0) {
        printf("Udp Socket Creation Error\n");
        return -1;
    }
    return udpSock;
}

int initTcpSock() {
    int tcpSock = socket(AF_INET, SOCK_STREAM, PROTO_TCP);
    if (tcpSock < 0) {
        printf("Tcp Socket Creation Error\n");
        return -1;
    }
    return tcpSock;
}

void udpPacketHandler(unsigned char *buffer, int size) {
    struct iphdr* iph = (struct iphdr*)buffer;

    if (iph->protocol == PROTO_UDP) {
        unsigned short iphdrlen = iph->ihl * 4;
        struct udphdr* udph = (struct udphdr*)(buffer + iphdrlen);

        char message[MESSAGESIZE];
        memset(message, 0, MESSAGESIZE);
        strncpy(message, buffer + sizeof(struct iphdr) + sizeof(struct udphdr), strlen(buffer + sizeof(struct iphdr) + sizeof(struct udphdr)));
        printf("\nUDP Packet %d:\n", size);
        printf("From: %s:%d\n", inet_ntoa((struct in_addr){iph->saddr}), ntohs(udph->source));
        printf("To: %s:%d\n", inet_ntoa((struct in_addr){iph->daddr}), ntohs(udph->dest));
        printf("Data: %s\n", message);
    }   
}

void tcpPacketHandler(unsigned char *buffer, int size) {
    struct iphdr* iph = (struct iphdr*)buffer;
     
    if (iph->protocol == PROTO_TCP) {
        unsigned short iphdrlen = iph->ihl * 4;
        struct tcphdr* tcph = (struct tcphdr*)(buffer + iphdrlen);

        char message[MESSAGESIZE];
        memset(message, 0, MESSAGESIZE);
        strncpy(message, buffer + sizeof(struct iphdr) + sizeof(struct tcphdr), strlen(buffer + sizeof(struct iphdr) + sizeof(struct tcphdr)));
        printf("\nTCP Packet %d:\n", size);
        printf("From: %s:%d\n", inet_ntoa((struct in_addr){iph->saddr}), ntohs(tcph->source));
        printf("To: %s:%d\n", inet_ntoa((struct in_addr){iph->daddr}), ntohs(tcph->dest));
        printf("Data: %s\n", message);
    }
}

int main() {
    struct sockaddr_in sin_local, sin_remote;
    socklen_t sin_len = sizeof(sin_remote);

    sin_local.sin_family = AF_INET;
    sin_local.sin_port = htons(SPORT);
    sin_local.sin_addr.s_addr = inet_addr(SADDR);

    memset(sin_local.sin_zero, 0, sizeof(sin_local.sin_zero));
    memset(&sin_remote, 0, sin_len);

    udpSock = initUdpSock();
    tcpSock = initTcpSock(); 

    if (bind(udpSock, (struct sockaddr *)&sin_local, sizeof(sin_local)) < 0) {
        printf("Failed to Bind Udp Socket\n");
        return -1;
    }

    if (bind(tcpSock, (struct sockaddr *)&sin_local, sizeof(sin_local)) < 0) {
        printf("Failed to Bind Tcp Socket\n");
        return -1;
    }

    listen(tcpSock, 3);

    printf("QoS Monitor Listening on port %d\n", SPORT);

    unsigned char buffer[BUFSIZE];

    while (1) {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(udpSock, &readfds);
        FD_SET(tcpSock, &readfds);

        int max_fd, activity;
        if (udpSock > tcpSock) {
            max_fd = udpSock;
        } else {
            max_fd = tcpSock;
        }

        activity = select(max_fd + 1, &readfds , NULL , NULL , NULL);

        if (activity < 0) {
            printf("Select Error\n");
            return -1;
        }

        if (FD_ISSET(udpSock, &readfds)) {
            int size = recvfrom(udpSock, buffer, BUFSIZE, 0, (struct sockaddr *)&sin_remote, &sin_len);
            udpPacketHandler(buffer, size);
        }
        if (FD_ISSET(tcpSock, &readfds)) {
            int new_socket = accept(tcpSock, (struct sockaddr *)&sin_remote, &sin_len);
            int size = read(new_socket, buffer, BUFSIZE);
            tcpPacketHandler(buffer, size);
        }
    }

    return 0;
}