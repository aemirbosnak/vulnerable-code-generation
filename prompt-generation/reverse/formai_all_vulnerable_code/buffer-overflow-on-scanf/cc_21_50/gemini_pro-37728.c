//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

int main() {
  char password[100];
  int strength = 0;

  printf("Enter your password: ");
  scanf("%s", password);

  // Check the length of the password
  if (strlen(password) < MIN_LENGTH) {
    printf("Password is too short! Must be at least %d characters long.\n", MIN_LENGTH);
    return 1;
  }

  // Check for uppercase characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength++;
      break;
    }
  }

  // Check for lowercase characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength++;
      break;
    }
  }

  // Check for digits
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength++;
      break;
    }
  }

  // Check for special characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength++;
      break;
    }
  }

  // Check for repeated characters
  for (int i = 0; i < strlen(password); i++) {
    for (int j = i + 1; j < strlen(password); j++) {
      if (password[i] == password[j]) {
        strength--;
        break;
      }
    }
  }

  // Check for common passwords
  FILE *file = fopen("common-passwords.txt", "r");
  if (file == NULL) {
    printf("Error opening common passwords file!\n");
    return 1;
  }

  char line[100];
  while (fgets(line, sizeof(line), file) != NULL) {
    if (strcmp(password, line) == 0) {
      strength--;
      break;
    }
  }

  fclose(file);

  // Print the password strength
  printf("Password strength: %d\n", strength);

  // Check the password strength
  if (strength < 3) {
    printf("Password is weak!\n");
  } else if (strength < 6) {
    printf("Password is moderate!\n");
  } else {
    printf("Password is strong!\n");
  }

  return 0;
}