//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Callback function that prints packet data */
void packet_handler(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
    printf("Packet Captured!\n");

    /* Print packet timestamp and length */
    printf("Timestamp: %s", ctime((const time_t *)&pkt_header->ts.tv_sec));
    printf("Packet Length: %d\n", pkt_header->len);

    /* Print packet data */
    for (int i = 0; i < pkt_header->len; i++)
    {
        printf("%02x", *(pkt_data + i));
        if (i % 16 == 15)
            printf("\n");
    }
    printf("\n\n");
}

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    pcap_t *handle;
    const u_char *packet;

    /* Find available network devices */
    pcap_if_t *interfaces;
    if (pcap_findalldevs(&interfaces, errbuf) == -1)
    {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(1);
    }

    /* Print available network devices */
    printf("Available Network Devices:\n");
    int i = 0;
    for (pcap_if_t *d = interfaces; d; d = d->next)
    {
        printf("%d: %s\n", ++i, d->name);
    }

    /* Select network device to capture packets */
    printf("Select device to capture packets: ");
    int choice = 0;
    scanf("%d", &choice);
    if (choice < 1 || choice > i)
    {
        fprintf(stderr, "Invalid choice.\n");
        exit(1);
    }

    /* Open network device for packet capture */
    handle = pcap_open_live(interfaces[choice - 1].name, 65536, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    /* Start capturing packets */
    printf("Packet capture started...\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    /* Cleanup */
    pcap_close(handle);
    pcap_freealldevs(interfaces);

    return 0;
}