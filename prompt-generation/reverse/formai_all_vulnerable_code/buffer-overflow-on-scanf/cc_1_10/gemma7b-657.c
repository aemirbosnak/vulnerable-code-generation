//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <math.h>

int main() {
  int subnet_mask_bits, host_bits, network_address, broadcast_address, subnet_mask, hosts_per_subnet;
  char subnet_mask_str[32];

  printf("Enter the subnet mask in binary: ");
  scanf("%s", subnet_mask_str);

  subnet_mask_bits = count_set_bits(subnet_mask_str);
  subnet_mask = calculate_subnet_mask(subnet_mask_bits);
  network_address = calculate_network_address(subnet_mask, subnet_mask_bits);
  broadcast_address = calculate_broadcast_address(network_address, subnet_mask);
  hosts_per_subnet = calculate_hosts_per_subnet(subnet_mask);

  printf("Subnet Mask:** %s\n", subnet_mask_str);
  printf("Network Address:** %d\n", network_address);
  printf("Broadcast Address:** %d\n", broadcast_address);
  printf("Hosts per Subnet:** %d\n", hosts_per_subnet);

  return 0;
}

int count_set_bits(char *str) {
  int i = 0, count = 0;
  while (str[i] != '\0') {
    if (str[i] == '1') {
      count++;
    }
    i++;
  }
  return count;
}

int calculate_subnet_mask(int num_bits) {
  int mask = 0, i = num_bits - 1;
  for (i; i >= 0; i--) {
    mask |= 1 << i;
  }
  return mask;
}

int calculate_network_address(int subnet_mask, int num_bits) {
  int network_address = (subnet_mask & ~((1 << num_bits) - 1)) >> num_bits;
  return network_address;
}

int calculate_broadcast_address(int network_address, int subnet_mask) {
  int broadcast_address = network_address | subnet_mask;
  return broadcast_address;
}

int calculate_hosts_per_subnet(int subnet_mask) {
  int hosts_per_subnet = (subnet_mask & 0xffffff) / 8;
  return hosts_per_subnet;
}