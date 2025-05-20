//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void subnet_calculator(char ip_addr[], int subnet_mask, int mode) { 
  
  unsigned long subnet_addr, broadcast_addr;
  int num_hosts;

  char *octet;
  int addr_in[4];
  
  octet = strtok(ip_addr, ".");
  for(int i=0;i<4;i++){
    if (octet == NULL) {
      printf("\nInvalid Ip Address\n");
      exit(0);
    }
    addr_in[i] = atoi(octet);
    octet = strtok(NULL, ".");
  }
  
  if(subnet_mask>32) {
    printf("\nInvalid input for subnet mask\n");
    exit(0);
  }
  
  if(mode == 1) { // subnet mask given
    subnet_addr = (addr_in[0]<<24) | (addr_in[1]<<16) | (addr_in[2]<<8) | addr_in[3];
    subnet_addr = subnet_addr & ((unsigned long)pow(2,subnet_mask)-1)<<(32-subnet_mask);
    broadcast_addr = subnet_addr | (~((unsigned long)pow(2,32-subnet_mask)-1));
    num_hosts = (int)pow(2, 32-subnet_mask) - 2;
  }
  else { // num of hosts given
    num_hosts = mode - 2;
    broadcast_addr = addr_in[3];
    int n = addr_in[3];
    for(int i=0;i<=8;i++){
      n = n | (1<<i); 
      if(n-addr_in[3]>=num_hosts) {
        broadcast_addr = n;
        break;
      }
    }
    subnet_addr = (broadcast_addr & ((unsigned long)pow(2,subnet_mask)-1)<<(32-subnet_mask));
  }
  
  printf("Subnet Address: %d.%d.%d.%d\n", (subnet_addr>>24)&0xff, (subnet_addr>>16)&0xff, (subnet_addr>>8)&0xff, subnet_addr&0xff);
  printf("Broadcast Address: %d.%d.%d.%d\n", (broadcast_addr>>24)&0xff, (broadcast_addr>>16)&0xff, (broadcast_addr>>8)&0xff, broadcast_addr&0xff);
  printf("Number of Hosts: %d\n", num_hosts);
}

int main() {
  
  int mode;
  char ip_addr[16];
  int subnet_mask, num_hosts;

  printf("\nSUBNET CALCULATOR\n");

  printf("\nEnter the Ip Address (Format - XXX.XXX.XXX.XXX): ");
  scanf("%s", ip_addr);

  printf("\n1. If you have subnet mask then Enter 1 \n2. If you have number of hosts required as input then Enter 2 (Choose 1 or 2) : ");
  scanf("%d", &mode);
  
  if(mode == 1) { // subnet mask given
    printf("\nEnter the Subnet Mask (0-32): ");
    scanf("%d", &subnet_mask);

    subnet_calculator(ip_addr, subnet_mask, mode);
  }
  
  else if(mode == 2) { // num of hosts given
    printf("\nEnter the number of hosts required (2-255): ");
    scanf("%d", &num_hosts);
    subnet_mask = 31-ceil(log2(num_hosts+2));

    subnet_calculator(ip_addr, subnet_mask, num_hosts+2);
  }

  else {  
    printf("\nError input. Please enter valid input\n");
  }

  return 0;
}