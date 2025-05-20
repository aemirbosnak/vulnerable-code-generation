#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char msg[100];
  int choice;

  printf("Enter your message: ");
  gets(msg);

  printf("Choose an encryption option:\n");
  printf("1. Caesar\n");
  printf("2. Multiplicative\n");
  printf("3. Affine\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      encryptCaesar(msg);
      break;
    case 2:
      encryptMultiplicative(msg);
      break;
    case 3:
      encryptAffine(msg);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}

void encryptCaesar(char *msg) {
  int i;
  for (i = 0; msg[i] != '\0'; i++) {
    msg[i] += 3;
  }
}

void encryptMultiplicative(char *msg) {
  int i;
  for (i = 0; msg[i] != '\0'; i++) {
    msg[i] *= 2;
  }
}

void encryptAffine(char *msg) {
  int i;
  for (i = 0; msg[i] != '\0'; i++) {
    msg[i] = (msg[i] - 9) * 5 + 13;
  }
}
