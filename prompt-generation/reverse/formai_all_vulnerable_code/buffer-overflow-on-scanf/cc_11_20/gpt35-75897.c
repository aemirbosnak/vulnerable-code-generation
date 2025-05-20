//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
   char password[20];
   int length, i, upper=0, lower=0, digit=0, specialch=0;

   printf("Enter password: ");
   scanf("%s", password);

   length = strlen(password);

   if(length < 8 || length > 20)
   {
       printf("\nWeak Password!\n");
       printf("Password length must be between 8 and 20 characters.\n");
       exit(0);
   }

   for(i=0; i<length; i++)
   {
      if(isupper(password[i]))
      {
          upper++;
      }

      if(islower(password[i]))
      {
          lower++;
      }

      if(isdigit(password[i]))
      {
          digit++;
      }

      if(password[i]>=33 && password[i]<=46 || password[i]==64)
      {
          specialch++;
      } 
   }

   if(upper>=1 && lower>=1 && digit>=1 && specialch>=1)
   {
      printf("\nStrong Password!\n");
   }
   else
   {
      printf("\nWeak Password!\n");
      if(upper<1)
      {
         printf("- Password must contain at least one uppercase letter.\n");
      }
      if(lower<1)
      {
         printf("- Password must contain at least one lowercase letter.\n");
      }
      if(digit<1)
      {
         printf("- Password must contain at least one digit.\n");
      }
      if(specialch<1)
      {
         printf("- Password must contain at least one special character.\n");
      }
   }

   return 0;
}