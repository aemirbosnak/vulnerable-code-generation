//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50];
   char str2[50];
   int len;
   int i;
   int j;

   printf("Enter the first string: ");
   scanf("%s", str1); // Read input string 1

   printf("Enter the second string: ");
   scanf("%s", str2); // Read input string 2

   printf("The first string is: %s\n", str1);
   printf("The second string is: %s\n", str2);

   len = strlen(str1); // Calculate length of string 1
   printf("The length of the first string is: %d\n", len);

   printf("The first string in uppercase: ");
   for(i=0; i<len; i++) {
      printf("%c", toupper(str1[i])); // Convert individual characters to uppercase of string 1
   }
   printf("\n");

   printf("The second string in lowercase: ");
   len = strlen(str2); // Calculate length of string 2
   for(i=0; i<len; i++) {
      printf("%c", tolower(str2[i])); // Convert individual characters to lowercase of string 2
   }
   printf("\n");

   printf("The concatenated string: ");
   strcat(str1,str2); // Concatenate two strings
   printf("%s\n", str1);

   printf("The reversed string: ");
   len = strlen(str1); // Calculate length of concatenated string
   for(i=len-1; i>=0; i--) {
      printf("%c", str1[i]); // Print the concatenated string in reverse
   }
   printf("\n");

   printf("The string without vowels: ");
   for(i=0; i<len; i++) {
      if(tolower(str1[i]) != 'a' && tolower(str1[i]) != 'e' && tolower(str1[i]) != 'i' && tolower(str1[i]) != 'o' && tolower(str1[i]) != 'u')  {
         printf("%c", str1[i]); // Print concatenated string without vowels
      }
   }
   printf("\n");

   printf("The string with every other character capitalized: ");
   for(i=0; i<len; i++) {
      if(i%2==0) {
         printf("%c", toupper(str1[i])); // Capitalize every other character of concatenated string
      } else {
         printf("%c", str1[i]); // Otherwise, print the character as is
      }
   }
   printf("\n");

   printf("The string with each character repeated twice: ");
   for(i=0; i<len; i++) {
      printf("%c%c", str1[i], str1[i]); // Repeat each character of concatenated string twice
   }
   printf("\n");

   return 0;
}