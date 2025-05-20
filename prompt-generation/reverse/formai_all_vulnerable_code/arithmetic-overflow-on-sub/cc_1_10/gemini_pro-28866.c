//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Let's set sail and gather our provisions!
  unsigned int ip_address;
  unsigned int subnet_mask;
  unsigned int network_address;
  unsigned int broadcast_address;
  unsigned int num_hosts;
  char ip_address_str[16];
  char subnet_mask_str[16];

  // Raise the Jolly Roger and display our welcome message!
  printf("Ahoy there, matey! Welcome aboard the C Subnet Calculator!\n");
  printf("Shiver me timbers, we'll sail through IP and subnet masks like a kraken through the deep!\n\n");

  // Batten down the hatches and get ready for our adventure!
  while (1) {
    // Haul in the IP address!
    printf("Enter thy IP address, matey (e.g., 192.168.1.100): ");
    scanf("%s", ip_address_str);
    ip_address = inet_addr(ip_address_str);

    // Weigh anchor and retrieve the subnet mask!
    printf("Yo ho ho, now tell us thy subnet mask (e.g., 255.255.255.0): ");
    scanf("%s", subnet_mask_str);
    subnet_mask = inet_addr(subnet_mask_str);

    // Calculate the network address, the beacon of our subnet!
    network_address = ip_address & subnet_mask;
    printf("Avast! The network address be: %s\n", inet_ntoa(network_address));

    // Determine the broadcast address, the final frontier of our subnet!
    broadcast_address = network_address | ~subnet_mask;
    printf("Weigh hey! The broadcast address be: %s\n", inet_ntoa(broadcast_address));

    // Tally the number of hosts, the hearty souls in our subnet!
    num_hosts = (ntohl(broadcast_address) - ntohl(network_address)) - 1;
    printf("Shiver me timbers! There be %u hosts in this subnet!\n", num_hosts);

    // Ask if our intrepid explorer wishes to continue the adventure!
    char choice;
    printf("Heave to, matey! Another calculation or treasure map to chart? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'n') {
      break;
    }
  }

  // Drop anchor and bid farewell to our fellow adventurers!
  printf("All hands abandon ship! Thanks for sailing with us on the C Subnet Calculator!\n");
  return 0;
}