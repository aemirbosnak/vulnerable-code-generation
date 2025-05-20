#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char ip_address[16];
  printf("Enter an IPv4 address: ");
  scanf("%s", ip_address);

  // Validate input length
  if (strlen(ip_address) != 11) {
    printf("Error: Invalid input length.\n");
    return 1;
  }

  // Check for invalid characters
  for (int i = 0; i < strlen(ip_address); i++) {
    if (!((ip_address[i] >= '0' && ip_address[i] <= '9') || ip_address[i] == '.')) {
      printf("Error: Invalid characters.\n");
      return 1;
    }
  }

  // Convert to binary
  int octets[4];
  char *p = ip_address;
  int i = 0;
  for (octets[i] = atoi(p); p++ && i < 3; octets[i++] = atoi(p));

  // Display binary
  printf("IPv4 address in binary: ");
  for (int i = 0; i < 4; i++) {
    printf("%d ", octets[i]);
  }
  printf("\n");

  return 0;
}
