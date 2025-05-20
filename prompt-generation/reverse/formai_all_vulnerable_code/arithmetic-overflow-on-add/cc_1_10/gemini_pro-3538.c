//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: scientific
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Callback function to process each packet */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
  struct tm *local_time;
  char time_buffer[80];
  int i;

  printf("\nPacket capture length: %d\n", header->caplen);
  printf("Packet total length: %d\n", header->len);

  // Convert the timestamp to a human-readable string
  local_time = localtime(&header->ts.tv_sec);
  strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local_time);
  printf("Packet timestamp: %s\n", time_buffer);

  // Print the packet data in hexadecimal format
  printf("Packet data:\n");
  for (i = 0; i < header->caplen; i++) {
    printf("%02x ", packet[i]);
    if ((i + 1) % 16 == 0) {
      printf("\n");
    }
  }

  printf("\n\n");
}

int main() {
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];
  char *device;
  bpf_u_int32 netmask;
  bpf_u_int32 ip;

  // Get the default network interface
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    fprintf(stderr, "Error getting default network interface: %s\n", errbuf);
    return 1;
  }

  // Get the network mask for the default interface
  if (pcap_lookupnet(device, &ip, &netmask, errbuf) == -1) {
    fprintf(stderr, "Error getting network mask: %s\n", errbuf);
    return 1;
  }

  // Open the network interface for packet capture
  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening network interface: %s\n", errbuf);
    return 1;
  }

  // Set the packet filter
  struct bpf_program filter;
  if (pcap_compile(handle, &filter, "tcp and port 80", 1, netmask) == -1) {
    fprintf(stderr, "Error compiling packet filter: %s\n", pcap_geterr(handle));
    return 1;
  }
  if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Error setting packet filter: %s\n", pcap_geterr(handle));
    return 1;
  }

  // Start the packet capture loop
  int num_packets = 0;
  while (1) {
    int num_received = pcap_dispatch(handle, 10, packet_handler, NULL);
    if (num_received == -1) {
      fprintf(stderr, "Error during packet capture: %s\n", pcap_geterr(handle));
      break;
    } else if (num_received > 0) {
      num_packets += num_received;
      printf("Received %d packets.\n", num_received);
    }
  }

  // Close the network interface
  pcap_close(handle);

  printf("Total packets received: %d\n", num_packets);

  return 0;
}