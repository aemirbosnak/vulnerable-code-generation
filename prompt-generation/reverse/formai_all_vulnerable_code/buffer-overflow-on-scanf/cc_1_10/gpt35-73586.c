//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if the password meets the minimum length requirement
int check_length(char *password) {
   int length = strlen(password);
   if (length >= 8) {
      return 1;
   } else {
      return 0;
   }
}

// function to check if the password contains at least one lowercase character
int check_lowercase(char *password) {
   int i, length = strlen(password);
   for (i = 0; i < length; i++) {
      if (islower(password[i])) {
         return 1;
      }
   }
   return 0;
}

// function to check if the password contains at least one uppercase character
int check_uppercase(char *password) {
   int i, length = strlen(password);
   for (i = 0; i < length; i++) {
      if (isupper(password[i])) {
         return 1;
      }
   }
   return 0;
}

// function to check if the password contains at least one digit
int check_digit(char *password) {
   int i, length = strlen(password);
   for (i = 0; i < length; i++) {
      if (isdigit(password[i])) {
         return 1;
      }
   }
   return 0;
}

// function to check if the password contains at least one special character
int check_special(char *password) {
   int i, length = strlen(password);
   for (i = 0; i < length; i++) {
      if (!isalnum(password[i])) {
         return 1;
      }
   }
   return 0;
}

int main() {
   char password[50];
   int length, lowercase, uppercase, digit, special;

   printf("Enter your password: ");
   scanf("%s", password);

   // check for each of the password requirements and set appropriate flags
   length = check_length(password);
   lowercase = check_lowercase(password);
   uppercase = check_uppercase(password);
   digit = check_digit(password);
   special = check_special(password);

   // print out the result based on the flags set
   if (length && lowercase && uppercase && digit && special) {
      printf("Your password is strong!\n");
   } else {
      printf("Your password is weak. Please make sure it meets the following requirements:\n");
      if (!length) {
         printf("- Minimum length of 8 characters\n");
      }
      if (!lowercase) {
         printf("- At least one lowercase letter\n");
      }
      if (!uppercase) {
         printf("- At least one uppercase letter\n");
      }
      if (!digit) {
         printf("- At least one digit\n");
      }
      if (!special) {
         printf("- At least one special character\n");
      }
   }

   return 0;
}