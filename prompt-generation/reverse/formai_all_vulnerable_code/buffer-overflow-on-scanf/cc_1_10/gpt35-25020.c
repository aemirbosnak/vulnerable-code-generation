//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main()
{
    pcap_if_t *all_devices;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Retrieve the device list
    if (pcap_findalldevs(&all_devices, errbuf) < 0)
    {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Print the list of devices
    int i = 0;
    for (device = all_devices; device != NULL; device = device->next)
    {
        printf("%d. %s\n", ++i, device->name);
    }

    // Ask the user to choose a device
    int choice;
    printf("Enter the interface number (1-%d): ", i);
    scanf("%d", &choice);

    if (choice < 1 || choice > i)
    {
        fprintf(stderr, "Invalid choice.\n");
        return 1;
    }

    // Get the chosen device
    for (device = all_devices, i = 1; i < choice; device = device->next, ++i);

    // Open the device for capturing
    pcap_t *handle;
    handle = pcap_open_live(device->name, 65535, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }

    // Set the capture filter
    struct bpf_program filter;
    char filter_exp[] = "ip";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) < 0)
    {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) < 0)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(handle);
    pcap_freealldevs(all_devices);

    return 0;
}

// The function to be called back when a packet is captured
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    // Print the packet length
    printf("Packet length: %d\n", header->len);
}