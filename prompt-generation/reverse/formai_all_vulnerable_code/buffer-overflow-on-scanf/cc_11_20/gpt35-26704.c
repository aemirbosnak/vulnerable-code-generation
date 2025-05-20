//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
  char password[30];
  int length, i;
  int letters = 0, digits = 0, symbols = 0;
  int score = 0;

  printf("Enter password: ");
  scanf("%s", password);
  
  length = strlen(password);
  
  if (length < 8) {
    printf("Password is too short.\n");
    return 0;
  }
  
  for (i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      letters++; // counting uppercase letters
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      letters++; // counting lowercase letters
    } else if (password[i] >= '0' && password[i] <= '9') {
      digits++; // counting digits
    } else {
      symbols++; // counting symbols
    }
  }
  
  if (letters >= 1 && digits >= 1 && symbols >= 1) {
    score += 5; // adding 5 points for each category
  }
  
  if (letters >= 10) {
    score += 10; // adding 10 points for long passwords with many letters
  } else if (letters >= 5) {
    score += 5; // adding 5 points for medium-length passwords with some letters
  }
  
  if (digits >= 5) {
    score += 5; // adding 5 points for passwords with many digits
  }
  
  if (symbols >= 2) {
    score += 5; // adding 5 points for passwords with many symbols
  }
  
  printf("Password score: %d\n", score);

  if (score < 10) {
    printf("Weak password.\n");
  } else if (score < 15) {
    printf("Moderate password.\n");
  } else {
    printf("Strong password.\n");
  }

  return 0;
}