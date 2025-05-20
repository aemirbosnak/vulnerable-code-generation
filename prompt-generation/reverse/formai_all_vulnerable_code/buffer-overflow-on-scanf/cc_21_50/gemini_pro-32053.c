//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Too weak! Try harder!
// Not strong enough! Keep trying!
// Still weak! You can do better!
// Getting there! Almost strong!
// Strong enough! You did it!
// Super strong! Unbreakable!

int main() {
  char password[101];
  int strength, i;

  printf("Enter your password (max 100 characters): ");
  scanf("%s", password);

  strength = 0;

  // Check for length
  if (strlen(password) >= 8) strength += 1;

  // Check for uppercase letters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') strength += 1;
  }

  // Check for lowercase letters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') strength += 1;
  }

  // Check for digits
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') strength += 1;
  }

  // Check for special characters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' ||
        password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') strength += 1;
  }

  // Print the password strength
  switch (strength) {
    case 0: printf("Your password is too weak!"); break;
    case 1: printf("Your password is not strong enough!"); break;
    case 2: printf("Your password is still weak!"); break;
    case 3: printf("Your password is getting there!"); break;
    case 4: printf("Your password is strong enough!"); break;
    case 5: printf("Your password is super strong!"); break;
  }

  return 0;
}