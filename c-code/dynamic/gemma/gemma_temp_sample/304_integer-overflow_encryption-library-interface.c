#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdint.h>

int encrypt(int key, int message) {
  int result = 0;
  int overflow_value = key * message;

  if (overflow_value < 0) {
    result = -1;
  } else {
    result = overflow_value;
  }

  return result;
}

int main() {
  int key = 10;
  int message = 5;

  int encrypted_message = encrypt(key, message);

  if (encrypted_message == -1) {
    printf("Error: Integer overflow.\n");
  } else {
    printf("Encrypted message: %d\n", encrypted_message);
  }

  return 0;
}
