#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int key, cipher_choice;

  printf("Enter your message: ");
  gets(message);

  printf("Enter the key (an integer): ");
  scanf("%d", &key);

  printf("Select the cipher type:\n1. Caesar\n2. Multiplicative\n3. Affine\n");
  scanf("%d", &cipher_choice);

  switch (cipher_choice) {
    case 1:
      encrypt_caesar(message, key);
      break;
    case 2:
      encrypt_multiplicative(message, key);
      break;
    case 3:
      encrypt_affine(message, key);
      break;
    default:
      printf("Invalid cipher selection.\n");
  }

  return 0;
}

void encrypt_caesar(char *message, int key) {
  int i = 0;
  while (message[i] != '\0') {
    message[i] = (message[i] - 'a' + key) % 26 + 'a';
    i++;
  }
}

void encrypt_multiplicative(char *message, int key) {
  int i = 0;
  while (message[i] != '\0') {
    message[i] = (message[i] - 'a' + key) * 3 + 'a';
    i++;
  }
}

void encrypt_affine(char *message, int key) {
  int i = 0;
  while (message[i] != '\0') {
    message[i] = (message[i] - 'a' + key) / 2 + 'a';
    i++;
  }
}
