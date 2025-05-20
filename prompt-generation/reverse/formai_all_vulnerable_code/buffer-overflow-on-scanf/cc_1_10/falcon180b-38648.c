//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PKT_SIZE 65535

struct packet_info {
    u_char *packet;
    int len;
};

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct packet_info *info = (struct packet_info *) args;
    memcpy(info->packet, packet, header->caplen);
    info->len = header->caplen;
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[100];
    struct bpf_program fp;
    char filter_exp[] = "tcp and host 192.168.1.1";
    int net = 1;
    int mask = 0xFF;
    int opt = 0;
    int ret;

    printf("Enter network device name: ");
    scanf("%s", dev);

    handle = pcap_open_live(dev, MAX_PKT_SIZE, 0, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error: pcap_compile() failed\n");
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error: pcap_setfilter() failed\n");
        exit(1);
    }

    while (1) {
        ret = pcap_loop(handle, -1, process_packet, NULL);
        if (ret == -1) {
            printf("Error: pcap_loop() failed\n");
            exit(1);
        }
        if (ret == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}