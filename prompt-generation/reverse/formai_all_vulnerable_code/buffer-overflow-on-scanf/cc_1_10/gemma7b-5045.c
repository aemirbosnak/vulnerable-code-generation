//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASS_LEN 255

void checkPasswordStrength(char *pass) {
  int strength = 0;
  int minLen = 8;
  char *specialChars = "$#@%^&*()_+-={}[]|\\:";

  if (strlen(pass) >= minLen) {
    strength++;
  }

  for (int i = 0; i < strlen(pass); i++) {
    if (pass[i] >= 'a' && pass[i] <= 'z') {
      strength++;
    } else if (pass[i] >= 'A' && pass[i] <= 'Z') {
      strength++;
    } else if (pass[i] >= '0' && pass[i] <= '9') {
      strength++;
    } else if (strchr(specialChars, pass[i]) != NULL) {
      strength++;
    }
  }

  switch (strength) {
    case 0:
      printf("Password is too weak!\n");
      break;
    case 1:
      printf("Password is somewhat weak.\n");
      break;
    case 2:
      printf("Password is strong.\n");
      break;
    case 3:
      printf("Password is very strong.\n");
      break;
  }
}

int main() {
  char pass[MAX_PASS_LEN];

  printf("Enter your password: ");
  scanf("%s", pass);

  checkPasswordStrength(pass);

  return 0;
}