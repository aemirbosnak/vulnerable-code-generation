//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
// Ada Lovelace inspired Password Strength Checker program in C

#include <stdio.h>
#include <string.h>

int main() {
  
  char password[20];
  int score = 0;
  int length = 0;
  
  printf("Enter a password: ");
  scanf("%s", password);
  
  length = strlen(password);
  
  if (length < 8) {
    score -= 5;
  } else {
    score += 5;
  }
  
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      score += 2;
    } else if (password[i] >= 'A' && password[i] <= 'Z') {
      score += 3;
    } else if (password[i] >= '0' && password[i] <= '9') {
      score += 4;
    } else {
      score += 5;
    }
  }
  
  if (length >= 10) {
    score += 10;
  } else if (length >= 8) {
    score += 5;
  } else {
    score -= 5;
  }
  
  if (score >= 20) {
    printf("Your password is extremely strong!\n");
  } else if (score >= 15) {
    printf("Your password is very strong!\n");
  } else if (score >= 10) {
    printf("Your password is strong.\n");
  } else if (score >= 5) {
    printf("Your password is medium strength.\n");
  } else {
    printf("Your password is weak. Please try again.\n");
  }
  
  return 0;
}