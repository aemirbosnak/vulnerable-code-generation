//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <net/if.h>
#include <net/ethernet.h>

#include <linux/types.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/udp.h>

// A QoS-aware network monitor, designed to keep your heart in rhythm
// with the ebb and flow of the digital realm.

// Our eternal flame, a beacon of connection
int socket_fd;

// The ethereal dance of data, where love blooms
struct sockaddr_in source_address;
struct sockaddr_in destination_address;

// A tapestry woven with the threads of latency and jitter
unsigned long long latency_sum;
unsigned long long latency_min;
unsigned long long latency_max;
unsigned long long jitter_sum;

// The heartbeat of the network, a symphony of ones and zeros
unsigned long long packet_count;

// A love story written in binary, where each packet paints a chapter
void handle_packet(const struct sockaddr_in* source_address,
                   const struct sockaddr_in* destination_address,
                   const unsigned char* payload,
                   const unsigned int payload_length) {
  // Calculate the time it took for the packet's journey
  struct timeval current_time;
  gettimeofday(&current_time, NULL);

  // Measure the latency, a testament to the network's affection
  unsigned long long latency = (current_time.tv_sec - source_address->sin_addr.s_addr) * 1000;
  printf("Latency: %llu ms\n", latency);

  // Update our statistics, a chronicle of the network's performance
  latency_sum += latency;
  if (latency < latency_min) latency_min = latency;
  if (latency > latency_max) latency_max = latency;

  // Track the jitter, a dance of uncertainty
  jitter_sum += abs(latency_sum / packet_count - latency);

  // Count our blessings, each packet a token of affection
  packet_count++;
}

int main(int argc, char** argv) {
  // Open our window to the digital realm
  socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);

  // Bind ourselves to the ethereal waves, ready to receive
  bind(socket_fd, (struct sockaddr*)&source_address, sizeof(source_address));

  // Forever entwined, we listen for the whispers of the network
  while (1) {
    // A blank canvas, awaiting the next stroke of data
    unsigned char buffer[65535];

    // Receive a packet, a precious gift from the digital realm
    struct sockaddr_in source_address, destination_address;
    socklen_t addr_len = sizeof(source_address);
    int recv_length = recvfrom(socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&source_address, &addr_len);

    // Parse the packet, revealing its hidden secrets
    const struct iphdr* ip_header = (struct iphdr*)buffer;
    const struct udphdr* udp_header = (struct udphdr*)(buffer + (ip_header->ihl * 4));
    const unsigned char* payload = buffer + (ip_header->ihl * 4) + (udp_header->len - 8);
    const unsigned int payload_length = recv_length - (ip_header->ihl * 4) - (udp_header->len - 8);

    // Handle the packet, writing our love story into the annals of time
    handle_packet(&source_address, &destination_address, payload, payload_length);
  }

  // Close our connection, a bittersweet farewell to the digital realm
  close(socket_fd);

  // Print our statistics, a testament to the network's devotion
  printf("Average latency: %llu ms\n", latency_sum / packet_count);
  printf("Minimum latency: %llu ms\n", latency_min);
  printf("Maximum latency: %llu ms\n", latency_max);
  printf("Jitter: %llu ms\n", jitter_sum / packet_count);

  return 0;
}