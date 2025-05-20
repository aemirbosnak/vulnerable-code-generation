//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ether.h>
#include <netinet/ip.h>

#define MAX_PACKET_LENGTH 65535

int main(int argc, char *argv[]){
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct pcap_pkthdr header;
    const u_char *packet;

    // Get the network device to sniff on
    if(argv[1]){
        dev = argv[1];
    }
    else{
        dev = pcap_lookupdev(errbuf);
        if(dev == NULL){
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            exit(1);
        }
    }

    // Get the network information for the device
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1){
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the device for sniffing
    handle = pcap_open_live(dev, MAX_PACKET_LENGTH, 1, 1000, errbuf);
    if(handle == NULL){
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    // Compile the filter expression
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1){
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    // Apply the filter expression
    if(pcap_setfilter(handle, &fp) == -1){
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    // Start sniffing packets
    while(1){
        packet = pcap_next(handle, &header);
        if(packet == NULL){
            printf("no packet found!\n");
            continue;
        }
        
        // Parse the Ethernet header
        struct ether_header *eth_header;
        eth_header = (struct ether_header *) packet;

        // Verify the protocol
        if(ntohs(eth_header->ether_type) != ETHERTYPE_IP){
            printf("Non-IP packet recieved.\n");
            continue;
        }

        // Move on to IP header
        const u_char *ip_packet = packet + sizeof(struct ether_header);
        struct iphdr *ip_header;
        ip_header = (struct iphdr *) ip_packet;

        // Print the complete packet in hex format
        printf("\nCOMPLETE PACKET RECEIVED:\n");
        printf("--------------------------------------------------------------\n");
        for(int i=0; i<header.len; i++){
            printf("%02x ", packet[i]);
        }
        printf("\n--------------------------------------------------------------\n");

        // Print the source and destination information
        printf("\nSOURCE ADDRESS: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
        printf("DESTINATION ADDRESS: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->daddr));
        
        // Print the payload
        printf("\nPAYLOAD:\n");
        printf("--------------------------------------------------------------\n");

        const u_char *payload = packet + sizeof(struct ether_header) + sizeof(struct iphdr);
        int payload_length = header.len - (sizeof(struct ether_header) + sizeof(struct iphdr));
        // Only print up to the first 64 bytes of the payload
        for(int i=0; i<payload_length && i<64; i++){
            printf("%02x ", payload[i]);
        }
        printf("\n--------------------------------------------------------------\n");
    }

    // Close the handle
    pcap_close(handle);
    return 0;
}