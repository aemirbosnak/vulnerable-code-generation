//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
  int subnet_mask;
  char ip_address[15], subnet_ip[15], broadcast_ip[15], network_ip[15], subnet_bits[15];

  printf("Enter IP address: ");
  scanf("%s", ip_address);

  printf("Enter subnet mask: ");
  scanf("%d", &subnet_mask);

  // clear the arrays
  memset(subnet_ip, '\0', sizeof(subnet_ip));
  memset(broadcast_ip, '\0', sizeof(broadcast_ip));
  memset(network_ip, '\0', sizeof(network_ip));
  memset(subnet_bits, '\0', sizeof(subnet_bits));

  // get the subnet bits
  for (int i = 0; i < 32; i++) {
    if (i < subnet_mask) {
      subnet_bits[i] = '1';
    } else {
      subnet_bits[i] = '0';
    }
  }

  // calculate the subnet mask
  for (int i = 0; i < 4; i++) {
    int pos = i * 8;
    int count = 0;
    for (int j = pos; j < pos + 8; j++) {
      if (subnet_bits[j] == '1') {
        count += 1 << (7 - (j % 8));
      }
    }
    sprintf(subnet_ip + strlen(subnet_ip), "%d.", count);
  }
  subnet_ip[strlen(subnet_ip) - 1] = '\0';

  // calculate the network ip
  for (int i = 0; i < 4; i++) {
    network_ip[i] = subnet_ip[i] & ip_address[i];
  }

  // calculate the broadcast ip
  for (int i = 0; i < 4; i++) {
    broadcast_ip[i] = network_ip[i] | (~subnet_ip[i] & 0xff);
  }

  // print the results
  printf("Subnet IP: %s\n", subnet_ip);
  printf("Network IP: %s\n", network_ip);
  printf("Broadcast IP: %s\n", broadcast_ip);

  return 0;
}