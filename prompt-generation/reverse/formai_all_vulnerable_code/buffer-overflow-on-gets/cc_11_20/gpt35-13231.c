//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main() {
   char str1[25], str2[25], temp[25];
   int i, j, len1 = 0, len2 = 0, choice, flag = 0;
   
   // Get the first string from the user
   printf("Enter the first string: ");
   gets(str1);
   len1 = strlen(str1);
   
   // Get the second string from the user
   printf("\nEnter the second string: ");
   gets(str2);
   len2 = strlen(str2);
   
   // Display the original strings
   printf("\nOriginal strings: \n");
   printf("String 1: %s\n",str1);
   printf("String 2: %s\n",str2);
   
   // Menu to select string manipulation operation
   printf("\nSelect string manipulation operation:\n");
   printf("1. Concatenation of two strings\n");
   printf("2. Comparison of two strings\n");
   printf("3. Reversal of two strings\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   // Perform the string manipulation operation based on user choice
   switch(choice) {
      case 1: // Concatenation of two strings
         strcat(str1,str2);
         printf("\nConcatenated string: %s",str1);
         break;
         
      case 2: // Comparison of two strings
         for(i=0; i<len1 && i<len2; i++) {
            if(str1[i]!=str2[i]) {
               flag = 1;
               break;
            }
         }
         if(flag == 0) {
            printf("\nThe strings are identical");
         }
         else {
            printf("\nThe strings are not identical");
         }
         break;
         
      case 3: // Reversal of two strings
         for(i=0; i<len1; i++) {
            temp[i] = str1[i];
         }
         for(i=0,j=len2-1; i<len2,j>=0; i++,j--) {
            str1[i] = str2[j];
         }
         for(i=len2,j=0; i<len1+len2,j<len1; i++,j++) {
            str1[i] = temp[j];
         }
         printf("\nReversed string: %s",str1);
         break;
         
      default: // Invalid choice
         printf("\nInvalid choice! Try again.");
         break;
   }
   
   return 0;
}