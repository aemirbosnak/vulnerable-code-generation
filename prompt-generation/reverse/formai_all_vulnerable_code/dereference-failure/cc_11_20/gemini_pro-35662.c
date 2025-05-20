//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
  char *dev = NULL;
  char *filter = "ip";
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  bpf_u_int32 netmask;
  struct pcap_pkthdr *header;
  const u_char *packet;

  dev = pcap_lookupdev(errbuf);
  if (dev == NULL || strlen(dev) == 0) {
    fprintf(stderr, "Cannot find default device: %s\n", errbuf);
    return -1;
  }

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Cannot open device %s: %s\n", dev, errbuf);
    return -1;
  }

  if (pcap_compile(handle, &fp, filter, 0, netmask) == -1) {
    fprintf(stderr, "Cannot compile filter: %s\n", pcap_geterr(handle));
    pcap_close(handle);
    return -1;
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Cannot set filter: %s\n", pcap_geterr(handle));
    pcap_close(handle);
    return -1;
  }

  printf("Capturing packets on device %s with filter %s\n", dev, filter);

  while (1) {
    int ret = pcap_next_ex(handle, &header, &packet);
    if (ret == 1) {
      printf("Packet capture successful\n");
      printf("Packet length: %d bytes\n", header->len);
      printf("Packet data:\n");
      for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
      }
      printf("\n\n");
    } else if (ret == -1) {
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      pcap_close(handle);
      return -1;
    } else if (ret == 0) {
      printf("Timeout while capturing packets\n");
    }
  }

  pcap_close(handle);
  return 0;
}