#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char ip[16];
  scanf("%s", ip);
  ip[15] = '\0';
  printf("Your IP address is: %s", ip);
  return 0;
}
