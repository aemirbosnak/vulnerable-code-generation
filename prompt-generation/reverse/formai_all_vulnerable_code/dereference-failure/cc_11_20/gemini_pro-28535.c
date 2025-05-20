//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multivariable
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv) {
    char *device = NULL;
    int snaplen = 65535;
    int promisc = 1;
    int to_ms = 1000;
    int timeout = 1000;
    char *filter = NULL;
    pcap_t *handle = NULL;
    struct bpf_program fp;
    struct pcap_pkthdr *header;
    const unsigned char *packet;
    int i = 0;

    if (argc > 1) {
        device = argv[1];
    }

    if (argc > 2) {
        snaplen = atoi(argv[2]);
    }

    if (argc > 3) {
        promisc = atoi(argv[3]);
    }

    if (argc > 4) {
        timeout = atoi(argv[4]);
    }

    if (argc > 5) {
        filter = argv[5];
    }

    if (device == NULL) {
        fprintf(stderr, "Error: no device specified.\n");
        return EXIT_FAILURE;
    }

    handle = pcap_open_live(device, snaplen, promisc, timeout, NULL);

    if (handle == NULL) {
        fprintf(stderr, "Error: pcap_open_live() failed: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (filter != NULL) {
        if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
            fprintf(stderr, "Error: pcap_compile() failed: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }

        if (pcap_setfilter(handle, &fp) == -1) {
            fprintf(stderr, "Error: pcap_setfilter() failed: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);

        if (res == -1) {
            fprintf(stderr, "Error: pcap_next_ex() failed: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }

        if (res == 0) {
            continue;
        }

        printf("Packet %d:\n", ++i);
        printf("  Length: %d\n", header->len);
        printf("  Capture time: %s\n", ctime((time_t *) &header->ts.tv_sec));
        printf("  Data: ");

        for (int j = 0; j < header->len; j++) {
            printf("%02x ", packet[j]);
        }

        printf("\n\n");
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}