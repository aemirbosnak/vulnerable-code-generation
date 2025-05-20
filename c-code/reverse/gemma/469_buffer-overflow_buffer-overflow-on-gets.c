#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice, key, message_length, i;
  char message[100];

  printf("Select an option:\n");
  printf("1. Caesar Cipher\n");
  printf("2. Multiplicative Cipher\n");
  printf("3. Affine Cipher\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the key: ");
      scanf("%d", &key);
      printf("Enter the message: ");
      scanf("%s", message);
      message_length = strlen(message);
      for (i = 0; i < message_length; i++) {
        message[i] = (message[i] - 96 + key) % 26 + 96;
      }
      printf("The encrypted message is: %s\n", message);
      break;
    case 2:
      printf("Enter the key: ");
      scanf("%d", &key);
      printf("Enter the message: ");
      scanf("%s", message);
      message_length = strlen(message);
      for (i = 0; i < message_length; i++) {
        message[i] = (message[i] - 96) * key + 96;
      }
      printf("The encrypted message is: %s\n", message);
      break;
    case 3:
      printf("Enter the key: ");
      scanf("%d", &key);
      printf("Enter the message: ");
      scanf("%s", message);
      message_length = strlen(message);
      for (i = 0; i < message_length; i++) {
        message[i] = (message[i] - 96) * key + key + 96;
      }
      printf("The encrypted message is: %s\n", message);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
