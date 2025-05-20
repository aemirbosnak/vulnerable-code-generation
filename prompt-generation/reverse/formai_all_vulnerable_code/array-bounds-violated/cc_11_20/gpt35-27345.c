//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shape shifting
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    pcap_if_t *all_devs, *dev;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    struct pcap_pkthdr header;
    const u_char *packet;

    // Find all available devices
    if (pcap_findalldevs(&all_devs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Choose device to capture packets on
    printf("Available devices:\n");
    for (dev = all_devs; dev != NULL; dev = dev->next) {
        printf("%s\n", dev->name);
    }
    printf("Enter the interface name to capture packets on: ");
    char chosen_dev[100];
    fgets(chosen_dev, 100, stdin);
    chosen_dev[strlen(chosen_dev) - 1] = '\0';

    // Get device info and open device for packet capture
    if (pcap_lookupnet(chosen_dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting device info: %s\n", errbuf);
        return 1;
    }
    handle = pcap_open_live(chosen_dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device for capture: %s\n", errbuf);
        return 1;
    }

    // Set filter for only capturing TCP packets
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets and print packet data
    int packet_count = 0;
    while (packet_count < 10) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }
        printf("Packet #%d:\n", packet_count + 1);
        int i;
        for (i = 0; i < header.len; i++) {
            printf("%.2x ", packet[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n");
        packet_count++;
    }

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    pcap_freealldevs(all_devs);

    return 0;
}