//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Romeo and Juliet
// Romeo and Juliet: A Password Strength Checker
// By: A Chatbot

#include<stdio.h>
#include<string.h>

int main() {
  char password[100];
  int length, i, digit, lower_alpha, upper_alpha, special_char;
  
  // Romeo: My love, what shall we name this program?
  // Juliet: How about "The Password Strength Checker"?
  // Romeo: Ah, how fitting. Let's begin coding!

  // Asking for input
  printf("Enter a password: ");
  scanf("%s", password);
  length = strlen(password);

  // Initializing variables
  digit = 0;
  lower_alpha = 0;
  upper_alpha = 0;
  special_char = 0;

  // Checking each character in password
  for(i = 0; i < length; i++) {
    if(password[i] >= '0' && password[i] <= '9') {
      digit = 1;
    } else if(password[i] >= 'a' && password[i] <= 'z') {
      lower_alpha = 1;
    } else if(password[i] >= 'A' && password[i] <= 'Z') {
      upper_alpha = 1;
    } else {
      special_char = 1;
    }
  }

  // Romeo: Let us now give the password its strength score
  // Juliet: Indeed, my love. It should be out of 10, shouldn't it?
  int score = (digit + lower_alpha + upper_alpha + special_char) * 2;

  // Displaying strength score and possible improvements
  printf("\nPassword Strength Score: %d/10\n", score);
  if(score < 5) {
    printf("Strength: Weak\n");
    printf("Possible Improvements: \n");
    if(!digit) {
      printf("- Add a number (0-9)\n");
    }
    if(!lower_alpha) {
      printf("- Add a lowercase letter (a-z)\n");
    }
    if(!upper_alpha) {
      printf("- Add an uppercase letter (A-Z)\n");
    }
    if(!special_char) {
      printf("- Add a special character (!@#$&*)\n");
    }
  } else if(score < 8) {
    printf("Strength: Good\n");
    printf("Possible Improvements: \n");
    if(digit && lower_alpha && upper_alpha && !special_char) {
      printf("- Add a special character (!@#$&*)\n");
    }
    if(digit && !lower_alpha && upper_alpha && special_char) {
      printf("- Add a lowercase letter (a-z)\n");
    }
    if(!digit && lower_alpha && upper_alpha && special_char) {
      printf("- Add a number (0-9)\n");
    }
    if(digit && lower_alpha && !upper_alpha && special_char) {
      printf("- Add an uppercase letter (A-Z)\n");
    }
  } else {
    printf("Strength: Strong\n");
    printf("No possible improvements needed. Your password is secure!\n");
  }

  return 0;
}