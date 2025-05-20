//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>

int main() {

  printf("Wohooo! Welcome to my subnet calculator!\n");

  /* Prompt user for input */
  printf("Please enter IP address in the following format xxx.xxx.xxx.xxx: ");
  char ip_address[16];
  scanf("%15s", ip_address);

  /* Validate user input */
  int ip_values[4];
  int match_count = sscanf(ip_address, "%d.%d.%d.%d", &ip_values[0], 
                                                  &ip_values[1], 
                                                  &ip_values[2], 
                                                  &ip_values[3]);

  if (match_count != 4) {
    printf("Oh no! Invalid IP address entered. Please try again.\n");
    return 1;
  }
  
  /* Prompt user for subnet mask */
  printf("Please enter subnet mask in the following format /xx: ");
  char subnet_mask[4];
  scanf("%3s", subnet_mask);

  /* Validate subnet mask input */
  int mask_value = atoi(subnet_mask+1);

  if (subnet_mask[0] != '/' || mask_value < 1 || mask_value > 32) {
    printf("Oops! Invalid subnet mask entered. Please try again.\n");
    return 1;
  }

  /* Calculate subnet information */
  int subnet_bits = mask_value;
  int host_bits = 32 - mask_value;
  int subnet_count = 1 << subnet_bits;
  int hosts_per_subnet = 1 << host_bits;
  int network_address[4];
  int broadcast_address[4];

  for (int i = 0; i < 4; i++) {

    int network_byte = ip_values[i] & (0xff << (8 - subnet_bits));
    network_address[i] = network_byte;

    int broadcast_byte = network_byte + (0xff >> subnet_bits);
    broadcast_address[i] = broadcast_byte;

  }

  /* Output subnet information */
  printf("\n=================== Subnet Information ===================\n");
  printf("IP Address: %s\n", ip_address);
  printf("Subnet Mask: %s\n", subnet_mask);
  printf("Number of Subnets: %d\n", subnet_count);
  printf("Hosts per Subnet: %d\n", hosts_per_subnet);
  printf("Network Address: %d.%d.%d.%d\n", network_address[0],
                                           network_address[1],
                                           network_address[2],
                                           network_address[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0],
                                             broadcast_address[1],
                                             broadcast_address[2],
                                             broadcast_address[3]);
  printf("============================================================\n");

  return 0;

}