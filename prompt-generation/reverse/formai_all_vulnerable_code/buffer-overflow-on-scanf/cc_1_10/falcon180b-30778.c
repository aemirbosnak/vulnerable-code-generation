//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <signal.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PACKET_COUNT 1000
#define PACKET_SIZE 64
#define PACKET_INTERVAL 10

pcap_t *handle;
char *dev;
char errbuf[PCAP_ERRBUF_SIZE];

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received!\n");
}

void cleanup(int signum) {
    pcap_breakloop(handle);
    pcap_close(handle);
    exit(0);
}

int main() {
    int i;
    int count = 0;
    char *filter_exp;
    struct bpf_program filter;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;

    printf("Enter the network interface: ");
    scanf("%s", dev);

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if(handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    printf("Enter the filter expression: ");
    scanf("%s", filter_exp);

    if(pcap_compile(handle, &filter, filter_exp, 0, 0) == -1) {
        fprintf(stderr, "pcap_compile() failed\n");
        exit(1);
    }

    if(pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "pcap_setfilter() failed\n");
        exit(1);
    }

    printf("Starting packet capture...\n");

    pcap_loop(handle, 0, packet_handler, NULL);

    printf("Packet capture complete.\n");

    pcap_close(handle);

    return 0;
}