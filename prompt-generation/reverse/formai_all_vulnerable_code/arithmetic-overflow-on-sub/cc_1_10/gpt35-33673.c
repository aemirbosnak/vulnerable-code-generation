//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include<stdio.h>

int main(){
   int ip1,ip2,ip3,ip4,subnetBits,newIp1,newIp2,newIp3,newIp4,hosts,maxHosts;
   int subnet_octet=0;
   int maskLength=0,subnetMask=0,subnet_no=0;

   printf("Enter IP address octet 1: ");
   scanf("%d",&ip1);

   printf("Enter IP address octet 2: ");
   scanf("%d",&ip2);

   printf("Enter IP address octet 3: ");
   scanf("%d",&ip3);

   printf("Enter IP address octet 4: ");
   scanf("%d",&ip4);

   printf("Enter number of subnet bits: ");
   scanf("%d",&subnetBits);

   //Calculating the subnet mask
   for(int i=0;i<subnetBits;i++){
      if(maskLength<8){
         subnetMask+=1<<7-maskLength;
         maskLength++;
      }
      else{
         maskLength=1;
         subnet_octet++;
         subnetMask+=128;
      }
   }

   //Calculating the maximum number of hosts
   maxHosts=1<<(32-subnetBits)-2;

   //Calculating the new IP address
   newIp1=ip1&(subnetMask>>24);
   newIp2=ip2&(subnetMask>>16);
   newIp3=ip3&(subnetMask>>8);
   newIp4=ip4&subnetMask;

   //Calculating the subnet number
   subnet_no=newIp4/maxHosts+1;

   printf("\nSubnet Mask is: %d.%d.%d.%d\n",subnetMask>>24,(subnetMask>>16)&0xFF,(subnetMask>>8)&0xFF,subnetMask&0xFF);
   printf("\nMaximum Number of Hosts : %d\n",maxHosts);
   printf("\nNew IP Address is: %d.%d.%d.%d\n",newIp1,newIp2,newIp3,newIp4);
   printf("\nSubnet Number is: %d\n",subnet_no);

   return 0;
}