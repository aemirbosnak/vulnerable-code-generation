//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
  if(argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the network interface
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 1000, errbuf);
  if(handle == NULL) {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  // Compile the filter expression
  struct bpf_program fp;
  if(pcap_compile(handle, &fp, "tcp and port 80", 1, PCAP_NETMASK_UNKNOWN) == -1) {
    fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  // Set the filter
  if(pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  // Loop forever and capture packets
  while(1) {
    // Wait for a packet to arrive
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res = pcap_next_ex(handle, &header, &packet);

    // Check for errors
    if(res == -1) {
      fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
      exit(EXIT_FAILURE);
    } else if(res == 0) {
      continue;
    }

    // Parse the packet
    struct ether_header *eth_header = (struct ether_header *)packet;
    struct ip *ip_header = (struct ip *)(packet + sizeof(struct ether_header));
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct ip));

    // Check if the packet is an HTTP request
    if(ip_header->ip_p == IPPROTO_TCP && tcp_header->th_dport == htons(80) && strncmp((char *)packet + sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct tcphdr), "GET ", 4) == 0) {
      // Extract the URL from the packet
      char *url = strchr((char *)packet + sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct tcphdr), ' ') + 1;
      *strchr(url, ' ') = '\0';

      // Check if the URL is suspicious
      if(strstr(url, "malware") || strstr(url, "phishing")) {
        // Log the suspicious activity
        printf("Suspicious activity detected: %s\n", url);
      }
    }
  }

  // Close the network interface
  pcap_close(handle);

  return EXIT_SUCCESS;
}