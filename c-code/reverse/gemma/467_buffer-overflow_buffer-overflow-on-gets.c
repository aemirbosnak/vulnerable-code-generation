#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char message[1024];
  int key;
  char cipher_type;

  printf("Enter cipher type (C, M, A): ");
  scanf("%c", &cipher_type);

  printf("Enter message: ");
  scanf("%s", message);

  printf("Enter key: ");
  scanf("%d", &key);

  switch (cipher_type) {
    case 'C':
      for (int i = 0; message[i] != '\0'; i++) {
        message[i] = (message[i] - 96 + key) % 26 + 96;
      }
      break;
    case 'M':
      for (int i = 0; message[i] != '\0'; i++) {
        message[i] = (message[i] - 96) * key + 96;
      }
      break;
    case 'A':
      for (int i = 0; message[i] != '\0'; i++) {
        message[i] = (message[i] - 96) * key + key + 96;
      }
      break;
    default:
      printf("Invalid cipher type.\n");
  }

  printf("Enciphered message: %s\n", message);

  return 0;
}
