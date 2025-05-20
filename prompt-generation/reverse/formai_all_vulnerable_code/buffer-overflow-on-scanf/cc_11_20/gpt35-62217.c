//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char password[100];
  int length, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0, strength = 0, i;

  printf("Enter your password: ");
  scanf("%s", password);
  length = strlen(password);

  for(i = 0; i < length; i++){
    if(password[i] >= 'A' && password[i] <= 'Z')
      hasUpper = 1;
    if(password[i] >= 'a' && password[i] <= 'z')
      hasLower = 1;
    if(password[i] >= '0' && password[i] <= '9')
      hasDigit = 1;
    if(password[i] >= 33 && password[i] <= 46)
      hasSpecial = 1;
  }

  if(length >= 8)
    strength++;
  if(hasUpper && hasLower)
    strength++;
  if(hasDigit)
    strength++;
  if(hasSpecial)
    strength++;

  switch(strength){
    case 4:
        printf("Your password is extremely strong!\n");
        break;
    case 3:
        printf("Your password is very strong!\n");
        break;
    case 2:
        printf("Your password is strong!\n");
        break;
    case 1:
        printf("Your password is weak!\n");
        break;
    default:
      printf("Invalid password!\n");
  }

  return 0;
}