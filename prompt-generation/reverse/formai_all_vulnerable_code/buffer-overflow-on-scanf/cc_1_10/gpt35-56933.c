//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Define variables */
char ip_addr[16];
int subnet_mask;
char subnet_cidr[4];
char subnet_mask_bin[33];
char subnet_first[16];
char subnet_last[16];
char subnet_broadcast[16];

/* Function to convert IP address to binary */
void ip_to_bin(char *ip_addr, char *ip_addr_bin) {
  int ip_octet[4], i;
  sscanf(ip_addr, "%d.%d.%d.%d", &ip_octet[0], &ip_octet[1], &ip_octet[2], &ip_octet[3]);
  for (i = 0; i < 4; i++) {
    for (int j = 7; j >= 0; j--) {
      if (ip_octet[i] >= pow(2, j)) {
        ip_addr_bin[strlen(ip_addr_bin)] = '1';
        ip_octet[i] -= pow(2, j);
      } else {
        ip_addr_bin[strlen(ip_addr_bin)] = '0';
      }
    }
  }
}

/* Function to convert subnet mask to CIDR notation */
void mask_to_cidr(int subnet_mask, char *subnet_cidr) {
  for (int i = 0; i < subnet_mask; i++) {
    subnet_cidr[i/8] = '1';
  }
}

/* Function to calculate the subnet details */
void calculate_subnet() {
  /* Declare variables */
  char network_addr_bin[33];
  char subnet_mask_inverted[33];
  char subnet_first_bin[33];
  char subnet_last_bin[33];
  char subnet_broadcast_bin[33];
  char network_addr[16];
  int i;

  /* Convert subnet mask to binary */
  for (i = 0; i < subnet_mask; i++) {
    subnet_mask_bin[i] = '1';
  }
  for (; i < 32; i++) {
    subnet_mask_bin[i] = '0';
  }
  subnet_mask_bin[32] = '\0';

  /* Convert IP address to binary */
  char ip_addr_bin[33] = "";
  ip_to_bin(ip_addr, ip_addr_bin);

  /* Calculate network address in binary */
  for (i = 0; i < 32; i++) {
    if (subnet_mask_bin[i] == '1') {
      network_addr_bin[i] = ip_addr_bin[i];
    } else {
      network_addr_bin[i] = '0';
    }
  }
  network_addr_bin[32] = '\0';

  /* Convert network address to decimal */
  for (i = 0; i < 4; i++) {
    strncpy(network_addr+(i*4), &network_addr_bin[i*8], 3);
    network_addr[i*4+3] = '.';
  }
  network_addr[15] = '\0';

  /* Invert subnet mask */
  for (i = 0; i < 32; i++) {
    if (subnet_mask_bin[i] == '1') {
      subnet_mask_inverted[i] = '0';
    } else {
      subnet_mask_inverted[i] = '1';
    }
  }
  subnet_mask_inverted[32] = '\0';

  /* Calculate first IP address in binary */
  for (i = 0; i < 32; i++) {
    if (subnet_mask_inverted[i] == '1') {
      subnet_first_bin[i] = network_addr_bin[i];
    } else {
      subnet_first_bin[i] = '0';
    }
  }
  subnet_first_bin[32] = '\0';
  subnet_first_bin[31] = '1';

  /* Convert first IP address to decimal */
  for (i = 0; i < 4; i++) {
    strncpy(subnet_first+(i*4), &subnet_first_bin[i*8], 3);
    subnet_first[i*4+3] = '.';
  }
  subnet_first[15] = '\0';

  /* Calculate last IP address in binary */
  for (i = 0; i < 32; i++) {
    if (subnet_mask_inverted[i] == '1') {
      subnet_last_bin[i] = network_addr_bin[i];
    } else {
      subnet_last_bin[i] = '1';
    }
  }
  subnet_last_bin[32] = '\0';
  subnet_last_bin[31] = '0';

  /* Convert last IP address to decimal */
  for (i = 0; i < 4; i++) {
    strncpy(subnet_last+(i*4), &subnet_last_bin[i*8], 3);
    subnet_last[i*4+3] = '.';
  }
  subnet_last[15] = '\0';

  /* Calculate broadcast address in binary */
  for (i = 0; i < 32; i++) {
    if (subnet_mask_bin[i] == '1') {
      subnet_broadcast_bin[i] = ip_addr_bin[i];
    } else {
      subnet_broadcast_bin[i] = '1';
    }
  }
  subnet_broadcast_bin[32] = '\0';

  /* Convert broadcast address to decimal */
  for (i = 0; i < 4; i++) {
    strncpy(subnet_broadcast+(i*4), &subnet_broadcast_bin[i*8], 3);
    subnet_broadcast[i*4+3] = '.';
  }
  subnet_broadcast[15] = '\0';
}

/* Main function */
int main() {
  /* Input IP address and subnet mask */
  printf("Please input IP address and subnet mask in the format xxx.xxx.xxx.xxx/y\n");
  scanf("%s/%d", ip_addr, &subnet_mask);

  /* Calculate subnet details */
  mask_to_cidr(subnet_mask, subnet_cidr);
  calculate_subnet();

  /* Output subnet details */
  printf("IP Address: %s\n", ip_addr);
  printf("Subnet Mask: %s\n", subnet_mask_bin);
  printf("CIDR Notation: /%s\n", subnet_cidr);
  printf("Network Address: %s\n", subnet_first);
  printf("First IP Address: %s\n", subnet_first);
  printf("Last IP Address: %s\n", subnet_last);
  printf("Broadcast Address: %s\n", subnet_broadcast);

  return 0;
}