#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char msg[1024];
  int key, choice;

  printf("Enter your message: ");
  gets(msg);

  printf("Choose an encryption method:\n");
  printf("1. Caesar Cipher\n");
  printf("2. Multiplicative Cipher\n");
  printf("3. Affine Cipher\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      key = 3;
      break;
    case 2:
      key = 5;
      break;
    case 3:
      key = 7;
      break;
    default:
      printf("Invalid choice.\n");
      return 1;
  }

  // Implement the chosen cipher here
  // ...

  printf("Your encrypted message is: %s", msg);

  return 0;
}
