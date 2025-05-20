//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char str1[50], str2[50], temp[50];
   int i, j, k;

   printf("Enter the first string: ");
   scanf("%s", str1);

   printf("Enter the second string: ");
   scanf("%s", str2);

   //Concatenating two strings
   printf("\nAfter concatenation: %s\n", strcat(str1, str2));

   //Copying one string to another
   strcpy(temp, str1);
   printf("After copying the first string to a temporary string: %s\n", temp);

   //Comparing two strings
   if(strcmp(str1, str2) == 0)
        printf("The strings are equal\n");
   else if(strcmp(str1, str2) < 0)
        printf("The first string is smaller than the second string.\n");
   else
        printf("The second string is smaller than the first string.\n");

   //Finding the length of a string
   printf("The length of the first string is: %d\n", strlen(str1));
   printf("The length of the second string is: %d\n", strlen(str2));

   //Reversing a string
   printf("The first string in reverse order: ");
   for(i = strlen(str1)-1; i >= 0; i--)
        printf("%c", str1[i]);
   printf("\n");

   //Finding a substring in a string
   printf("Enter a substring to search in the first string: ");
   scanf("%s", temp);
   for(i = 0; i < strlen(str1); i++) {
        if(strncmp(&str1[i], temp, strlen(temp)) == 0) {
            printf("The substring was found in the first string starting at index: %d\n", i);
            break;
        }
   }

   //Replacing a character in a string
   printf("Enter a character to replace in the second string: ");
   char c;
   scanf(" %c", &c);

   printf("Enter the new character: ");
   char new_c;
   scanf(" %c", &new_c);

   for(i = 0; i < strlen(str2); i++) {
        if(str2[i] == c)
            str2[i] = new_c;
   }

   printf("The second string after replacing %c with %c: %s\n", c, new_c, str2);

   return 0;
}