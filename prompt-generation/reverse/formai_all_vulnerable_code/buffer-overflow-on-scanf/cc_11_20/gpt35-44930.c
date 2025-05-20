//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//function to check password strength
int check_password_strength(char password[]) {
  int len = strlen(password);
  int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

  for(int i = 0; i < len; i++) {
    if(isupper(password[i])) has_upper = 1;
    if(islower(password[i])) has_lower = 1;
    if(isdigit(password[i])) has_digit = 1;
    if(!isalnum(password[i])) has_special = 1;
  }

  if(len >= 8 && has_upper && has_lower && has_digit && has_special) return 4;
  else if(len >= 8 && has_upper && has_lower && has_digit) return 3;
  else if(len >= 8 && (has_upper || has_lower) && has_digit) return 2;
  else if(len >= 8 && (has_upper || has_lower)) return 1;
  else return 0;
}

int main() {
  char password[50];

  printf("Enter your password: ");
  scanf("%s", password);

  int strength = check_password_strength(password);

  switch(strength) {
    case 0:
      printf("Weak Password\n");
      break;
    case 1:
      printf("Moderately Strong Password\n");
      break;
    case 2:
      printf("Strong Password\n");
      break;
    case 3:
      printf("Very Strong Password\n");
      break;
    case 4:
      printf("Extremely Strong Password\n");
      break;
    default:
      printf("Invalid Input\n");
      break;
  }

  return 0;
}