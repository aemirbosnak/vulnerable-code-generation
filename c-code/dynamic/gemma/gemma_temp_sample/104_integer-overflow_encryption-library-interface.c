#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int key = 0xDEADBEEF;
  int plaintext = 0x123456;
  int ciphertext = 0;

  // Vulnerable code: Integer overflow
  ciphertext = (key * plaintext) + key;

  // Print the ciphertext
  printf("Ciphertext: %x\n", ciphertext);

  return 0;
}
