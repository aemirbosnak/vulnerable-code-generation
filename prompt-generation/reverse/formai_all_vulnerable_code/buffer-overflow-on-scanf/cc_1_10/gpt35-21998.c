//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char str1[100], str2[100], temp[100];
   int choice, len1, len2;
   printf("Enter the first string: ");
   scanf("%s",str1);
   printf("Enter the second string: ");
   scanf("%s",str2);

   while(1) {
      printf("\n\n********** STRING MANIPULATION MENU **********\n");
      printf(" 1. Compare two strings\n");
      printf(" 2. Concatenate two strings\n");
      printf(" 3. Reverse a string\n");
      printf(" 4. Exit\n");
      printf(" Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1: 
            if (strcmp(str1, str2) == 0) {
               printf("Both strings are equal!");
            }
            else {
               printf("The strings are not equal!");
            }
            break;
         case 2: 
            strcat(str1, str2);
            printf("Concatenated string: %s", str1);
            break;
         case 3: 
            len1 = strlen(str1);
            len2 = strlen(str2);
            strcpy(temp, str1);
            for (int i = 0; i < len1; i++) {
               str1[i] = temp[len1 - 1 - i];
            }
            strcpy(temp, str2);
            for (int i = 0; i < len2; i++) {
               str2[i] = temp[len2 - 1 - i];
            }
            printf("Reversed strings:\n");
            printf(" %s\n %s", str1, str2);
            break;
         case 4: 
            printf("Exiting program...");
            exit(0);
         default: 
            printf("Invalid choice! Please enter a valid option.");
            break;
      }
   }
   return 0;
}