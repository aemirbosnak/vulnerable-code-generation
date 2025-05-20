//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
  int subnet_mask;
  char ip_address[16];
  int first_octet = 0;
  int second_octet = 0;
  int third_octet = 0;
  int fourth_octet = 0;
  int subnet_octet = 0;
  int subnet_bits = 0;
  int subnet_decimal = 0;
  int subnet_mask_binary[32] = {0};
  int ones = 0;
  int twos = 0;
  int threes = 0;
  int fours = 0;
  
  printf("Enter an IP address in dotted decimal notation (ex. 192.168.1.1): ");
  scanf("%s", ip_address);
  printf("\nEnter a subnet mask in CIDR notation (ex. 24): ");
  scanf("%d", &subnet_mask);
  
  // Parse IP address
  sscanf(ip_address, "%d.%d.%d.%d", &first_octet, &second_octet, &third_octet, &fourth_octet);
  
  // Calculate subnet bits
  ones = subnet_mask / 8;
  subnet_bits = subnet_mask % 8;
  
  // Set subnet mask binary array
  for(int i = 0; i < subnet_bits; i++) {
    subnet_mask_binary[i] = 1;
  }
  
  // Set subnet octet
  for(int i = 0; i < 8; i++) {
    if(subnet_mask_binary[i] == 1) {
      subnet_decimal += pow(2, 7 - i);
    }
  }
  subnet_octet = subnet_decimal;
  
  // Print results
  printf("\nIP Address: %d.%d.%d.%d", first_octet, second_octet, third_octet, fourth_octet);
  printf("\nSubnet Mask: %d.%d.%d.%d", subnet_octet, subnet_octet, subnet_octet, subnet_octet);
  printf("\nSubnet Bits: %d", subnet_bits);
  printf("\nNetwork Address: %d.%d.%d.%d", first_octet & subnet_octet, second_octet & subnet_octet, third_octet & subnet_octet, fourth_octet & subnet_octet);
  
  // Calculate and print Number of Hosts
  if(subnet_mask <= 24) {
    ones = subnet_mask / 8;
    twos = (subnet_mask % 8) - 1;
    printf("\nNumber of Hosts: %d", pow(2, (8 - ones - twos)) - 2);
  } else if(subnet_mask > 24 && subnet_mask <= 30) {
    ones = subnet_mask - 24;
    printf("\nNumber of Hosts: %d", pow(2, (8 - ones)) - 2);
  } else {
    printf("\nNumber of Hosts: 1");
  }
  
  // Calculate and print Subnet ID
  if(subnet_mask <= 24) {
    ones = subnet_mask / 8;
    twos = (subnet_mask % 8) - 1;
    threes = 8 - ones - twos;
    
    int network_octets[4] = {first_octet & subnet_octet, second_octet & subnet_octet, third_octet & subnet_octet, fourth_octet & subnet_octet};
    int ones_decimal = pow(2, (8 - ones)) - 1;
    int twos_decimal = pow(2, twos) - 1;
    
    int subnet_id_octet = fourth_octet & subnet_octet;
    for(int i = 0; i < (threes - 1); i++) {
      subnet_id_octet += (network_octets[ones + i] & ones_decimal) * pow(2, (8 * (i + 1)));
    }
    subnet_id_octet += ((network_octets[ones + threes - 1] & twos_decimal) * pow(2, (8 * threes)));
    
    printf("\nSubnet ID: %d.%d.%d.%d", network_octets[0], network_octets[1], network_octets[2], subnet_id_octet);
  } else {
    printf("\nSubnet ID: %d.%d.%d.%d", first_octet, second_octet, third_octet, fourth_octet & subnet_octet);
  }
  
  // Calculate and print Broadcast Address
  if(subnet_mask <= 24) {
    ones = subnet_mask / 8;
    twos = (subnet_mask % 8) - 1;
    threes = 8 - ones - twos;
    
    int network_octets[4] = {first_octet & subnet_octet, second_octet & subnet_octet, third_octet & subnet_octet, fourth_octet & subnet_octet};
    int ones_decimal = pow(2, (8 - ones)) - 1;
    int twos_decimal = pow(2, twos) - 1;
    
    int subnet_id_octet = fourth_octet & subnet_octet;
    for(int i = 0; i < (threes - 1); i++) {
      subnet_id_octet += (network_octets[ones + i] & ones_decimal) * pow(2, (8 * (i + 1)));
    }
    subnet_id_octet += ((network_octets[ones + threes - 1] & twos_decimal) * pow(2, (8 * threes)));
    
    int broadcast_octet = subnet_id_octet + (unsigned char)(pow(2, (8 - subnet_bits)) - 1);
    
    printf("\nBroadcast Address: %d.%d.%d.%d", network_octets[0], network_octets[1], network_octets[2], broadcast_octet);
  } else {
    int broadcast_octet = fourth_octet & subnet_octet + (unsigned char)(pow(2, (8 - subnet_bits)) - 1);
    
    printf("\nBroadcast Address: %d.%d.%d.%d", first_octet, second_octet, third_octet, broadcast_octet);
  }
  
  return 0;
}