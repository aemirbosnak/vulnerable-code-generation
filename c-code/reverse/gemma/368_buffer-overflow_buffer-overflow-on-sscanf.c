#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char ip[16], mask[16], broadcast[16];
  int i, mask_len, ip_len;

  scanf("%s", ip);
  scanf("%s", mask);

  ip_len = strlen(ip);
  mask_len = strlen(mask);

  sprintf(broadcast, "%s&~%s", ip, mask);
  broadcast[ip_len - 1] = 'b';

  printf("%s\n", broadcast);

  return 0;
}
