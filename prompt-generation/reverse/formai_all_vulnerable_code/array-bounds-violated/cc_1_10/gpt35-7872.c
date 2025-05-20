//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define PASS_LEN 12       // Define password length here

int main(void)
{
   // Define string arrays for each character set
   const char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
   const char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   const char special_chars[] = "!@#$%^&*()_+-=[]{}|;:<>,.?/~`";
   const char digits[] = "0123456789";
  
   char password[PASS_LEN];
   int i, j, char_type;
  
   // Generate a seed for the random number generator based on the system time
   srand(time(NULL));
   
   // Loop through each character in the password
   for (i = 0; i < PASS_LEN; i++) 
   {
      // Randomly choose which character set to use for this character
      char_type = rand() % 4;
      
      // Select a random character from the chosen set and add it to the password
      switch(char_type) 
      {
         case 0:
            password[i] = lower_case[rand() % 26];
            break;
         case 1:
            password[i] = upper_case[rand() % 26];
            break;
         case 2:
            password[i] = special_chars[rand() % 29];
            break;
         case 3:
            password[i] = digits[rand() % 10];
            break;
      }
   }
   password[i] = '\0';  // Add null character at the end of the string
   
   // Randomly shuffle the characters in the password for added security
   for (i = 0; i < PASS_LEN; i++) 
   {
      j = rand() % PASS_LEN;
      char temp = password[i];
      password[i] = password[j];
      password[j] = temp;
   }
   
   // Print the final generated password
   printf("Your new password is: %s\n", password);
  
   return 0;
}