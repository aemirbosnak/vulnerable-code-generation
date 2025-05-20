//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
// packet_capturer.c

#include <pcap.h>
#include <stdio.h>

int main() {
  pcap_t *handle;
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct pcap_pkthdr header;
  const u_char *packet;
  int i;

  // Get the name of the default device
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    printf("Error finding default device: %s\n", errbuf);
    return 1;
  }

  // Open the device
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Error opening device: %s\n", errbuf);
    return 1;
  }

  // Loop through all packets in the capture
  while (1) {
    // Read a packet
    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      break;
    }

    // Print the packet's contents
    printf("Packet #%d\n", i++);
    printf("  Header: %s\n", header.ts.tv_sec);
    printf("  Packet: ");
    for (int i = 0; i < header.len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");
  }

  // Close the device
  pcap_close(handle);

  return 0;
}