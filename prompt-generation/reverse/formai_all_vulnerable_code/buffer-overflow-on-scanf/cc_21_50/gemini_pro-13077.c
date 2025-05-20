//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
  char password[101];
  int strength = 0;
  int hasUpper = 0, hasLower = 0, hasNumber = 0, hasSymbol = 0;
  int length = 0;

  printf("Enter thy password, weary traveler:\n");
  scanf("%s", password);

  // Calculate the length of the password
  length = strlen(password);

  // Check if the password contains at least one uppercase letter
  for (int i = 0; i < length; i++) {
    if (isupper(password[i])) {
      hasUpper = 1;
    }
  }

  // Check if the password contains at least one lowercase letter
  for (int i = 0; i < length; i++) {
    if (islower(password[i])) {
      hasLower = 1;
    }
  }

  // Check if the password contains at least one number
  for (int i = 0; i < length; i++) {
    if (isdigit(password[i])) {
      hasNumber = 1;
    }
  }

  // Check if the password contains at least one symbol
  for (int i = 0; i < length; i++) {
    if (ispunct(password[i])) {
      hasSymbol = 1;
    }
  }

  // Calculate the password strength
  if (hasUpper && hasLower && hasNumber && hasSymbol && length >= 8) {
    strength = 5;
  } else if (hasUpper && hasLower && hasNumber && length >= 6) {
    strength = 4;
  } else if (hasUpper && hasLower && length >= 6) {
    strength = 3;
  } else if (hasUpper || hasLower && length >= 6) {
    strength = 2;
  } else {
    strength = 1;
  }

  // Print the password strength
  switch (strength) {
    case 1:
      printf("Thy password is as weak as a twig in the wind.\n");
      break;
    case 2:
      printf("Thy password is as strong as a wooden shield.\n");
      break;
    case 3:
      printf("Thy password is as strong as a chainmail shirt.\n");
      break;
    case 4:
      printf("Thy password is as strong as a plate armor.\n");
      break;
    case 5:
      printf("Thy password is as strong as the walls of a castle.\n");
      break;
  }

  return 0;
}