//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main(void) {
  char password[50];
  int length, score = 0;
  int lowercase = 0, uppercase = 0, digit = 0, special = 0;

  printf("Enter your password: ");
  scanf("%s", password);

  length = strlen(password);

  // Password length check
  if (length < 8) {
    printf("Password is too short. It must be at least 8 characters long.\n");
    return 0;
  }
  else if(length > 20){
    printf("Password is too long. It must not be more than 20 characters long.\n");
    return 0;
  }

  // Check for strength of password
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      lowercase++;
    }
    else if (password[i] >= 'A' && password[i] <= 'Z') {
      uppercase++;
    }
    else if (password[i] >= '0' && password[i] <= '9') {
      digit++;
    }
    else if ((password[i] >= '!' && password[i] <= '/') || 
            (password[i] >= ':' && password[i] <= '@') || 
            (password[i] >= '[' && password[i] <= '`') || 
            (password[i] >= '{' && password[i] <= '~')) {
      special++;
    }
  }

  if (lowercase > 0) {
    score++;
  }
  if (uppercase > 0) {
    score++;
  }
  if (digit > 0) {
    score++;
  }
  if (special > 0) {
    score++;
  }

  // Password strength check
  switch(score) {
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderately strong.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
    default:
      printf("Invalid password.\n");
      break;
  }

  return 0;
}