#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <netdb.h>

int main() {
  char host[256];
  gethostbyname(host);
  printf("Host name: %s", host);
  return 0;
}
