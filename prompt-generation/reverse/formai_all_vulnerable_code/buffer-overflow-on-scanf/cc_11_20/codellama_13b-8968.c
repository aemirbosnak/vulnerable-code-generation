//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: funny
// A funny password strength checker program in C
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[20];
  int length, uppercase, lowercase, number, special;
  int pass_strength = 0;

  printf("Enter your password: ");
  scanf("%s", password);

  length = strlen(password);
  uppercase = 0;
  lowercase = 0;
  number = 0;
  special = 0;

  for (int i = 0; i < length; i++) {
    if (isupper(password[i])) {
      uppercase++;
    } else if (islower(password[i])) {
      lowercase++;
    } else if (isdigit(password[i])) {
      number++;
    } else {
      special++;
    }
  }

  if (length >= 8) {
    pass_strength++;
  }
  if (uppercase >= 1) {
    pass_strength++;
  }
  if (lowercase >= 1) {
    pass_strength++;
  }
  if (number >= 1) {
    pass_strength++;
  }
  if (special >= 1) {
    pass_strength++;
  }

  if (pass_strength >= 5) {
    printf("Your password is very strong!\n");
  } else if (pass_strength == 4) {
    printf("Your password is strong!\n");
  } else if (pass_strength == 3) {
    printf("Your password is good!\n");
  } else if (pass_strength == 2) {
    printf("Your password is weak!\n");
  } else {
    printf("Your password is very weak!\n");
  }

  return 0;
}