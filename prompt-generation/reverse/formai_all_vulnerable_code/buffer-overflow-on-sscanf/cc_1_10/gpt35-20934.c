//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>

int main() {
  // Greeting message
  printf("Welcome to the Subnet Calculator!\n");
  
  // Prompt user for input
  printf("Please enter an IP address: ");
  char ipAddress[15];
  scanf("%s", ipAddress);
  
  // Convert IP address to binary
  int octet1, octet2, octet3, octet4;
  sscanf(ipAddress, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
  int binaryIP[32];
  
  for (int i = 0; i < 8; i++) {
    binaryIP[i] = (octet1 >> i) & 1;
    binaryIP[8+i] = (octet2 >> i) & 1;
    binaryIP[16+i] = (octet3 >> i) & 1;
    binaryIP[24+i] = (octet4 >> i) & 1;
  }
  
  // Prompt user for subnet mask
  printf("Please enter a subnet mask (in decimal form): ");
  int subnetMask;
  scanf("%d", &subnetMask);
  
  // Calculate prefix length
  int prefixLength = 0;
  
  for (int i = 0; i < 32; i++) {
    if (subnetMask >= pow(2, 31-i)) {
      prefixLength++;
      subnetMask -= pow(2, 31-i);
    }
  }
  
  // Print subnet information
  printf("\nSubnet Information:\n");
  printf("IP address: %s\n", ipAddress);
  printf("Subnet mask: %d\n", prefixLength);
  
  // Calculate network address
  int networkAddress[32];
  
  for (int i = 0; i < prefixLength; i++) {
    networkAddress[i] = binaryIP[i];
  }
  
  for (int i = prefixLength; i < 32; i++) {
    networkAddress[i] = 0;
  }
  
  int networkOctet1 = 0, networkOctet2 = 0, networkOctet3 = 0, networkOctet4 = 0;
  
  for (int i = 0; i < 8; i++) {
    networkOctet1 += pow(2, 7-i) * networkAddress[i];
    networkOctet2 += pow(2, 7-i) * networkAddress[8+i];
    networkOctet3 += pow(2, 7-i) * networkAddress[16+i];
    networkOctet4 += pow(2, 7-i) * networkAddress[24+i];
  }
  
  printf("Network address: %d.%d.%d.%d\n", networkOctet1, networkOctet2, networkOctet3, networkOctet4);
  
  // Calculate broadcast address
  int broadcastAddress[32];
  
  for (int i = 0; i < prefixLength; i++) {
    broadcastAddress[i] = binaryIP[i];
  }
  
  for (int i = prefixLength; i < 32; i++) {
    broadcastAddress[i] = 1;
  }
  
  int broadcastOctet1 = 0, broadcastOctet2 = 0, broadcastOctet3 = 0, broadcastOctet4 = 0;
  
  for (int i = 0; i < 8; i++) {
    broadcastOctet1 += pow(2, 7-i) * broadcastAddress[i];
    broadcastOctet2 += pow(2, 7-i) * broadcastAddress[8+i];
    broadcastOctet3 += pow(2, 7-i) * broadcastAddress[16+i];
    broadcastOctet4 += pow(2, 7-i) * broadcastAddress[24+i];
  }
  
  printf("Broadcast address: %d.%d.%d.%d\n", broadcastOctet1, broadcastOctet2, broadcastOctet3, broadcastOctet4);
  
  // Calculate number of hosts
  int numHosts = pow(2, 32-prefixLength) - 2;
  printf("Number of hosts: %d\n", numHosts);
  
  // Farewell message
  printf("\nThank you for using the Subnet Calculator!\n");
  
  return 0;
}