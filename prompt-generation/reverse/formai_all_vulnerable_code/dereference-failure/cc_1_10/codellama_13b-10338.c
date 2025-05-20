//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
/*
 * A unique C Packet Capturer with pcap library example program in a shocked style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>

#define MAX_PACKET_SIZE 65536

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s interface\n", argv[0]);
    return 1;
  }

  char *interface = argv[1];

  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];

  handle = pcap_open_live(interface, BUFSIZ, 1, 0, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", interface, errbuf);
    return 2;
  }

  struct pcap_pkthdr hdr;
  const u_char *packet;

  while (1) {
    packet = pcap_next(handle, &hdr);

    if (packet == NULL) {
      fprintf(stderr, "Error while reading packet: %s\n", pcap_geterr(handle));
      break;
    }

    printf("Packet length: %d bytes\n", hdr.len);
    printf("Packet contents:\n");

    for (int i = 0; i < hdr.len; i++) {
      printf("%02x ", packet[i]);
    }

    printf("\n");
  }

  pcap_close(handle);

  return 0;
}