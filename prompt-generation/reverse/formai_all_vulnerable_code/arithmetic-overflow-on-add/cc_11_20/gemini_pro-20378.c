//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i, j, k;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    dev = argv[1];
    if ((handle = pcap_open_live(dev, 65535, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
        exit(1);
    }

    while (1) {
        if (pcap_next_ex(handle, &header, &packet) < 0) {
            fprintf(stderr, "Error capturing packet.\n");
            break;
        }

        if (header->caplen < 14)
            continue;

        for (i = 0; i < header->caplen; i++) {
            if (j + 6 > header->caplen)
                break;

            if (i >= 28) {
                for (k = 0, j = 0; j < 6; j++) {
                    if (!(packet[i + j] == 0xff))
                        break;
                }

                if (j == 6) {
                  for (k = 0, j = i + 6; j < header->caplen; j++) {
                      if (packet[j] == 0 || packet[j] == 0xff)
                          break;
                  }

                  if (j != header->caplen) {
                      printf("%02x:%02x:%02x:%02x:%02x:%02x  %.*s\n",
                               packet[i + 12], packet[i + 13], packet[i + 14], packet[i + 15],
                               packet[i + 16], packet[i + 17], j - i - 6, packet + i + 6);
                  }
              }
          }
      }
  }

  pcap_close(handle);
  return 0;
}