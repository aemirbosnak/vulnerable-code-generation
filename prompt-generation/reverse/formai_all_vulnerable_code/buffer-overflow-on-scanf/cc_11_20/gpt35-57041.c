//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
  char password[30];
  int length, i;
  int uppercaseCount = 0;
  int lowercaseCount = 0;
  int digitCount = 0;
  int specialCharCount = 0;

  printf("Enter your password:\n");
  scanf("%s", password);

  length = strlen(password);

  // Check Password Length
  if (length < 8) {
    printf("Your password should be at least 8 characters long.\n");
    return 0;
  }

  // Check Characters in Password
  for (i = 0; i < length; i++) {
    char c = password[i];
    if (c >= 'A' && c <= 'Z') {
      uppercaseCount++;
    } else if (c >= 'a' && c <= 'z') {
      lowercaseCount++;
    } else if (c >= '0' && c <= '9') {
      digitCount++;
    } else {
      specialCharCount++;
    }
  }

  // Check Uppercase Letters
  if (uppercaseCount < 1) {
    printf("Your password should contain at least 1 uppercase character.\n");
    return 0;
  }

  // Check Lowercase Letters
  if (lowercaseCount < 1) {
    printf("Your password should contain at least 1 lowercase character.\n");
    return 0;
  }

  // Check Digits
  if (digitCount < 1) {
    printf("Your password should contain at least 1 digit.\n");
    return 0;
  }

  // Check Special Characters
  if (specialCharCount < 1) {
    printf("Your password should contain at least 1 special character.\n");
    return 0;
  }

  // If the password meets all criteria, display success message
  printf("Password is strong!\n");

  return 0;
}