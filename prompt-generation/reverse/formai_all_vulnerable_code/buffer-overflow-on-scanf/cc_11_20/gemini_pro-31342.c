//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_password_strength(char *password) {
  int score = 0;
  int length = strlen(password);

  // Check for length
  if (length < 8) {
    score += 1;
  } else if (length < 12) {
    score += 2;
  } else if (length < 16) {
    score += 3;
  } else {
    score += 4;
  }

  // Check for uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
    }
  }
  if (has_uppercase) {
    score += 1;
  }

  // Check for lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
    }
  }
  if (has_lowercase) {
    score += 1;
  }

  // Check for numbers
  int has_number = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_number = 1;
    }
  }
  if (has_number) {
    score += 1;
  }

  // Check for special characters
  int has_special_character = 0;
  for (int i = 0; i < length; i++) {
    if (!(password[i] >= 'A' && password[i] <= 'Z') &&
        !(password[i] >= 'a' && password[i] <= 'z') &&
        !(password[i] >= '0' && password[i] <= '9')) {
      has_special_character = 1;
    }
  }
  if (has_special_character) {
    score += 1;
  }

  // Check for dictionary words
  FILE *fp;
  char word[256];
  fp = fopen("dictionary.txt", "r");
  if (fp != NULL) {
    while (fgets(word, sizeof(word), fp) != NULL) {
      if (strcmp(password, word) == 0) {
        score -= 1;
      }
    }
    fclose(fp);
  }

  return score;
}

int main() {
  char password[256];
  printf("Enter a password: ");
  scanf("%s", password);

  int score = check_password_strength(password);

  printf("Password strength: %d\n", score);

  if (score < 4) {
    printf("Your password is weak.\n");
  } else if (score < 6) {
    printf("Your password is medium.\n");
  } else {
    printf("Your password is strong.\n");
  }

  return 0;
}