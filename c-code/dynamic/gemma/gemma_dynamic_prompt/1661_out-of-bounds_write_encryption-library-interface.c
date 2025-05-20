#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *key = "secret";
  char *msg = "Hello, world!";

  // Out-of-bounds write
  *(key + 10) = msg[0];

  printf("Encrpted message: %s", key);

  return 0;
}
