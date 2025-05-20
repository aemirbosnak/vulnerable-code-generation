#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
    return 1;
  }

  char *ip_address = argv[1];
  int subnet_mask = atoi(argv[2]);

  struct in_addr addr;
  addr.s_addr = inet_addr(ip_address);

  int broadcast_addr = addr.s_addr | ~subnet_mask;

  printf("Broadcast address: %s\n", inet_ntoa((struct sockaddr_in *)&broadcast_addr));

  return 0;
}
