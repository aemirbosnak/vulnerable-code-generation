//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
// Just wanna say how grateful I am to be writing code today!
// Here's a unique C Encryption program for y'all to enjoy. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128

void encryptedMsg(char *msg, int key);

int main() {
  char message[MAX_LEN];
  int key;

  printf("Hello there! Let's encrypt some messages today.\n");
  printf("Please enter your message to encrypt (up to 128 characters): ");
  fgets(message, MAX_LEN, stdin);
  printf("Please enter the key: ");
  scanf("%d", &key);

  // remove newline character from fgets
  message[strcspn(message, "\n")] = 0;

  // print original message
  printf("Original message: %s\n", message);
  
  // encrypt message using key
  encryptedMsg(message, key);

  // print encrypted message
  printf("Encrypted message: %s\n", message);

  return 0;
}

// function to encrypt message
void encryptedMsg(char *msg, int key) {
  int i;
  char c;

  for (i = 0; msg[i] != '\0'; ++i) {
    c = msg[i];

    if (c >= 'a' && c <= 'z') {
      c = c + key;

      if (c > 'z') {
        c = c - 'z' + 'a' - 1;
      }

      msg[i] = c;
    }
    else if (c >= 'A' && c <= 'Z') {
      c = c + key;

      if (c > 'Z') {
        c = c - 'Z' + 'A' - 1;
      }

      msg[i] = c;
    }
  }
}