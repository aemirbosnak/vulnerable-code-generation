//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

int main(int argc, char *argv[]) {
  char *dev, *filter;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct bpf_program fp;
  pcap_t *handle;
  char *packet;
  struct pcap_pkthdr *header;
  int status;

  if (argc != 3) {
    printf("Usage: %s <device> <filter>\n", argv[0]);
    return 1;
  }

  dev = argv[1];
  filter = argv[2];

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Couldn't open device %s: %s\n", dev, errbuf);
    return 2;
  }

  status = pcap_compile(handle, &fp, filter, 0, PCAP_NETMASK_UNKNOWN);
  if (status != 0) {
    printf("Couldn't parse filter %s: %s\n", filter, pcap_geterr(handle));
    return 3;
  }

  status = pcap_setfilter(handle, &fp);
  if (status != 0) {
    printf("Couldn't install filter: %s\n", pcap_geterr(handle));
    return 4;
  }

  while (1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      break;
    }

    printf("Received packet of size %d bytes\n", header->len);
  }

  pcap_close(handle);
  return 0;
}