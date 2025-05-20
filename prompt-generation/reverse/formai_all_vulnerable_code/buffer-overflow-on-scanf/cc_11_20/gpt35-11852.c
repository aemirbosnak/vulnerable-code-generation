//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char password[20];
  int len, has_uppercase, has_lowercase, has_digit, has_special_char, strength = 0;

  printf("Enter a password with minimum 8 characters: ");
  scanf("%s", password);

  len = strlen(password);
  has_uppercase = has_lowercase = has_digit = has_special_char = 0;

  for(int i = 0; i < len; i++) {
    if(password[i] >= 'A' && password[i] <= 'Z')
      has_uppercase = 1;
    else if(password[i] >= 'a' && password[i] <= 'z')
      has_lowercase = 1;
    else if(password[i] >= '0' && password[i] <= '9')
      has_digit = 1;
    else
      has_special_char = 1;
  }

  if (len < 8) {
    printf("Password is too short\n");
    return 0;
  }

  if (has_uppercase)
    strength++;
  if (has_lowercase)
    strength++;
  if (has_digit)
    strength++;
  if (has_special_char)
    strength++;

  if (strength == 1) {
    printf("Password is very weak!\n");
  } else if (strength == 2) {
    printf("Password is weak!\n");
  } else if (strength == 3) {
    printf("Password is strong!\n");
  } else {
    printf("Password is very strong!\n");
  }

  return 0;
}