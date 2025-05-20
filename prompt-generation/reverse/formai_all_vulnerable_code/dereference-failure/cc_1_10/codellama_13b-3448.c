//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  struct pcap_pkthdr *header;
  const u_char *packet;
  int i, ret;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <device>\n", argv[0]);
    return 1;
  }

  dev = argv[1];

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return 2;
  }

  ret = pcap_compile(handle, &fp, "tcp port 80", 0, PCAP_NETMASK_UNKNOWN);
  if (ret == -1) {
    fprintf(stderr, "Couldn't parse filter: %s\n", pcap_geterr(handle));
    return 3;
  }

  ret = pcap_setfilter(handle, &fp);
  if (ret == -1) {
    fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
    return 4;
  }

  printf("Listening on device %s for TCP packets to port 80...\n", dev);

  while (1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      fprintf(stderr, "pcap_next() failed: %s\n", pcap_geterr(handle));
      return 5;
    }

    printf("Packet received with length %d\n", header->len);

    for (i = 0; i < header->len; i++) {
      printf("%02X ", packet[i]);
    }

    printf("\n");
  }

  pcap_close(handle);

  return 0;
}