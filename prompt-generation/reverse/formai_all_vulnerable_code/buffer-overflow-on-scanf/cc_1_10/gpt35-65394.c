//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 50

// function to encrypt the message
void encrypt(char *message, int shift) {
  int i = 0;
  char ch;

  while (message[i]) {
    ch = message[i];

    // encrypt uppercase characters
    if (ch >= 'A' && ch <= 'Z') {
      ch = ((ch - 'A') + shift) % 26 + 'A';
    }

    // encrypt lowercase characters
    else if (ch >= 'a' && ch <= 'z') {
      ch = ((ch - 'a') + shift) % 26 + 'a';
    }

    message[i] = ch;
    i++;
  }
}

int main() {
  char message[MAX_LEN];
  int shift;

  // get message to be encrypted from user
  printf("Enter message to encrypt (max length 50 characters): ");
  fgets(message, MAX_LEN, stdin);

  // get shift value from user
  printf("Enter shift value: ");
  scanf("%d", &shift);

  // remove newline character from message
  message[strcspn(message, "\n")] = '\0';

  // call encrypt function to encrypt the message
  encrypt(message, shift);

  // print the encrypted message
  printf("\nEncrypted message: %s\n", message);

  return 0;
}