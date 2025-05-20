//FormAI DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>

int main()
{
   char str1[30], str2[30];

   // Prompt user to enter two strings
   printf("Enter the first string: ");
   scanf("%s",str1);

   printf("Enter the second string: ");
   scanf("%s",str2);

   int option;

   // Prompts user to select an option
   printf("Choose an option: \n");
   printf("1. Concatenate two strings\n");
   printf("2. Copy second string to the first string\n");
   printf("3. Compare two strings\n");
   scanf("%d",&option);

   switch(option) {
      case 1 :
         // Concatenates the two strings
         strcat(str1,str2);
         printf("Concatenated string: %s\n", str1);
         break;

      case 2 :
         // Copy's the second string to the first string
         strcpy(str1,str2);
         printf("First string after copy: %s\n", str1);
         break;

      case 3 :
         // Compares two strings
         if(strcmp(str1,str2) == 0)
            printf("The strings are equal.\n");
         else
            printf("The strings are not equal.\n");
         break;

      default :
         printf("Invalid option, please try again.\n");
   }

   return 0;
}