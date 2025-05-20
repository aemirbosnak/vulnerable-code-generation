//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
  char password[256];
  int strength;

  printf("My dearest, enter your password: ");
  scanf("%s", password);

  int length = strlen(password);
  if (length < 8) {
    strength = 1;
  } else if (length < 16) {
    strength = 2;
  } else {
    strength = 3;
  }

  int uppercase = 0;
  int lowercase = 0;
  int numbers = 0;
  int symbols = 0;

  for (int i = 0; i < length; i++) {
    char c = password[i];
    if (c >= 'A' && c <= 'Z') {
      uppercase++;
    } else if (c >= 'a' && c <= 'z') {
      lowercase++;
    } else if (c >= '0' && c <= '9') {
      numbers++;
    } else {
      symbols++;
    }
  }

  if (uppercase > 0 && lowercase > 0 && numbers > 0 && symbols > 0) {
    strength++;
  }

  printf("My love, your password strength is %d.\n", strength);

  if (strength == 1) {
    printf("A password as delicate as a rose, it needs more thorns to protect it.");
  } else if (strength == 2) {
    printf("A password as strong as our bond, yet it could withstand a stronger gale.");
  } else if (strength == 3) {
    printf("A password as unyielding as my love, it will forever keep our hearts entwined.");
  }

  return 0;
}