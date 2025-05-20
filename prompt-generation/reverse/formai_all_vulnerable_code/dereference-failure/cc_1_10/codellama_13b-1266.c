//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: imaginative
#include <pcap.h>

#define SNAP_LEN 65535
#define PROMISC_MODE 1

int main(int argc, char **argv) {
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program filter;
  bpf_u_int32 mask;
  bpf_u_int32 net;
  struct pcap_pkthdr header;
  const u_char *packet;

  // Check if the user provided a network interface
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <network interface>\n", argv[0]);
    return 1;
  }

  // Get the network interface from the command line arguments
  dev = argv[1];

  // Open the network interface in promiscuous mode
  handle = pcap_open_live(dev, SNAP_LEN, PROMISC_MODE, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
    return 2;
  }

  // Compile and apply the filter
  if (pcap_compile(handle, &filter, "tcp port 80", 0, net) == -1) {
    fprintf(stderr, "Could not compile filter: %s\n", pcap_geterr(handle));
    return 3;
  }
  if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Could not set filter: %s\n", pcap_geterr(handle));
    return 4;
  }

  // Loop through the packets and print the contents
  while (1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      fprintf(stderr, "No more packets to capture\n");
      break;
    }

    // Print the packet contents
    printf("Packet number %d, length %d bytes\n", header.ts.tv_sec, header.len);
    for (int i = 0; i < header.len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");
  }

  // Clean up
  pcap_close(handle);
  return 0;
}