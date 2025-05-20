//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: beginner-friendly
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    pcap_if_t *alldevs = NULL;
    pcap_if_t *dev = NULL;

    int i = 0;
    int inum = 0;

    printf("Packet Capturer\n");

    // Get the list of available capture devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Print the list of available capture devices
    printf("Available devices:\n");
    for (dev = alldevs; dev != NULL; dev = dev->next) {
        printf("%d. %s\n", ++i, dev->name);
        if (dev->description)
            printf("   (%s)\n", dev->description);
        else
            printf("   (No description available)\n");
    }

    // Prompt the user to select a capture device
    printf("Enter the number of the device you want to capture from: ");
    scanf("%d", &inum);
    if (inum < 1 || inum > i) {
        printf("Invalid device number.\n");
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Move to the selected device
    for (dev = alldevs, i = 0; i < inum - 1; dev = dev->next, i++);

    // Open the selected device for capturing
    if ((handle = pcap_open_live(dev->name, 65536, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "Error opening adapter: %s\n", errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    printf("Capturing on device: %s\n", dev->name);

    // Begin capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the capture device
    pcap_freealldevs(alldevs);
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet captured.\n");

    // Print the packet data
    int i = 0;
    for (i = 0; i < header->len; i++) {
        printf("%.2x ", *(pkt_data + i));
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}