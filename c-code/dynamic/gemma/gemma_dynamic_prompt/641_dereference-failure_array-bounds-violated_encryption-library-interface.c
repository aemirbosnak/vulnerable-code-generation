#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int key[] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0};
  char *message = "Secret message";
  int message_length = strlen(message) + 1;
  char *encrypted_message = NULL;

  encrypted_message = malloc(message_length * 2);

  // Array bounds violation - write beyond the allocated memory
  encrypted_message[message_length * 2 - 1] = 0xdeadbeef;

  // Encryption logic (omitted for brevity)

  printf("Encrypted message: %s", encrypted_message);

  free(encrypted_message);

  return 0;
}
