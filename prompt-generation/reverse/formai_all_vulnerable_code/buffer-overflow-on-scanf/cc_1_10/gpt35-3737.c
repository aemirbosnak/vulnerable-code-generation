//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

   char ipAddress[16], subnetMask[16];
   int cidr, octet1, octet2, octet3, octet4, subnetOctet1, subnetOctet2, subnetOctet3, subnetOctet4;
   unsigned long subnetMaskValue, wildcardMaskValue, networkAddr, broadcastAddr, numIPs;

   printf("Welcome to the Subnet Calculator! Let's start by entering the IP address: \n");
   scanf("%s", ipAddress);

   printf("\nGreat! Now let's enter the subnet mask - but instead of CIDR notation, let's use the regular dotted decimal notation we're all used to: \n");
   scanf("%s", subnetMask);

   printf("\nAlmost there! Finally, let's enter the CIDR notation for this subnet: \n");
   scanf("%d", &cidr);

   printf("\nCalculating....\n\n");

   //Extracting Octets
   sscanf(ipAddress, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
   sscanf(subnetMask, "%d.%d.%d.%d", &subnetOctet1, &subnetOctet2, &subnetOctet3, &subnetOctet4);

   //Calculating subnet mask
   subnetMaskValue = ((1 << cidr) - 1) << (32 - cidr);
   wildcardMaskValue = ~subnetMaskValue;

   printf("IP Address   : %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
   printf("Subnet Mask  : %d.%d.%d.%d\n", subnetOctet1, subnetOctet2, subnetOctet3, subnetOctet4);
   printf("CIDR         : %d\n", cidr);

   //Calculating Network Address
   networkAddr = (octet1 & subnetOctet1) << 24;
   networkAddr |= (octet2 & subnetOctet2) << 16;
   networkAddr |= (octet3 & subnetOctet3) << 8;
   networkAddr |= (octet4 & subnetOctet4);

   printf("Network Addr : %ld\n", networkAddr);

   //Calculating Broadcast Address
   broadcastAddr = networkAddr | wildcardMaskValue;

   printf("Broadcast Addr : %ld\n", broadcastAddr);

   //Calculating number of IPs
   numIPs = pow(2, 32 - cidr) - 2;

   printf("Number of IPs : %ld\n", numIPs);

   return 0;
} 

/* DISCLAIMER: This calculator is not responsible for any errors in calculation or allocation of IP addresses.
                 Please, don't blame the calculator - blame the guy who wrote it, he was clearly not a subnetting expert. */