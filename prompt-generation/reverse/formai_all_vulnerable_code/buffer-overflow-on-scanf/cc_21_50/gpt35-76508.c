//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50];
   int i, j;

   printf("Enter a string: ");
   scanf("%s",str1);

   printf("Enter another string: ");
   scanf("%s",str2);

   // Concatenate the two strings
   i = strlen(str1);
   for (j = 0; str2[j] != '\0'; i++, j++) {
      str1[i] = str2[j];
   }

   str1[i] = '\0'; // Add null character at the end of concatenated string

   printf("Concatenated string: %s\n", str1);

   // Reverse the string
   printf("Original string: %s\n", str1);
   for(i=0, j=strlen(str1)-1; i<j; i++, j--) {
      char temp = str1[i];
      str1[i] = str1[j];
      str1[j] = temp;
   }

   printf("Reversed string: %s\n", str1);

   // Check if string is palindrome
   int isPalindrome = 1;
   for (i = 0, j = strlen(str1)-1; i < j; i++, j--) {
      if (str1[i] != str1[j]) {
         isPalindrome = 0;
         break;
      }
   }

   if (isPalindrome) {
      printf("The reversed string is a palindrome\n");
   } else {
      printf("The reversed string is not a palindrome\n");
   }

   // Count the number of vowels and consonants in the string
   int vowels = 0, consonants = 0;
   for (i = 0; str1[i] != '\0'; i++) {
      if (str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U'
         || str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u') {
         vowels++;
      } else if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z')) {
         consonants++;
      }
   }

   printf("Number of vowels: %d\n", vowels);
   printf("Number of consonants: %d\n", consonants);

   return 0;
}