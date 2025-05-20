//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   char ipAddress[20], subnetMask[20];
   int splitAddress[4], splitMask[4], binaryAddress[32], binaryMask[32], subnetSize, i, j;
   unsigned int netAddress, broadcastAddress;

   // Taking user input
   printf("Enter IP Address in dotted decimal format: ");
   scanf("%s", ipAddress);
   printf("Enter Subnet Mask in dotted decimal format: ");
   scanf("%s", subnetMask);

   // Splitting IP address and subnet mask into octets
   sscanf(ipAddress, "%d.%d.%d.%d", &splitAddress[0], &splitAddress[1], &splitAddress[2], &splitAddress[3]);
   sscanf(subnetMask, "%d.%d.%d.%d", &splitMask[0], &splitMask[1], &splitMask[2], &splitMask[3]);

   // Calculating binary representation of IP address and subnet mask
   for(i = 0; i < 4; i++)
   {
      for(j = 0; j < 8; j++)
      {
         binaryAddress[i * 8 + j] = (splitAddress[i] >> (7 - j)) & 1;
         binaryMask[i * 8 + j] = (splitMask[i] >> (7 - j)) & 1;
      }
   }

   // Calculating subnet size
   subnetSize = 0;
   for(i = 0; i < 32 && binaryMask[i] == 1; i++)
   {
      subnetSize++;
   }

   // Calculating network and broadcast addresses
   netAddress = 0;
   broadcastAddress = 0;
   for(i = 0; i < 32; i++)
   {
      if(i < subnetSize)
      {
         netAddress |= binaryAddress[i] << (31 - i);
         broadcastAddress |= binaryAddress[i] << (31 - i);
      }
      else
      {
         broadcastAddress |= 1 << (31 - i);
      }
   }

   printf("\n");
   printf("IP Address: %s\n", ipAddress);
   printf("Subnet Mask: %s\n", subnetMask);
   printf("Network Address: %d.%d.%d.%d\n", netAddress >> 24, (netAddress >> 16) & 0xFF, (netAddress >> 8) & 0xFF, netAddress & 0xFF);
   printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress >> 24, (broadcastAddress >> 16) & 0xFF, (broadcastAddress >> 8) & 0xFF, broadcastAddress & 0xFF);
   printf("Subnet Size: %d\n", subnetSize);
   printf("\n");

   return 0;
}