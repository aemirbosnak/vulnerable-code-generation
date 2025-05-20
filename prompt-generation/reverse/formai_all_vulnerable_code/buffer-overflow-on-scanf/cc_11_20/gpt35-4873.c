//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multivariable
#include<stdio.h>
#include<string.h>

int main() {
   char password[100];
   int i, len, isDigit, isUpper, isLower, isSpecial;
   int strength = 0;

   printf("Enter your password: ");
   scanf("%s", password);

   len = strlen(password);

   // check for digits, upper and lowercase letters, special characters
   isDigit = isUpper = isLower = isSpecial = 0;
   for(i=0; i<len; i++) {
      if(password[i] >= '0' && password[i] <= '9')
         isDigit = 1;
      else if(password[i] >= 'A' && password[i] <= 'Z')
         isUpper = 1;
      else if(password[i] >= 'a' && password[i] <= 'z')
         isLower = 1;
      else
         isSpecial = 1;
   }

   // calculate password strength based on criteria met
   if(len < 8) {
      printf("Weak password. Password length should be at least 8 characters.\n");
      return 0;
   } else if(len < 10) {
      strength += 10;
   } else {
      strength += 20;
   }

   if(isDigit)
      strength += 10;
   if(isUpper)
      strength += 10;
   if(isLower)
      strength += 10;
   if(isSpecial)
      strength += 10;

   // print password strength level
   if(strength < 30)
      printf("Weak password. Password strength level: %d/100\n", strength);
   else if(strength < 50)
      printf("Moderate password. Password strength level: %d/100\n", strength);
   else if(strength < 80)
      printf("Strong password. Password strength level: %d/100\n", strength);
   else
      printf("Very strong password. Password strength level: %d/100\n", strength);

   return 0;
}