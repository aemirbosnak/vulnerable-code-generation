//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define PING_SIZE 64

struct ping_packet {
  char data[PING_SIZE];
  time_t timestamp;
};

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in dest_addr;
  memset(&dest_addr, 0, sizeof(dest_addr));
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_addr.s_addr = inet_addr(argv[1]);

  struct ping_packet packet;
  memset(&packet, 0, sizeof(packet));
  packet.timestamp = time(NULL);

  int sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
  if (sent < 0) {
    perror("sendto");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in src_addr;
  socklen_t src_addr_len = sizeof(src_addr);
  int recv = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&src_addr, &src_addr_len);
  if (recv < 0) {
    perror("recvfrom");
    exit(EXIT_FAILURE);
  }

  time_t elapsed = time(NULL) - packet.timestamp;
  printf("Round-trip time: %ld ms\n", elapsed * 1000);

  close(sockfd);
  return EXIT_SUCCESS;
}