#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *key = "secret";
  char *message = "Hello, world!";
  int length = strlen(message) + 1;
  char *encrypted_message = malloc(length);

  // Out-of-bounds read
  encrypted_message[length - 1] = 'A';

  // Encrypt message
  // (This code would normally use a cryptographic algorithm to encrypt the message)
  memcpy(encrypted_message, message, length);

  // Print encrypted message
  printf("%s", encrypted_message);

  free(encrypted_message);
  return 0;
}
