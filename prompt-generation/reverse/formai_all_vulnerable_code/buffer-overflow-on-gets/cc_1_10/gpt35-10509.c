//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
   char str1[100], str2[100];
   printf("Enter string 1: ");
   gets(str1);
   printf("Enter string 2: ");
   gets(str2);
   
   // Find the length of each string
   int len1 = strlen(str1), len2 = strlen(str2);
   
   // Compare the two strings
   int cmp = strcmp(str1, str2);
   
   // Copy string 1 to string 2
   strcpy(str2, str1);
   
   // Concatenate string 1 and string 2
   strcat(str1, str2);
   
   // Convert the strings to uppercase
   for(int i=0; i<len1; i++) {
      str1[i] = toupper(str1[i]);
   }
   
   for(int i=0; i<len2; i++) {
      str2[i] = toupper(str2[i]);
   }
   
   // Print out the modified strings and other information
   printf("\nModified Results:\n");
   printf("String 1: %s\n", str1);
   printf("String 2: %s\n", str2);
   printf("String 1 Length: %d\n", len1);
   printf("String 2 Length: %d\n", len2);
   
   if(cmp == 0) {
      printf("String 1 and String 2 are equal.\n");
   }
   else if(cmp > 0) {
      printf("String 1 is greater than String 2.\n");
   }
   else {
      printf("String 1 is less than String 2.\n");
   }
   
   return 0;
}