//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 255
#define NUM_REQUIRED_TYPES 3

// Function to check if a password is strong
int is_strong_password(char *password) {
  int length = strlen(password);

  if (length < MIN_LENGTH || length > MAX_LENGTH) {
    return 0;
  }

  int num_types = 0;
  int has_upper = 0;
  int has_lower = 0;
  int has_digit = 0;
  int has_special = 0;

  for (int i = 0; i < length; i++) {
    char c = password[i];

    if (isupper(c)) {
      has_upper = 1;
    } else if (islower(c)) {
      has_lower = 1;
    } else if (isdigit(c)) {
      has_digit = 1;
    } else {
      has_special = 1;
    }
  }

  num_types = has_upper + has_lower + has_digit + has_special;

  return num_types >= NUM_REQUIRED_TYPES;
}

// Main function
int main() {
  char password[MAX_LENGTH + 1];

  printf("Enter a password: ");
  scanf("%s", password);

  int strength = is_strong_password(password);

  if (strength) {
    printf("Strong password!\n");
  } else {
    printf("Weak password!\n");
  }

  return 0;
}