//FormAI DATASET v1.0 Category: modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Encrypt(char plaintext[], int key) {
  int i;
  char encrypted[strlen(plaintext) + 1];

  for(i = 0; i < strlen(plaintext); i++) {
    char character = plaintext[i];

    if(character >= 'A' && character <= 'Z') {
      character = ((character - 'A' + key) % 26) + 'A';
    } else if(character >= 'a' && character <= 'z') {
      character = ((character - 'a' + key) % 26) + 'a';
    }

    encrypted[i] = character;
  }

  encrypted[i] = '\0';

  printf("Encrypted text: %s\n", encrypted);
}

void Decrypt(char ciphertext[], int key) {
  int i;
  char decrypted[strlen(ciphertext) + 1];

  for(i=0; i<strlen(ciphertext); i++) {
    char character = ciphertext[i];

    if(character >= 'A' && character <= 'Z') {
      character = ((character - 'A' - key + 26) % 26) + 'A';
    } else if(character >= 'a' && character <= 'z') {
      character = ((character - 'a' - key + 26) % 26) + 'a';
    }

    decrypted[i] = character;
  }

  decrypted[i] = '\0';

  printf("Decrypted text: %s\n", decrypted);
}

int main() {
  char plaintext[100];
  int key;

  printf("Enter text to be encrypted: ");
  gets(plaintext);

  printf("Enter key: ");
  scanf("%d", &key);

  printf("\nOriginal text: %s\n", plaintext);

  Encrypt(plaintext, key);
  Decrypt("Qebnrfzhyr", 13); // Check if decryption is working

  return 0;
}