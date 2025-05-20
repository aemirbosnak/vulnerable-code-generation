//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("\n\tWelcome to the Password Strength Checker!\n");

  //initialize variables
  char password[50];
  int length, count_uppercase, count_lowercase, count_symbols, count_numbers, score=0;
  length = count_uppercase = count_lowercase = count_symbols = count_numbers = 0;

  //get password from user
  printf("\n\tPlease enter your password: ");
  scanf("%s", password);
  length = strlen(password);

  //check password length
  if (length < 8) {
    printf("\n\tYour password is too short!\n");
    exit(0);
  }

  //check for uppercase letters
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      count_uppercase++;
    }
  }

  //check for lowercase letters
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      count_lowercase++;
    }
  }

  //check for symbols
  for (int i = 0; i < length; i++) {
    if (!(password[i] >= 'A' && password[i] <= 'Z') 
        && !(password[i] >= 'a' && password[i] <= 'z') 
        && !(password[i] >= '0' && password[i] <= '9')) {
      count_symbols++;
    }
  }

  //check for numbers
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      count_numbers++;
    }
  }

  //calculate password strength score
  if (length >= 8 && length <= 10) {
    score += 5;
  } else if (length > 10) {
    score += 10;
  }
  score += count_uppercase * 2;
  score += count_lowercase * 2;
  score += count_symbols * 3;
  score += count_numbers * 2;

  //print password strength score
  printf("\n\tYour password strength score is: %d\n\n", score);

  return 0;
}