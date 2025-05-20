//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAPLEN 1024

int main(int argc, char *argv[])
{
    int res;
    int ifcount, i;
    pcap_if_t *alldevs, *dev;
    char *interfaceName;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;

    /* 1. Get the list of interfaces. */
    if(pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        fprintf(stderr, "pcap_findalldevs() error: %s\n", errbuf);
        return 1;
    }

    /* 2. Print the list of interfaces. */
    printf("Available interfaces:\n");
    for(dev = alldevs; dev; dev = dev->next)
    {
        printf("%d. %s\n", i, dev->name);
        i++;
    }

    /* 3. Get the interface name from the user. */
    printf("Enter the interface number: ");
    scanf("%d", &ifcount);

    /* 4. Get the interface by the index. */
    dev = alldevs;
    for(i = 0; i < ifcount && dev; i++, dev = dev->next);

    if(!dev)
    {
        fprintf(stderr, "Invalid interface number\n");
        return 1;
    }

    interfaceName = dev->name;

    /* 5. Open the interface for capturing packets. */
    handle = pcap_open_live(interfaceName, SNAPLEN, PCAP_OPENFLAG_PROMISCUOUS, 100, errbuf);

    if(!handle)
    {
        fprintf(stderr, "pcap_open_live() error: %s\n", errbuf);
        return 1;
    }

    /* 6. Capture packets. */
    while(1)
    {
        res = pcap_next_ex(handle, &header, &packet);

        if(res == -1)
        {
            fprintf(stderr, "pcap_next_ex() error: %s\n", pcap_geterr(handle));
            return 1;
        }
        else if(res == -2)
        {
            continue;
        }
        else
        {
            /* Do something with the packet. */
            printf("Packet length: %d\n", header.len);
            printf("Packet data:\n");
            for(i = 0; i < header.len; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("\n");
        }
    }

    /* 7. Close the interface. */
    pcap_close(handle);

    return 0;
}