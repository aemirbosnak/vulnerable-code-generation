//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>


#define ICMP_HDR_LEN 8
#define MAX_LEN 65536

struct hdr_qos {
    u_int8_t tos;
    u_int8_t len;
    u_int8_t type;
    u_int8_t code;
    u_int16_t checksum;
    u_int32_t identifier;
    u_int32_t sequence_number;
    u_int32_t timestamp;
};

int sock_fd = -1;
struct sockaddr_in dest;
struct hdr_qos hdr;
char buffer[MAX_LEN];
int verbose = 0;

void interrupt_handler(int sig) {
    printf("Received interrupt signal %d.\n", sig);
    close(sock_fd);
    exit(0);
}

void print_usage(char *prog_name) {
    printf("Usage: %s <destination IP address> <optional: verbose mode (0/1)>\n", prog_name);
}

int main(int argc, char **argv) {
    int i, ret, size;
    struct timeval start, end;

    if (signal(SIGINT, interrupt_handler) == SIG_ERR) {
        perror("Error setting signal handler");
        exit(1);
    }

    if (argc < 2) {
        print_usage(argv[0]);
        exit(1);
    }

    if (argc == 3) {
        verbose = atoi(argv[2]);
    }

    if ((sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(argv[1]);

    memset(&hdr, 0, sizeof(hdr));
    hdr.type = ICMP_ECHO;
    hdr.code = 0;
    hdr.identifier = getpid();
    hdr.sequence_number = 0;
    hdr.checksum = 0;
    gettimeofday(&start, NULL);

    size = ICMP_HDR_LEN + sizeof(struct timeval);
    if ((ret = sendto(sock_fd, &hdr, size, 0, (struct sockaddr *)&dest, sizeof(dest))) < 0) {
        perror("Error sending packet");
        close(sock_fd);
        exit(1);
    } else if (verbose) {
        printf("Sent QoS packet.\n");
    }

    if ((ret = recvfrom(sock_fd, buffer, MAX_LEN, 0, NULL, NULL)) < 0) {
        perror("Error receiving packet");
        close(sock_fd);
        exit(1);
    } else if (verbose) {
        printf("Received QoS packet.\n");
    }

    gettimeofday(&end, NULL);
    printf("Round trip time: %.2fms\n", (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0);

    close(sock_fd);
    return 0;
}