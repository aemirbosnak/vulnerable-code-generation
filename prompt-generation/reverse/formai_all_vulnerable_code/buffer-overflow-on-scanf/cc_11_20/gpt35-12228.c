//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
// C Password Strength Checker Program in Alan Turing Style

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  // Initializing variables
  char password[100];
  int i, len, digits, upper_case, lower_case, special_chars, strength;

  // User input for password
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password length
  len = strlen(password);

  if (len < 8) {
    printf("The password is weak. It must be at least 8 characters long!\n");
    return 0;
  }

  // Count the number of digits in the password
  digits = 0;
  for (i = 0; i < len; i++) {
    if (isdigit(password[i])) {
      digits++;
    }
  }

  if (digits < 2) {
    printf("The password is weak. It must contain at least 2 digits!\n");
    return 0;
  }

  // Count the number of upper case letters
  upper_case = 0;
  for (i = 0; i < len; i++) {
    if (isupper(password[i])) {
      upper_case++;
    }
  }

  if (upper_case < 1) {
    printf("The password is weak. It must contain at least 1 upper case letter!\n");
    return 0;
  }

  // Count the number of lower case letters
  lower_case = 0;
  for (i = 0; i < len; i++) {
    if (islower(password[i])) {
      lower_case++;
    }
  }

  if (lower_case < 1) {
    printf("The password is weak. It must contain at least 1 lower case letter!\n");
    return 0;
  }

  // Count the number of special characters
  special_chars = 0;
  for (i = 0; i < len; i++) {
    if (!isalnum(password[i])) {
      special_chars++;
    }
  }

  if (special_chars < 1) {
    printf("The password is weak. It must contain at least 1 special character!\n");
    return 0;
  }

  // If it contains all the above, it is considered strong
  strength = (len * digits * upper_case * lower_case * special_chars);

  printf("The password is strong. Its strength is %d.\n", strength);

  return 0;
}