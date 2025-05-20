//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LEN 16

typedef struct network {
  char ip[MAX_IP_LEN];
  char mask[MAX_IP_LEN];
  char network[MAX_IP_LEN];
  char broadcast[MAX_IP_LEN];
  unsigned int cidr;
} Network;

void calculate(Network *n) {
  struct in_addr addr, mask;

  inet_aton(n->ip, &addr);
  inet_aton(n->mask, &mask);

  unsigned int ip = ntohl(addr.s_addr);
  unsigned int m = ntohl(mask.s_addr);

  unsigned int net = ip & m;
  unsigned int bcast = net | ~m;

  n->cidr = __builtin_popcount(m);

  inet_ntop(AF_INET, &mask.s_addr, n->mask, sizeof(n->mask));
  inet_ntop(AF_INET, &net, n->network, sizeof(n->network));
  inet_ntop(AF_INET, &bcast, n->broadcast, sizeof(n->broadcast));
}

void print_result(Network *n) {
  printf("IP: %s/%d\n", n->ip, n->cidr);
  printf("Mask: %s\n", n->mask);
  printf("Network: %s\n", n->network);
  printf("Broadcast: %s\n", n->broadcast);
}

void read_input(Network *n) {
  printf("Enter IP address: ");
  scanf("%s", n->ip);

  printf("Enter subnet mask: ");
  scanf("%s", n->mask);
}

int main(int argc, char** argv) {
  Network n;

  read_input(&n);
  calculate(&n);
  print_result(&n);

  return EXIT_SUCCESS;
}