//FormAI DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
// This is a firewall program written in C
// inspired by the analytical engine of Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for IP address
typedef struct IPAddress {
  int octet1, octet2, octet3, octet4;
} IPAddress;

// Define a structure for firewall rules
typedef struct FirewallRule {
  char protocol[10];
  IPAddress ipStart;
  IPAddress ipEnd;
  int portStart;
  int portEnd;
} FirewallRule;

int main() {
  // Initialize firewall rules
  FirewallRule rules[5];
  strcpy(rules[0].protocol, "TCP");
  rules[0].ipStart.octet1 = 10;
  rules[0].ipStart.octet2 = 0;
  rules[0].ipStart.octet3 = 0;
  rules[0].ipStart.octet4 = 1;
  rules[0].ipEnd.octet1 = 10;
  rules[0].ipEnd.octet2 = 255;
  rules[0].ipEnd.octet3 = 255;
  rules[0].ipEnd.octet4 = 255;
  rules[0].portStart = 80;
  rules[0].portEnd = 80;

  strcpy(rules[1].protocol, "UDP");
  rules[1].ipStart.octet1 = 192;
  rules[1].ipStart.octet2 = 168;
  rules[1].ipStart.octet3 = 0;
  rules[1].ipStart.octet4 = 1;
  rules[1].ipEnd.octet1 = 192;
  rules[1].ipEnd.octet2 = 168;
  rules[1].ipEnd.octet3 = 0;
  rules[1].ipEnd.octet4 = 255;
  rules[1].portStart = 22;
  rules[1].portEnd = 22;

  strcpy(rules[2].protocol, "UDP");
  rules[2].ipStart.octet1 = 0;
  rules[2].ipStart.octet2 = 0;
  rules[2].ipStart.octet3 = 0;
  rules[2].ipStart.octet4 = 0;
  rules[2].ipEnd.octet1 = 255;
  rules[2].ipEnd.octet2 = 255;
  rules[2].ipEnd.octet3 = 255;
  rules[2].ipEnd.octet4 = 255;
  rules[2].portStart = 0;
  rules[2].portEnd = 1024;

  strcpy(rules[3].protocol, "TCP");
  rules[3].ipStart.octet1 = 172;
  rules[3].ipStart.octet2 = 16;
  rules[3].ipStart.octet3 = 0;
  rules[3].ipStart.octet4 = 1;
  rules[3].ipEnd.octet1 = 172;
  rules[3].ipEnd.octet2 = 31;
  rules[3].ipEnd.octet3 = 255;
  rules[3].ipEnd.octet4 = 255;
  rules[3].portStart = 0;
  rules[3].portEnd = 1024;

  strcpy(rules[4].protocol, "TCP");
  rules[4].ipStart.octet1 = 127;
  rules[4].ipStart.octet2 = 0;
  rules[4].ipStart.octet3 = 0;
  rules[4].ipStart.octet4 = 1;
  rules[4].ipEnd.octet1 = 127;
  rules[4].ipEnd.octet2 = 255;
  rules[4].ipEnd.octet3 = 255;
  rules[4].ipEnd.octet4 = 255;
  rules[4].portStart = 0;
  rules[4].portEnd = 1024;

  // Get input from user
  IPAddress userIP;
  printf("Enter your IP address:\n");
  scanf("%d.%d.%d.%d", &userIP.octet1, &userIP.octet2, &userIP.octet3, &userIP.octet4);
  int userPort;
  printf("Enter the port you want to access:\n");
  scanf("%d", &userPort);
  char userProtocol[10];
  printf("Enter the protocol you want to use (TCP or UDP):\n");
  scanf("%s", userProtocol);

  // Check rules to see if user is allowed access
  for(int i = 0; i < 5; i++) {
    if(strcmp(rules[i].protocol, userProtocol) == 0 &&
       rules[i].ipStart.octet1 <= userIP.octet1 &&
       rules[i].ipEnd.octet1 >= userIP.octet1 &&
       rules[i].ipStart.octet2 <= userIP.octet2 &&
       rules[i].ipEnd.octet2 >= userIP.octet2 &&
       rules[i].ipStart.octet3 <= userIP.octet3 &&
       rules[i].ipEnd.octet3 >= userIP.octet3 &&
       rules[i].ipStart.octet4 <= userIP.octet4 &&
       rules[i].ipEnd.octet4 >= userIP.octet4 &&
       rules[i].portStart <= userPort &&
       rules[i].portEnd >= userPort) {
      printf("Access granted!\n");
      return 0;
    }
  }

  printf("Access denied.\n");

  return 0;
}