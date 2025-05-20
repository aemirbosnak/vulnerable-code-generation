//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int counter = 0;
    printf("Packet number %d:\n", ++counter);
    printf("Packet size: %d bytes\n", header->len);
    printf("Payload:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    pcap_if_t *alldevs;
    pcap_if_t *d;
    int interface_num = 0;
    int selected_interface_num;
    char selected_interface_name[PCAP_BUF_SIZE];

    // Step 1: Get a list of all available interfaces
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(1);
    }

    // Step 2: Show the list of interfaces and prompt for selection
    printf("Available Interfaces:\n");
    for (d = alldevs; d; d = d->next) {
        printf("%d. %s\n", ++interface_num, d->name);
    }
    printf("Select Interface (1-%d): ", interface_num);
    scanf("%d", &selected_interface_num);

    if (selected_interface_num < 1 || selected_interface_num > interface_num) {
        fprintf(stderr, "Invalid interface number\n");
        exit(1);
    }

    // Step 3: Open the selected interface
    int i = 0;
    for (d = alldevs; d; d = d->next) {
        if (++i == selected_interface_num) {
            strncpy(selected_interface_name, d->name, sizeof(selected_interface_name));
            selected_interface_name[sizeof(selected_interface_name)-1] = '\0';
            break;
        }
    }
    pcap_handle = pcap_open_live(selected_interface_name, BUFSIZ, 0, 1000, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Error opening interface %s: %s\n", selected_interface_name, errbuf);
        exit(1);
    }

    // Step 4: Start capturing packets
    printf("Capturing packets on %s...\n", selected_interface_name);
    pcap_loop(pcap_handle, 0, packet_handler, NULL);

    // Step 5: Cleanup
    pcap_close(pcap_handle);
    pcap_freealldevs(alldevs);
    return 0;
}