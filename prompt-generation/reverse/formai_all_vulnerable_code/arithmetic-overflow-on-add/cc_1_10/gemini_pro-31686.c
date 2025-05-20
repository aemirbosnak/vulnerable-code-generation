//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>

#define BUFSIZE 1024

struct qos_monitor {
    int sockfd;
    struct sockaddr_in addr;
    int seqno;
    int last_seqno;
    int last_time;
    int last_bps;
    int last_rtt;
};

struct qos_monitor *init_qos_monitor(const char *hostname, int port) {
    struct qos_monitor *qm;
    struct hostent *hostinfo;
    int sockfd;
    struct sockaddr_in addr;

    qm = malloc(sizeof(struct qos_monitor));
    if (!qm) {
        perror("malloc");
        return NULL;
    }

    hostinfo = gethostbyname(hostname);
    if (!hostinfo) {
        perror("gethostbyname");
        free(qm);
        return NULL;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        free(qm);
        return NULL;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr *) hostinfo->h_addr_list[0];
    addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sockfd);
        free(qm);
        return NULL;
    }

    qm->sockfd = sockfd;
    qm->addr = addr;
    qm->seqno = 0;
    qm->last_seqno = 0;
    qm->last_time = 0;
    qm->last_bps = 0;
    qm->last_rtt = 0;

    return qm;
}

void close_qos_monitor(struct qos_monitor *qm) {
    close(qm->sockfd);
    free(qm);
}

int send_packet(struct qos_monitor *qm) {
    int nbytes;
    char buf[BUFSIZE];

    memset(buf, 0, BUFSIZE);
    snprintf(buf, BUFSIZE, "%d", qm->seqno);

    nbytes = send(qm->sockfd, buf, strlen(buf), 0);
    if (nbytes < 0) {
        perror("send");
        return -1;
    }

    return nbytes;
}

int recv_packet(struct qos_monitor *qm) {
    int nbytes;
    char buf[BUFSIZE];
    struct timeval tv;

    memset(buf, 0, BUFSIZE);

    nbytes = recv(qm->sockfd, buf, BUFSIZE - 1, 0);
    if (nbytes < 0) {
        perror("recv");
        return -1;
    }

    gettimeofday(&tv, NULL);

    qm->last_seqno = qm->seqno;
    qm->last_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    qm->seqno++;

    return nbytes;
}

int get_last_bps(struct qos_monitor *qm) {
    return qm->last_bps;
}

int get_last_rtt(struct qos_monitor *qm) {
    return qm->last_rtt;
}

int main(int argc, char **argv) {
    struct qos_monitor *qm;
    int nbytes;
    int i;
    int bps;
    int rtt;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    qm = init_qos_monitor(argv[1], atoi(argv[2]));
    if (!qm) {
        return 1;
    }

    for (i = 0; i < 100; i++) {
        nbytes = send_packet(qm);
        if (nbytes < 0) {
            break;
        }

        nbytes = recv_packet(qm);
        if (nbytes < 0) {
            break;
        }

        bps = nbytes * 8 * 1000 / (qm->last_time - qm->last_time);
        rtt = qm->last_time - qm->last_time;

        printf("seqno: %d, bps: %d, rtt: %d\n", qm->last_seqno, bps, rtt);
    }

    close_qos_monitor(qm);

    return 0;
}