#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char message[100];
  int key;

  printf("Enter a message: ");
  scanf("%s", message);

  printf("Enter a key (integer): ");
  scanf("%d", &key);

  // Caesar cipher
  char caesar_cipher(char letter, int key) {
    int offset = key;
    if (letter >= 'a' && letter <= 'z') {
      offset += 26;
    }
    return (letter - 'a' + offset) % 26 + 'a';
  }

  // Multiplicative cipher
  char multiplicative_cipher(char letter, int key) {
    int multiplier = key;
    if (letter >= 'a' && letter <= 'z') {
      multiplier = multiplier % 26;
    }
    return (letter - 'a' + multiplier) % 26 + 'a';
  }

  // Affine cipher
  char affine_cipher(char letter, int a, int b) {
    int k = a;
    int n = b;
    if (letter >= 'a' && letter <= 'z') {
      k = k % 26;
      n = n % 26;
    }
    return (letter - 'a' + k * n) % 26 + 'a';
  }

  // Apply chosen cipher
  switch (key) {
    case 1:
      printf("Enciphered message: %s", caesar_cipher(message, key));
      break;
    case 2:
      printf("Enciphered message: %s", multiplicative_cipher(message, key));
      break;
    case 3:
      printf("Enciphered message: %s", affine_cipher(message, key, key));
      break;
    default:
      printf("Invalid key");
  }

  return 0;
}
