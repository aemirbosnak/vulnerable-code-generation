//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to calculate number of hosts
int findHosts(int mask) {
     return (1 << (32 - mask)) - 2;
}

//function to convert IP address to binary
void toBinary(int ip[], char binary[]) {
     sprintf(binary, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);    
}

//function to calculate Subnet Mask
void calcSubnetMask(int mask, char subnetMask[]) {
     int i, j;
     for (i = 0; i < 32; i++) {
          if (i < mask)
               subnetMask[i] = '1';
          else
               subnetMask[i] = '0';
          if ((i + 1) % 8 == 0 && i != 31)
               subnetMask[i++] = '.';
     }
     subnetMask[i] = '\0';
}

//function to calculate network ID
void calcNetworkID(int ip[], int mask, char networkId[]) {
     char binary[100];
     toBinary(ip, binary);
     char subnetMask[33];
     calcSubnetMask(mask, subnetMask);

     int n = strlen(binary);
     for (int i = 0; i < n; i++) {
          if (subnetMask[i] == '1')
               networkId[i] = binary[i];
          else
               networkId[i] = '0';
     }
     networkId[n] = '\0';
}

int main() {
     char ipString[16];
     int ip[4];
     int subnetMask;
     char binary[100];

     printf("Enter IP Address (e.g. 192.168.1.10): ");
     scanf("%s", ipString);
     printf("Enter Subnet Mask (e.g. 24): ");
     scanf("%d", &subnetMask);

     sscanf(ipString, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

     char networkId[33];
     calcNetworkID(ip, subnetMask, networkId);

     int hosts = findHosts(subnetMask);

     printf("\nIP ADDRESS: %s", ipString);
     printf("\nSUBNET MASK: %d", subnetMask);
     printf("\nBINARY SUBNET MASK: ");

     calcSubnetMask(subnetMask, binary);
     printf("%s", binary);

     printf("\nNETWORK ID: %s", networkId);
     printf("\nNUMBER OF HOSTS: %d", hosts);

     return 0;
}