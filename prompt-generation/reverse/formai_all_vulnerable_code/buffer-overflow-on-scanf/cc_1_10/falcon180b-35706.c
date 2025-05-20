//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 1024
#define SNAPLEN 65535
#define TRUE 1
#define FALSE 0

char errbuf[PCAP_ERRBUF_SIZE];

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Received packet with length %d\n", header->len);
}

int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char dev[100];
    struct bpf_program fp;
    int ret;
    char filter_exp[] = "tcp port 80";

    printf("Enter network device: ");
    scanf("%s", dev);

    handle = pcap_open_live(dev, SNAPLEN, 1, 0, errbuf);
    if (handle == NULL)
    {
        printf("Error opening live capture device: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, 0)!= 0)
    {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp)!= 0)
    {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    ret = pcap_loop(handle, -1, packet_handler, NULL);
    if (ret!= 0)
    {
        printf("Error looping packet capture: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_close(handle);
    return 0;
}