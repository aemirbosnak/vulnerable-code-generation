//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

struct packet_data {
    u_char *data;
    int len;
};

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct packet_data *data = (struct packet_data*)args;
    data->len = header->len;
    data->data = (u_char*)malloc(header->len);
    memcpy(data->data, packet, header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_str[] = "tcp port 80";
    struct bpf_program filter;
    char device[1024];
    int i, j, res;
    struct packet_data data;

    printf("Enter the device name: ");
    scanf("%s", device);

    handle = pcap_create(device, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    printf("Enter the filter string: ");
    scanf("%s", filter_str);

    res = pcap_compile(handle, &filter, filter_str, 0, 0);
    if (res!= 0) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    res = pcap_setfilter(handle, &filter);
    if (res!= 0) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    printf("Press any key to start capturing packets...\n");
    getchar();

    while (1) {
        res = pcap_dispatch(handle, 1, process_packet, (u_char*)&data);
        if (res == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            break;
        }

        if (data.len > 0) {
            printf("Packet captured:\n");
            printf("Length: %d bytes\n", data.len);
            printf("Data: ");
            for (i = 0; i < data.len; i++) {
                printf("%02X ", data.data[i]);
            }
            printf("\n");
        }
    }

    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}