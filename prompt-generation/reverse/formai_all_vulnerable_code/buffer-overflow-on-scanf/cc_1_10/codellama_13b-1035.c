//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[16];
  printf("Enter a subnet mask: ");
  scanf("%s", input);
  int mask = strtol(input, NULL, 10);
  int net = 0;
  int host = 0;

  switch (mask) {
    case 24:
      net = 255;
      host = 24;
      break;
    case 25:
      net = 255;
      host = 25;
      break;
    case 26:
      net = 255;
      host = 26;
      break;
    case 27:
      net = 255;
      host = 27;
      break;
    case 28:
      net = 255;
      host = 28;
      break;
    case 29:
      net = 255;
      host = 29;
      break;
    case 30:
      net = 255;
      host = 30;
      break;
    case 31:
      net = 255;
      host = 31;
      break;
    default:
      printf("Invalid subnet mask\n");
      return 1;
  }

  int subnet = net << host;
  int host_ip = 0;

  if (host_ip < subnet) {
    host_ip = host_ip + subnet;
  } else {
    host_ip = host_ip - subnet;
  }

  printf("Subnet: %d.%d.%d.%d\n", (subnet >> 24) & 0xFF, (subnet >> 16) & 0xFF, (subnet >> 8) & 0xFF, subnet & 0xFF);
  printf("Host IP: %d.%d.%d.%d\n", (host_ip >> 24) & 0xFF, (host_ip >> 16) & 0xFF, (host_ip >> 8) & 0xFF, host_ip & 0xFF);

  return 0;
}