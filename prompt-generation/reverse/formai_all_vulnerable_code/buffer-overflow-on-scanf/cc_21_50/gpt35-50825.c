//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
   char str[1000];
   char temp;
   int i, j = 0;
   printf("Enter a string: ");
   scanf("%s", str);
   printf("\nOriginal String: %s\n", str);
   
   // To reverse the string
   for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
   }
   printf("Reversed String: %s\n", str);

   // To remove all vowels from the string
   int len = strlen(str);
   for (i = 0; i < len; i++) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
         for (j = i; j < len; j++) {
            str[j] = str[j+1];
         }
         len--;
         i--;
      }
   }
   printf("String without vowels: %s\n", str);

   // To print each character of the string in a new line
   for (i = 0; i < strlen(str); i++) {
      printf("%c\n", str[i]);
   }

   // To count the number of words in the string
   int wordCount = 1;
   for (i = 0; i < strlen(str); i++) {
      if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v') {
         wordCount++;
      }
   }
   printf("Number of words in the string: %d\n", wordCount);

   // To convert the first character of each word to uppercase
   for (i = 0; i < strlen(str); i++) {
      if (i == 0 || str[i-1] == ' ' || str[i-1] == '\n' || str[i-1] == '\t' || str[i-1] == '\r' || str[i-1] == '\f' || str[i-1] == '\v') {
         if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
         }
      }
   }
   printf("String with first character of each word in uppercase: %s\n", str);
   
   return 0;
}