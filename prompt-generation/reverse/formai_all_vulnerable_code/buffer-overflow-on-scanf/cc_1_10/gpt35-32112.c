//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8  //Minimum Length Password Requirement
#define MAX_TRIES 3   //Maximum Password Tries

//Function Prototypes
int isUpperCase(char ch);
int isLowerCase(char ch);
int isDigit(char ch);
int isSpecialCharacter(char ch);
int isPasswordValid(char *password);
int getPasswordStrength(char *password);

int main()
{
   char password[50];
   int strength;
   int tries = 0;

   printf("******************************************************\n");
   printf("* Welcome to the Password Strength Checker Program!  *\n");
   printf("******************************************************\n\n");

   //Prompt user for password
   printf("Please enter your password: ");
   scanf("%s", password);

   //Check if the password is valid
   if (!isPasswordValid(password))
   {
      printf("\nSorry, your password does not meet the minimum requirements.\n");
      printf("Your password must be at least %d characters long and contain at least:\n", MIN_LENGTH);
      printf("1 uppercase letter, 1 lowercase letter, 1 digit, and 1 special character.\n");
      return 0;
   }

   //Get the password strength
   strength = getPasswordStrength(password);

   printf("\nCongratulations! Your password is strong enough!\n");
   printf("The strength of your password is %d out of 4.\n", strength);

   return 0;
}

/**
 * Checks if a given character is an uppercase letter.
 * Returns 1 if true, 0 otherwise.
 */
int isUpperCase(char ch)
{
   return ch >= 'A' && ch <= 'Z';
}

/**
 * Checks if a given character is a lowercase letter.
 * Returns 1 if true, 0 otherwise.
 */
int isLowerCase(char ch)
{
   return ch >= 'a' && ch <= 'z';
}

/**
 * Checks if a given character is a digit.
 * Returns 1 if true, 0 otherwise.
 */
int isDigit(char ch)
{
   return ch >= '0' && ch <= '9';
}

/**
 * Checks if a given character is a special character.
 * Returns 1 if true, 0 otherwise.
 */
int isSpecialCharacter(char ch)
{
   return !isalnum(ch);  //Returns true if the character is not alphanumeric
}

/**
 * Checks if a given password is valid.
 * To be valid, the password must be at least MIN_LENGTH characters long,
 * and contain at least 1 uppercase letter, 1 lowercase letter, 1 digit,
 * and 1 special character.
 * Returns 1 if true, 0 otherwise.
 */
int isPasswordValid(char *password)
{
   int i;
   int hasUpperCase = 0;
   int hasLowerCase = 0;
   int hasDigit = 0;
   int hasSpecialCharacter = 0;

   //Check if the length of the password is valid
   if (strlen(password) < MIN_LENGTH)
   {
      return 0;
   }

   //Check if the password contains at least one of each requirement
   for (i = 0; i < strlen(password); i++)
   {
      if (isUpperCase(password[i]))
      {
         hasUpperCase = 1;
      }
      else if (isLowerCase(password[i]))
      {
         hasLowerCase = 1;
      }
      else if (isDigit(password[i]))
      {
         hasDigit = 1;
      }
      else if (isSpecialCharacter(password[i]))
      {
         hasSpecialCharacter = 1;
      }

      //If all of the requirements are met, return true
      if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialCharacter)
      {
         return 1;
      }
   }

   //If any of the requirements are missing, return false
   return 0;

}

/**
 * Gets the strength of a given password.
 * The strength of the password is determined by the number of requirements met.
 * Returns a value between 1 and 4.
 */
int getPasswordStrength(char *password)
{
   int strength = 0;

   if (strlen(password) >= MIN_LENGTH)
   {
      strength++;
   }

   if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") && strpbrk(password, "abcdefghijklmnopqrstuvwxyz"))
   {
      strength++;
   }

   if (strpbrk(password, "0123456789"))
   {
      strength++;
   }

   if (strpbrk(password, "!@#$%^&*()_+-=[]\\{}|;':\",./<>?"))
   {
      strength++;
   }

   return strength;
}