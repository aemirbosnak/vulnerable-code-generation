//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char password[50];
   int valid = 0;
   int length = 0, upper = 0, lower = 0, digit = 0, special = 0;
   printf("Enter your password:");
   scanf("%s", password);

   length = strlen(password);

   for (int i = 0; i < length; i++) {

      if (isupper(password[i]))
         upper++;

      if (islower(password[i]))
         lower++;

      if (isdigit(password[i]))
         digit++;

      if (password[i] >= 33 && password[i] <= 46 || password[i] == 64) // ASCII code for special characters
         special++;
   }

   if (length >= 8 && upper > 0 && lower > 0 && digit > 0 && special > 0) {
      printf("Password strength: Strong");
      valid = 1;
   }

   else if (length >= 8 && upper > 0 && lower > 0 && digit > 0) {
      printf("Password strength: Medium");
      valid = 1;
   }

   else if (length >= 8 && upper > 0 && lower > 0) {
      printf("Password strength: Weak");
      valid = 1;
   }

   else {
      printf("Password must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, one digit and one special character.");
   }

   // Code for giving hints to a weak password
   if (valid == 0) {

      printf("\nSome Password Hints:\n");

      if (length < 8) {
         printf("- Password should be at least 8 characters.\n");
      }

      if (upper == 0) {
         printf("- Password should contain at least one uppercase letter.\n");
      }

      if (lower == 0) {
         printf("- Password should contain at least one lowercase letter.\n");
      }

      if (digit == 0) {
         printf("- Password should contain at least one digit.\n");
      }

      if (special == 0) {
         printf("- Password should contain at least one special character.\n");
      }
   }

   return 0;
}