//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
   char ip_address[15];
   int subnet_mask;
   printf("Enter IP Address (xxx.xxx.xxx.xxx): ");
   scanf("%s",ip_address);
   printf("Enter Subnet Mask (/num): ");
   scanf("%d",&subnet_mask);

   int subnet_octets[4] = {0,0,0,0};
   int temp_octet = 0, temp_sum = 0, temp_mask = subnet_mask;
   int subnet_bits[32] = {0};
   int i = 0, j = 0, k = 0;

   // Convert IP Address
   for (i = 0; i < strlen(ip_address); i++) {
      if (ip_address[i] == '.') {
         subnet_octets[k] = temp_sum;
         temp_sum = 0;
         k++;
      } else {
         temp_sum = temp_sum * 10 + (ip_address[i] - '0');
      }
   }
   subnet_octets[k] = temp_sum;

   // Convert Subnet Mask to Binary
   while (temp_mask > 0) {
      if (temp_mask >= 8) {
         subnet_bits[i] = 1;
         i++;
         temp_mask -= 8;
      } else {
         subnet_bits[i] = pow(2, 8 - temp_mask);
         temp_mask = 0;
      }
   }

   // Calculate Subnet ID
   for (i = 0; i < 4; i++) {
      if (subnet_bits[j] > subnet_octets[i]) {
         subnet_octets[i] = 0;
      } else {
         subnet_octets[i] = subnet_octets[i] - subnet_bits[j];
      }
      j++;
      if (j == 8) {
         j = 0;
      }
   }

   printf("Subnet ID : %d.%d.%d.%d/%d\n",subnet_octets[0],subnet_octets[1],subnet_octets[2],subnet_octets[3],subnet_mask);
   printf("First IP Address : %d.%d.%d.%d\n",subnet_octets[0],subnet_octets[1],subnet_octets[2],subnet_octets[3] + 1);

   // Calculate Broadcast Address
   subnet_octets[3] += pow(2, (8 - temp_mask)) - 1;
   if (subnet_octets[3] > 255) {
      subnet_octets[2] += subnet_octets[3] / 256;
      subnet_octets[3] = subnet_octets[3] % 256;
   }
   if (subnet_octets[2] > 255) {
      subnet_octets[1] += subnet_octets[2] / 256;
      subnet_octets[2] = subnet_octets[2] % 256; 
   }
   if (subnet_octets[1] > 255) {
      subnet_octets[0] += subnet_octets[1] / 256;
      subnet_octets[1] = subnet_octets[1] % 256;
   }
   printf("Broadcast Address : %d.%d.%d.%d\n",subnet_octets[0],subnet_octets[1],subnet_octets[2],subnet_octets[3]);

   return 0;
}