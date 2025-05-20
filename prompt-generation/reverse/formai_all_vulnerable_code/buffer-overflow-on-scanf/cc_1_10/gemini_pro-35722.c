//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define SNAPLEN 1518

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    struct in_addr source;
    struct in_addr dest;
    const u_char *ptr;

    printf("Packet arrived!\n");

    source.s_addr = *ptr;
    dest.s_addr = *(ptr + 4);

    printf("Source: %s\n", inet_ntoa(source));
    printf("Dest: %s\n", inet_ntoa(dest));

    int i = 1;
    while (i < header->caplen) {
        printf("%02x ", packet[i]);
        i++;
        if (i % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main()
{
    pcap_t *handle;
    pcap_if_t *all_devices;
    pcap_if_t *device;
    const char *device_name;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_string[] = "tcp and port 80";

    // Find all the network devices
    if (pcap_findalldevs(&all_devices, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return -1;
    }

    // Print the list of devices
    printf("Found the following devices:\n");
    for (device = all_devices; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // Ask the user to select a device
    printf("Enter the name of the device you want to capture on: ");
    scanf("%s", device_name);

    // Open the device for capture
    handle = pcap_open_live(device_name, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return -1;
    }

    // Compile the filter
    if (pcap_compile(handle, &filter, filter_string, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Start the capture loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the device
    pcap_close(handle);

    return 0;
}