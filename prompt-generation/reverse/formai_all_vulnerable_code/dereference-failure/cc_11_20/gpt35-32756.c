//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    printf("C Packet Capturer with pcap library\n");

    char *dev = NULL; // device to capture from
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle; // session handle
    struct bpf_program fp; // compiled filter expression
    char filter_exp[] = "port 80"; // filter expression
    bpf_u_int32 net; // IP address of net to listen on
    bpf_u_int32 mask; // network mask of net to listen on
    struct pcap_pkthdr header; // packet header
    const u_char *packet; // packet data
    
    // find a capture device if not specified
    if (argc == 1) {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            printf("Error finding default device: %s\n", errbuf);
            exit(1);
        }
    } else { // use specified device
        dev = argv[1];
    }

    printf("Listening on device: %s\n", dev);

    // get network address and mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Error getting network information for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open the capture device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device %s: %s\n", dev, errbuf);
        exit(1);
    }

    // compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error compiling filter expression %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error applying filter expression %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    // loop through packets and print data
    int count = 0;
    while (count < 10) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet #%d\n", count+1);
            printf("Length: %d bytes\n", header.len);
            printf("Data:\n");
            for (int i = 0; i < header.len; i++) {
                printf("%02x ", packet[i]);
                if ((i+1) % 16 == 0) printf("\n");
            }
            printf("\n\n");
        }
        count++;
    }

    // cleanup
    pcap_close(handle);
    printf("Done.\n");

    return 0;
}