//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50], temp[50];
   int i, j;

   // Get the 1st string from user
   printf("Enter the first string: ");
   scanf("%s", str1);

   // Get the 2nd string from user
   printf("Enter the second string: ");
   scanf("%s", str2);

   // Print the original strings
   printf("Original Strings:\n");
   printf("String 1: %s\nString 2: %s\n", str1, str2);
   
   // Concatenate the 2nd string to the 1st string
   strcat(str1, str2);
   printf("Concatenated String: %s\n", str1);

   // Reverse the concatenated string
   for (i = 0; i < strlen(str1) / 2; i++) {
      temp[i] = str1[i];
      str1[i] = str1[strlen(str1) - i - 1];
      str1[strlen(str1) - i - 1] = temp[i];
   }
   printf("Reversed Concatenated String: %s\n", str1);

   // Remove all vowels from the reversed concatenated string
   for (i = 0; str1[i] != '\0'; i++) {
      while (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' || str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U') {
         for (j = i; str1[j] != '\0'; j++) {
            str1[j] = str1[j + 1];
         }
         str1[j] = '\0';
      }
   }
   printf("Reversed Concatenated String without vowels: %s\n", str1);

   // Find all occurrences of the 2nd string in the reversed concatenated string
   int count = 0;
   char *p = str1;
   while ((p = strstr(p, str2)) != NULL) {
      count++;
      printf("Occurrence %d starts at position %ld\n", count, p - str1 + 1);
      p++;
   }
   printf("Total Occurrences found: %d\n", count);

   return 0;
}