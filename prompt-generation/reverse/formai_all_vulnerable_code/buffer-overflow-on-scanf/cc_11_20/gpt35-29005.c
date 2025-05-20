//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include<stdio.h>
#include<string.h>

int main() {

   //Variable Declarations
   char password[100];
   int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
   int length, i;

   //Greet User
   printf("Welcome to Password Strength Checker\n");
   printf("------------------------------------\n");

   //User input
   printf("Enter password: ");
   scanf("%s", password);

   //Password length check
   length = strlen(password);
   if (length < 8) {
      printf("Password is too short!\n");
      return 0;
   }

   //Character requirements
   for (i = 0; i < length; i++) {
      if (password[i] >= 'A' && password[i] <= 'Z') {
         has_upper = 1;
      }
      else if (password[i] >= 'a' && password[i] <= 'z') {
         has_lower = 1;
      }
      else if (password[i] >= '0' && password[i] <= '9') {
         has_digit = 1;
      }
      else {
         has_special = 1;
      }
   }

   //Password strength check
   if (has_upper && has_lower && has_digit && has_special) {
      printf("Password is strong!\n");
   }
   else if ((has_upper + has_lower + has_digit + has_special) == 3) {
      printf("Password is medium!\n");
   }
   else {
      printf("Password is weak!\n");
   }
   return 0;
}