//FormAI DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {

   char str1[50], str2[50];
   int i, j, length;

   printf("Enter the first string: ");
   scanf("%s",str1);

   printf("Enter the second string: ");
   scanf("%s",str2);

   length = strlen(str1);

   printf("\nOriginal String: %s\n", str1);

   for(i = 0, j = length -1; i < length/2; i++, j--) {

      char temp = str1[i];
      str1[i] = str1[j];
      str1[j] = temp;

   }

   printf("Reversed String: %s\n", str1);

   length = strlen(str2);

   printf("\nOriginal String: %s\n", str2);

   for(i = 0, j = length -1; i < length/2; i++, j--) {

      char temp = str2[i];
      str2[i] = str2[j];
      str2[j] = temp;

   }

   printf("Reversed String: %s\n", str2);

   // Concatenate two strings
   strcat(str1, str2);

   printf("\nConcatenated String: %s\n", str1);

   // Convert all characters to uppercase
   length = strlen(str1);

   for(i = 0; i < length; i++) {
      str1[i] = toupper(str1[i]);
   }

   printf("\nUppercase String: %s", str1);

   return 0;
}