//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subnet {
  unsigned int address;
  unsigned int netmask;
  unsigned int broadcast;
  unsigned int first_host;
  unsigned int last_host;
  unsigned int num_hosts;
  char address_str[16];
  char netmask_str[16];
  char broadcast_str[16];
  char first_host_str[16];
  char last_host_str[16];
};

void calculate_subnet(struct subnet *subnet, unsigned int address, unsigned int netmask) {
  subnet->address = address;
  subnet->netmask = netmask;
  subnet->broadcast = subnet->address | ~subnet->netmask;
  subnet->first_host = subnet->address + 1;
  subnet->last_host = subnet->broadcast - 1;
  subnet->num_hosts = (1 << (32 - subnet->netmask)) - 2;
  sprintf(subnet->address_str, "%u.%u.%u.%u",
          (subnet->address >> 24) & 0xff,
          (subnet->address >> 16) & 0xff,
          (subnet->address >> 8) & 0xff,
          subnet->address & 0xff);
  sprintf(subnet->netmask_str, "%u.%u.%u.%u",
          (subnet->netmask >> 24) & 0xff,
          (subnet->netmask >> 16) & 0xff,
          (subnet->netmask >> 8) & 0xff,
          subnet->netmask & 0xff);
  sprintf(subnet->broadcast_str, "%u.%u.%u.%u",
          (subnet->broadcast >> 24) & 0xff,
          (subnet->broadcast >> 16) & 0xff,
          (subnet->broadcast >> 8) & 0xff,
          subnet->broadcast & 0xff);
  sprintf(subnet->first_host_str, "%u.%u.%u.%u",
          (subnet->first_host >> 24) & 0xff,
          (subnet->first_host >> 16) & 0xff,
          (subnet->first_host >> 8) & 0xff,
          subnet->first_host & 0xff);
  sprintf(subnet->last_host_str, "%u.%u.%u.%u",
          (subnet->last_host >> 24) & 0xff,
          (subnet->last_host >> 16) & 0xff,
          (subnet->last_host >> 8) & 0xff,
          subnet->last_host & 0xff);
}

int main() {
  struct subnet subnet;
  char input[100];
  int i;

  printf("Enter the subnet address and netmask in the format \"x.x.x.x/y\": ");
  scanf("%s", input);

  char *address_str = strtok(input, "/");
  char *netmask_str = strtok(NULL, "/");

  unsigned int address = inet_addr(address_str);
  unsigned int netmask = inet_addr(netmask_str);

  calculate_subnet(&subnet, address, netmask);

  printf("Subnet Information:\n");
  printf("  Address: %s\n", subnet.address_str);
  printf("  Netmask: %s\n", subnet.netmask_str);
  printf("  Broadcast: %s\n", subnet.broadcast_str);
  printf("  First Host: %s\n", subnet.first_host_str);
  printf("  Last Host: %s\n", subnet.last_host_str);
  printf("  Number of Hosts: %u\n", subnet.num_hosts);

  return 0;
}