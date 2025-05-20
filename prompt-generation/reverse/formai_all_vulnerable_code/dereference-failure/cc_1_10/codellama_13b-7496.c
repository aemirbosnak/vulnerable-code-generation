//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: secure
#include <stdio.h>
#include <pcap.h>

int main() {
  // Create a pcap handle
  pcap_t *handle;
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  int ret;

  // Get the device name
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Could not find default device: %s\n", errbuf);
    return 1;
  }

  // Open the device
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Could not open device: %s\n", errbuf);
    return 1;
  }

  // Compile and apply the filter
  struct bpf_program filter;
  char filter_exp[] = "ip and dst host 192.168.1.1";
  if (pcap_compile(handle, &filter, filter_exp, 0, 0) == -1) {
    fprintf(stderr, "Could not compile filter: %s\n", pcap_geterr(handle));
    return 1;
  }
  if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Could not apply filter: %s\n", pcap_geterr(handle));
    return 1;
  }

  // Loop through the packets
  struct pcap_pkthdr header;
  const u_char *packet;
  while (1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      break;
    }

    // Print the packet data
    printf("Packet length: %d\n", header.len);
    printf("Packet data: ");
    for (int i = 0; i < header.len; i++) {
      printf("%02X ", packet[i]);
    }
    printf("\n");
  }

  // Clean up
  pcap_freecode(&filter);
  pcap_close(handle);

  return 0;
}