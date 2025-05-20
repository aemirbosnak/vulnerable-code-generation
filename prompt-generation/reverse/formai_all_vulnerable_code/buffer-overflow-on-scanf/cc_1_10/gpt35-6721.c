//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if a password is strong
int check_password_strength(char password[]) {
  int len = strlen(password);
  int upper = 0, lower = 0, digit = 0, special_char = 0;

  // iterate over all characters in the password
  for (int i = 0; i < len; i++) {
    char c = password[i];
    if (isupper(c)) {    // check if the character is uppercase
      upper = 1;
    } else if (islower(c)) {    // check if the character is lowercase
      lower = 1;
    } else if (isdigit(c)) {    // check if the character is a digit
      digit = 1;
    } else {    // check if the character is a special character
      special_char = 1;
    }
  }

  // calculate the password strength score
  int score = upper + lower + digit + special_char;
  if (len < 8 && score < 3) {
    return 0;    // password is weak
  } else if (len >= 8 && score < 3) {
    return 1;    // password is moderate
  } else if (len < 8 && score >= 3) {
    return 1;    // password is moderate
  } else {
    return 2;    // password is strong
  }
}

int main() {
  printf("Enter a password: ");
  char password[50];
  scanf("%s", password);

  int strength = check_password_strength(password);
  switch(strength) {
    case 0:
      printf("Password is weak. Try again!\n");
      break;
    case 1:
      printf("Password is moderate. Good, but can be better!\n");
      break;
    case 2:
      printf("Password is strong. Well done!\n");
      break;
    default:
      printf("Invalid password.\n");
  }

  return 0;
}