//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

// Cyberpunk-style macros
#define DECRYPT(x) ((x) ^ 0x55)
#define DATA_GRAB(x) (x)

// Main function
int main(int argc, char *argv[]) {
  // Check if arguments are provided
  if (argc < 2) {
    printf("Usage: ./cyberpunk_packet_monitor <interface>\n");
    return -1;
  }

  // Open network interface
  char *interface = argv[1];
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Error opening interface: %s\n", errbuf);
    return -1;
  }

  // Listen for packets
  while (1) {
    // Receive packet
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) continue;
    if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK) {
      printf("Error receiving packet: %s\n", pcap_geterr(handle));
      break;
    }

    // Parse packet header
    printf("[%08x] %02x:%02x:%02x:%02x:%02x:%02x -> %02x:%02x:%02x:%02x:%02x:%02x\n",
           header->ts.tv_sec, DECRYPT(packet[0]), DECRYPT(packet[1]), DECRYPT(packet[2]),
           DECRYPT(packet[3]), DECRYPT(packet[4]), DECRYPT(packet[5]), DECRYPT(packet[6]),
           DECRYPT(packet[7]), DECRYPT(packet[8]), DECRYPT(packet[9]), DECRYPT(packet[10]));

    // Parse packet data
    int offset = 14; // Ethernet header length
    while (offset < header->caplen) {
      // Get protocol type
      int protocol = (int)packet[offset];
      offset++;

      // Parse data based on protocol
      switch (protocol) {
      case DECRYPT(0x06): // TCP
        printf("  [TCP] ");
        offset += 20; // TCP header length
        break;
      case DECRYPT(0x11): // UDP
        printf("  [UDP] ");
        offset += 8; // UDP header length
        break;
      case DECRYPT(0x01): // ICMP
        printf("  [ICMP] ");
        offset += 8; // ICMP header length
        break;
      case DECRYPT(0x02): // IGMP
        printf("  [IGMP] ");
        offset += 8; // IGMP header length
        break;
      default:
        printf("  [Unknown protocol: %02x]\n", protocol);
        break;
      }

      // Parse data payload
      int payload_len = header->caplen - offset;
      if (payload_len > 0) {
        printf("Payload: <%s>\n", DATA_GRAB(packet) + offset);
      }

      offset = header->caplen;
    }

    printf("\n");
  }

  // Close network interface
  pcap_close(handle);

  return 0;
}