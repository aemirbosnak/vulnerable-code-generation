//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  //variable declaration
  char ip_address[16], subnet_mask[16];
  int subnet_bits, subnet_mask_binary[32], subnet_mask_decimal[4], wildcard_bits,
      num_addresses, host_bits, max_num_hosts;

  //user input
  printf("Enter IP Address (e.g. 192.168.0.1): ");
  scanf("%s", ip_address);

  printf("Enter Subnet Mask (e.g 255.255.255.0): ");
  scanf("%s", subnet_mask);

  //converting subnet mask into binary
  char *token;
  token = strtok(subnet_mask, ".");
 
  int i = 0;
  while (token != NULL)
  {
    subnet_mask_decimal[i] = atoi(token); //converting subnet mask from string to decimal
    i++;
    token = strtok(NULL, ".");
  }

  for (i = 0; i < 4; i++)
  {
    int j = 7;
    int num = subnet_mask_decimal[i];
    while (j >= 0)
    {
      subnet_mask_binary[i * 8 + j] = num % 2; //converting decimal to binary
      num /= 2;
      j--;
    }
  }

  //calculating subnet bits and wildcard bits
  for (i = 0; i < 32; i++)
  {
    if (subnet_mask_binary[i] == 0)
    {
      subnet_bits = i;
      wildcard_bits = 32 - subnet_bits;
      break;
    }
  }

  //calculating number of addresses and host bits
  num_addresses = 1 << wildcard_bits;
  host_bits = 32 - subnet_bits;
  max_num_hosts = num_addresses - 2; //excluding network and broadcast address

  //displaying results
  printf("\n---------------------------------------\n");
  printf("IP Address      : %s\n", ip_address);
  printf("Subnet Mask     : %s\n", subnet_mask);
  printf("Subnet Bits     : %d\n", subnet_bits);
  printf("Wildcard Bits   : %d\n", wildcard_bits);
  printf("Number of Hosts : %d\n", max_num_hosts);

  return 0;
}