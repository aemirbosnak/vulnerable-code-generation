//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
   int score = 0;
   char password[100];

   printf("Enter your password: ");
   scanf("%s", password);

   if (strlen(password) < 8) {
      printf("Your password is too short. You need at least 8 characters.\n");
      return 0;
   }

   if (strlen(password) > 16) {
      printf("Your password is too long. You should keep it below 16 characters.\n");
      return 0;
   }

   int upper = 0, lower = 0, digit = 0, symbol = 0;
   for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= 'A' && password[i] <= 'Z')
         upper = 1;
      else if (password[i] >= 'a' && password[i] <= 'z')
         lower = 1;
      else if (password[i] >= '0' && password[i] <= '9')
         digit = 1;
      else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%'
               || password[i] == '^' || password[i] == '&' || password[i] == '*')
         symbol = 1;
   }

   if (upper)
      score += 3;
   if (lower)
      score += 3;
   if (digit)
      score += 3;
   if (symbol)
      score += 3;

   if (strlen(password) > 12)
      score += 2;
   if (strlen(password) > 8)
      score += 1;

   if (score < 6)
      printf("Your password is weak and easily hackable!\n");
   else if (score < 9)
      printf("Your password is decent, but could use improvement.\n");
   else if (score < 12)
      printf("Your password is strong and secure!\n");
   else
      printf("Your password is extremely strong and virtually uncrackable!\n");

   return 0;
}