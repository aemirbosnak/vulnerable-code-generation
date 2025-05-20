//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

/* Custom packet handler function */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct tm *local_time;
    char time_string[26];
    int packet_len = header->len;

    /* Convert the header timestamp to a human-readable time string */
    local_time = localtime(&header->ts.tv_sec);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

    /* Print out the packet header information */
    printf("Packet captured at %s with length %d bytes\n", time_string, packet_len);

    /* Print out the packet data as hexadecimal bytes */
    for (int i = 0; i < packet_len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n\n");
}

int main() {
    char *interface_name = NULL;             /* The name of the network interface to capture packets from */
    char *bpf_filter = NULL;                /* The BPF filter expression to apply to the captured packets */
    int promiscuous_mode = 1;              /* Set to 1 to enable promiscuous mode, 0 to disable */
    int timeout = 1000;                    /* The number of milliseconds to wait for a packet to arrive */
    int packet_count = 0;                 /* The number of packets captured so far */
    int packet_limit = 100;                /* The maximum number of packets to capture (0 for unlimited) */

    /* Get the network interface name from the user */
    printf("Enter the name of the network interface to capture packets from: ");
    scanf("%s", interface_name);

    /* Get the BPF filter expression from the user */
    printf("Enter the BPF filter expression to apply to the captured packets: ");
    scanf("%s", bpf_filter);

    /* Open the network interface for capturing packets */
    pcap_t *handle = pcap_open_live(interface_name, BUFSIZ, promiscuous_mode, timeout, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening the network interface for capturing packets: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* Set the BPF filter expression */
    if (pcap_setfilter(handle, bpf_filter) != 0) {
        fprintf(stderr, "Error setting the BPF filter expression: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* Loop until the packet limit is reached */
    while (packet_count < packet_limit) {
        /* Wait for a packet to arrive */
        int packets_read = pcap_dispatch(handle, 1, packet_handler, NULL);
        if (packets_read == -1) {
            fprintf(stderr, "Error reading packets from the network interface: %s\n", pcap_geterr(handle));
            break;
        } else if (packets_read == 0) {
            /* No packets arrived within the timeout period */
            continue;
        } else {
            /* One or more packets arrived */
            packet_count += packets_read;
        }
    }

    /* Close the network interface */
    pcap_close(handle);

    return EXIT_SUCCESS;
}