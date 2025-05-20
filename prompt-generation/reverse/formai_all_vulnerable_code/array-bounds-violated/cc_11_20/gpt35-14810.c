//FormAI DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
// VeronaEncrypt.c - A story of forbidden love, written in C code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[1000], key[1000], encrypted_msg[1000];
  int i, j, choice, msg_len, key_len;

  // Setting the stage
  printf("In fair Verona, where we lay our scene,\n");
  printf("Two households, both alike in dignity,\n");
  printf("In fair C code, where we begin our tale,\n");
  printf("A new encryption method awaits, to prevail.\n");

  // Gathering the message and key
  printf("\nEnter your message (max 1000 characters):\n");
  fgets(message, 1001, stdin);
  printf("Enter your secret key (max 1000 characters):\n");
  fgets(key, 1001, stdin);

  // Removing newline character from message and key
  msg_len = strlen(message);
  key_len = strlen(key);
  if (message[msg_len-1] == '\n') message[msg_len-1] = '\0';
  if (key[key_len-1] == '\n') key[key_len-1] = '\0';

  // Prompting the user to choose encryption method
  printf("\nNow comes the test to choose your fate,\n");
  printf("Which encryption method shall you create?\n");
  printf("[1] Shift cipher\n");
  printf("[2] Vigenere cipher\n");
  printf("Enter your choice (1 or 2):\n");
  scanf("%d", &choice);

  // Applying shift cipher or vigenere cipher based on user's choice
  if (choice == 1) {
    printf("\nWith the shift cipher, the message shall be,\n");
    printf("Encrypted with a key to shift a certain degree.\n");
    for (i = 0; i < msg_len; i++) {
      if (message[i] >= 'A' && message[i] <= 'Z') {
        encrypted_msg[i] = (message[i] + key[i%key_len] - 2*'A') % 26 + 'A';
      } else if (message[i] >= 'a' && message[i] <= 'z') {
        encrypted_msg[i] = (message[i] + key[i%key_len] - 2*'a') % 26 + 'a';
      }
    }
  } else if (choice == 2) {
    printf("\nWith the Vigenere cipher, the message shall be,\n");
    printf("Encoded with a key of a similar degree.\n");
    for (i = 0; i < msg_len; i++) {
      j = i % key_len;
      encrypted_msg[i] = ((message[i] + key[j]) % 26) + 'A';
    }
  }

  // Displaying the encrypted message
  printf("\nAnd thus the message is now concealed,\n");
  printf("In ciphered text that must be revealed.\n");
  printf("\nThe encrypted message is:\n%s\n", encrypted_msg);

  // Cheesy ending to the program
  printf("Oh Romeo, oh Juliet, if only they knew,\n");
  printf("The message that was sent between these two.\n");
  printf("A love so pure, and yet so concealed,\n");
  printf("By encryption that must be revealed.\n");

  return 0;
}