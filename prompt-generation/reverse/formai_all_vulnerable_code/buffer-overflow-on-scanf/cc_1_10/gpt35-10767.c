//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main()
{
   char str1[100], str2[100];
   int i, j;
   
   printf("Enter first string: ");
   scanf("%s", str1);
   
   printf("Enter second string: ");
   scanf("%s", str2);

   // Concatenation of two strings
   strcat(str1, str2);
   
   printf("\nConcatenated string: %s\n", str1);

   // Finding the string length
   printf("\nLength of the concatenated string: %zu\n", strlen(str1));

   // Copying the string
   char str3[100];
   strcpy(str3, str1);
   printf("\nCopied string: %s\n", str3);

   // Reversing the string
   int len = strlen(str1);
   char rev[len+1];
   
   for (i = 0, j = len-1; i < len; i++, j--)
   {
      rev[i] = str1[j];
   }
   rev[len] = '\0';
   
   printf("\nReversed string: %s\n", rev);

   // Checking for palindrome
   int flag = 1;
   
   for (i = 0; i < len; i++)
   {
      if (str1[i] != rev[i])
      {
         flag = 0;
         break;
      }
   }
   if (flag)
   {
      printf("\nThe concatenated string is a palindrome.\n");
   }
   else
   {
      printf("\nThe concatenated string is not a palindrome.\n");
   }

   // Searching substrings
   char sub[20];
   printf("\nEnter substring to search: ");
   scanf("%s", sub);

   char *pos = strstr(str1, sub);
   if (pos == NULL)
   {
      printf("\nSubstring not found.\n");
   }
   else
   {
      printf("\nSubstring found at position %d.\n", pos - str1);
   }

   return 0;
}