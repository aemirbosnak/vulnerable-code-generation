//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ART_WIDTH 40
#define ART_HEIGHT 6

char art[ART_HEIGHT][ART_WIDTH] = {
  ".-..",
  "--.--",
  "....",
  "..--.",
  "...--",
  "....."
};

void print_art() {
  for (int i = 0; i < ART_HEIGHT; i++) {
    printf("%s\n", art[i]);
  }
}

void encrypt(char *message, int key) {
  for (int i = 0; i < strlen(message); i++) {
    if (isalpha(message[i])) {
      if (isupper(message[i])) {
        message[i] = (((int)message[i] - 65 + key) % 26) + 65;
      } else {
        message[i] = (((int)message[i] - 97 + key) % 26) + 97;
      }
    }
  }
}

int main() {
  char message[100];
  int key;

  printf(" _____\n");
  printf("|_____|\n");
  printf("|  __  |\n");
  printf("|  |  ||\n");
  printf("|__|__|_|\n");
  printf("| Retro Cipher |\n");
  printf("|_____________|\n");
  printf("\n");

  printf("Enter the message to encrypt: ");
  fgets(message, sizeof(message), stdin);
  message[strcspn(message, "\n")] = '\0';

  printf("Enter the encryption key (1-25): ");
  scanf("%d", &key);

  encrypt(message, key);

  printf("\nEncrypted message:\n");
  print_art();

  for (int i = 0; i < strlen(message); i++) {
    printf("%c ", message[i]);
  }
  printf("\n");

  return 0;
}