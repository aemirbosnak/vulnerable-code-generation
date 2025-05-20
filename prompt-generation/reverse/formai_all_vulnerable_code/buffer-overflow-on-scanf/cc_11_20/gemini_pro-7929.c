//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Password Strength Checker
//
// This program checks the strength of a password by analyzing its length, character
// composition, and diversity. The program assigns a score to the password based on
// these factors and provides feedback on the password's strength.
//
// The program uses the following criteria to evaluate password strength:
//
// - Length: The password must be at least 8 characters long.
// - Character Composition: The password must contain a mix of uppercase and lowercase
//   characters, numbers, and symbols.
// - Diversity: The password must not contain any repeated characters.

int main() {
  // Get the password from the user.
  char password[100];
  printf("Enter a password: ");
  scanf("%s", password);

  // Check the password's length.
  int length = strlen(password);
  if (length < 8) {
    printf("The password must be at least 8 characters long.\n");
    return 1;
  }

  // Check the password's character composition.
  int hasUppercase = 0;
  int hasLowercase = 0;
  int hasNumber = 0;
  int hasSymbol = 0;
  for (int i = 0; i < length; i++) {
    char c = password[i];
    if (isupper(c)) {
      hasUppercase = 1;
    } else if (islower(c)) {
      hasLowercase = 1;
    } else if (isdigit(c)) {
      hasNumber = 1;
    } else {
      hasSymbol = 1;
    }
  }

  if (!hasUppercase || !hasLowercase || !hasNumber || !hasSymbol) {
    printf(
        "The password must contain a mix of uppercase and lowercase characters, "
        "numbers, and symbols.\n");
    return 1;
  }

  // Check the password's diversity.
  for (int i = 0; i < length; i++) {
    char c = password[i];
    for (int j = i + 1; j < length; j++) {
      char d = password[j];
      if (c == d) {
        printf("The password must not contain any repeated characters.\n");
        return 1;
      }
    }
  }

  // Calculate the password's strength score.
  int score = 0;
  score += length;
  score += hasUppercase ? 1 : 0;
  score += hasLowercase ? 1 : 0;
  score += hasNumber ? 1 : 0;
  score += hasSymbol ? 1 : 0;
  score -= (length - strlen(password));  // Penalize for spaces

  // Provide feedback on the password's strength.
  if (score < 5) {
    printf("The password is weak.\n");
  } else if (score < 7) {
    printf("The password is moderate.\n");
  } else if (score < 9) {
    printf("The password is strong.\n");
  } else {
    printf("The password is very strong.\n");
  }

  return 0;
}