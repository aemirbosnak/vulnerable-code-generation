//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
// Password Strength Checker Program
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check the password strength
int check_password_strength(char *password) {
  int length = strlen(password);
  int uppercase = 0, lowercase = 0, number = 0, special = 0;
  int score = 0;

  for (int i = 0; i < length; i++) {
    if (isupper(password[i])) {
      uppercase++;
    } else if (islower(password[i])) {
      lowercase++;
    } else if (isdigit(password[i])) {
      number++;
    } else if (!isalnum(password[i])) {
      special++;
    }
  }

  // Assign a score to each category
  if (length >= 8) {
    score += 2;
  }
  if (uppercase >= 1) {
    score += 2;
  }
  if (lowercase >= 1) {
    score += 2;
  }
  if (number >= 1) {
    score += 2;
  }
  if (special >= 1) {
    score += 2;
  }

  // Return the score
  return score;
}

// Main function
int main() {
  char password[100];
  int score;

  printf("Enter your password: ");
  scanf("%s", password);
  score = check_password_strength(password);

  if (score >= 8) {
    printf("Your password is strong!\n");
  } else {
    printf("Your password is weak!\n");
  }

  return 0;
}