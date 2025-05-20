//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <ctype.h>

int main() {

   char password[40];
   int upper = 0, lower = 0, digit = 0, special = 0, i, score = 0;

   printf("Enter Password : ");
   scanf("%s", password);

   for(i = 0; password[i] != '\0'; i++) {
      if(isupper(password[i])) {
         upper++;
      } else if(islower(password[i])) {
         lower++;
      } else if(isdigit(password[i])) {
         digit++;
      } else {
         special++;
      }
   }

   if(upper > 0 && lower > 0) {
      score += 10;
   }

   if(digit > 0) {
      score += 10;
   }

   if(special > 0) {
      score += 10;
   }

   if(i >= 8 && i < 12) {
      score += 10;
   } else if(i >= 12 && i < 16) {
      score += 20;
   } else if(i >= 16) {
      score += 30;
   }

   if(score >= 30 && score < 40) {
      printf("Password Strength: Weak\n");
   } else if(score >= 40 && score < 60) {
      printf("Password Strength: Moderate\n");
   } else if(score >= 60 && score < 80) {
      printf("Password Strength: Strong\n");
   } else if(score >= 80) {
      printf("Password Strength: Very Strong\n");
   }

   return 0;
}