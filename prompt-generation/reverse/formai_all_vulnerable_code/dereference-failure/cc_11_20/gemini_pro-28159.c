//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <pcap.h>

#define MAX_DEVICES 100

typedef struct {
  char name[100];
  char mac[20];
  int channel;
  int signal;
  int noise;
} device_t;

int main(int argc, char *argv[]) {
  // Check if the user specified an interface to scan
  if (argc < 2) {
    printf("Usage: %s <interface>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the specified interface for packet capture
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle = pcap_open_live(argv[1], 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening interface: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Start the packet capture loop
  struct pcap_pkthdr *header;
  const u_char *packet;
  int res;
  while ((res = pcap_next_ex(handle, &header, &packet)) >= 0) {
    // Check if the packet is a beacon frame from a wireless access point
    if (header->len < 100 || packet[0] != 0x80 || packet[1] != 0x00) {
      continue;
    }

    // Parse the beacon frame and extract the SSID and BSSID
    char ssid[100];
    char bssid[20];
    int channel = 0;
    int signal = 0;
    int noise = 0;
    int offset = 36;
    while (offset < header->len) {
      int tag_type = packet[offset++];
      int tag_length = packet[offset++];
      if (tag_type == 0) {
        break;
      } else if (tag_type == 1) {
        memcpy(ssid, packet + offset, tag_length);
        ssid[tag_length] = '\0';
      } else if (tag_type == 3) {
        memcpy(bssid, packet + offset, 6);
      } else if (tag_type == 39) {
        channel = packet[offset];
      } else if (tag_type == 66) {
        signal = (int)packet[offset];
      } else if (tag_type == 69) {
        noise = (int)packet[offset];
      }
      offset += tag_length;
    }

    // Print the SSID, BSSID, and other information
    printf("%s (%s)\n", ssid, bssid);
    printf("Channel: %d\n", channel);
    printf("Signal: %d dBm\n", signal);
    printf("Noise: %d dBm\n", noise);
    printf("\n");
  }

  // Stop the packet capture loop and close the interface
  pcap_close(handle);

  return EXIT_SUCCESS;
}