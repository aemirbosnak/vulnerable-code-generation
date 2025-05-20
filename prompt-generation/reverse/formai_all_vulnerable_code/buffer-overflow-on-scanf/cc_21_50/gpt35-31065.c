//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
  char password[50];
  int score = 0;
  
  printf("Enter your password: ");
  scanf("%s", password);
  
  int length = strlen(password);
  
  // Password length check
  if (length >= 8 && length <= 16) {
    score += 10;
  }
  
  // Uppercase and lowercase check
  int uppercase = 0, lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      uppercase = 1;
    }
    if (password[i] >= 'a' && password[i] <= 'z') {
      lowercase = 1;
    }
  }
  if (uppercase && lowercase) {
    score += 10;
  }
  
  // Digit check
  int digit = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      digit = 1;
    }
  }
  if (digit) {
    score += 10;
  }
  
  // Symbol check
  int symbol = 0;
  for (int i = 0; i < length; i++) {
    if (!(password[i] >= '0' && password[i] <= '9') && !(password[i] >= 'A' && password[i] <= 'Z') && !(password[i] >= 'a' && password[i] <= 'z')) {
      symbol = 1;
    }
  }
  if (symbol) {
    score += 10;
  }
  
  // Password strength check
  printf("\nPassword Strength: ");
  if (score == 10) {
    printf("Weak");
  }
  else if (score == 20) {
    printf("Moderate");
  }
  else if (score == 30) {
    printf("Strong");
  }
  else if (score == 40) {
    printf("Very Strong");
  }
  else {
    printf("Very Weak");
  }
  
  return 0;
}