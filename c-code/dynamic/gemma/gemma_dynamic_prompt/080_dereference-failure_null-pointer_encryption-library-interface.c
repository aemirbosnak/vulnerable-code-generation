#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *key, char *msg) {
  // Allocate memory for the encrypted message
  char *enc_msg = malloc(strlen(msg) + 1);

  // Null pointer dereference
  *(enc_msg + 10) = msg;

  // Do something with the encrypted message
  printf("Encryped message: %s", enc_msg);
}

int main() {
  char *key = "secret";
  char *msg = "Hello, world!";

  encrypt(key, msg);

  return 0;
}
