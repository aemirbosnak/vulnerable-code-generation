//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
   char password[50];
   int len, i, digit=0, upper=0, lower=0, special=0;

   printf("Enter the Password: ");
   scanf("%s", password);

   len = strlen(password);

   if(len < 8){
      printf("\nPassword must have at least 8 characters.\n");
      return 0;
   }

   for(i=0; i<len; i++){
      if(isdigit(password[i]))
         digit++;
      else if(isupper(password[i]))
         upper++;
      else if(islower(password[i]))
         lower++;
      else
         special++;
   }

   // Password Score Calculation
   int score = 0; 
   if(digit >= 1) score += 15;
   if(upper >= 1) score += 20;
   if(lower >= 1) score += 20;
   if(special >= 1) score += 25;
   
   // Output the Password Strength result
   printf("============================\n");
   printf("Password Strength Checker\n");
   printf("============================\n");
   printf("Password: %s\n", password);
   printf("Password Length: %d\n", len);
   printf("------------------------------\n");
   printf("Digit count: %d\n", digit);
   printf("Uppercase count: %d\n", upper);
   printf("Lowercase count: %d\n", lower);
   printf("Special character count: %d\n", special);
   printf("------------------------------\n");
   printf("Password Score: %d\n", score);
   printf("============================\n");

   if(score < 40) printf("Weak Password!\n");
   else if(score < 60) printf("Medium Password!\n");
   else if(score < 80) printf("Strong Password!\n");
   else printf("Very Strong Password!\n");

   return 0;
}