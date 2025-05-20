//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 128
#define VALID_PASSWORD_STRENGTH 100

typedef struct {
  int length;
  int uppercase_letters;
  int lowercase_letters;
  int digits;
  int special_characters;
  int strength;
} password_strength;

int main() {
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter your password: ");
  scanf("%s", password);

  // Check if the password is valid.
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    printf("Your password is too short.\n");
    return 1;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    printf("Your password is too long.\n");
    return 1;
  }

  // Calculate the strength of the password.
  int strength = 0;
  for (int i = 0; i < strlen(password); i++) {
    char character = password[i];
    if (isupper(character)) {
      strength += 1;
    } else if (islower(character)) {
      strength += 1;
    } else if (isdigit(character)) {
      strength += 1;
    } else {
      strength += 1;
    }
  }

  // Print the strength of the password.
  printf("Your password strength is %d%%.\n", strength);

  return 0;
}