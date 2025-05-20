//FormAI DATASET v1.0 Category: Data validation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char username[20];
  char password[20];
  int valid = 1;

  printf("Please enter your desired username (must contain only alphabetical characters and be between 6 and 12 characters long):\n");
  scanf("%s", username);

  // check if username length is between 6 and 12 characters
  if (strlen(username) < 6 || strlen(username) > 12) {
    printf("Username must be between 6 and 12 characters long.\n");
    valid = 0;
  }

  // check if username contains only alphabetical characters
  for (int i = 0; i < strlen(username); i++) {
    if (!isalpha(username[i])) {
      printf("Username must contain only alphabetical characters.\n");
      valid = 0;
      break;
    }
  }

  printf("Please enter your desired password (must contain at least one uppercase letter, one lowercase letter, and one number):\n");
  scanf("%s", password);

  // check if password contains at least one uppercase letter, one lowercase letter, and one number
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_number = 0;

  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    }
    if (islower(password[i])) {
      has_lowercase = 1;
    }
    if (isdigit(password[i])) {
      has_number = 1;
    }
  }

  if (!has_uppercase || !has_lowercase || !has_number) {
    printf("Password must contain at least one uppercase letter, one lowercase letter, and one number.\n");
    valid = 0;
  }

  if (valid) {
    printf("Username and password are valid.\n");
  }

  return 0;
}