//FormAI DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char str1[50];
   char str2[50];
   char temp[50];
   int choice, len1, len2, flag, i, j, count, pos;

   printf("Enter the string 1: ");
   fgets(str1, 50, stdin);
   len1 = strlen(str1) - 1;
   str1[len1] = '\0';

   printf("Enter the string 2: ");
   fgets(str2, 50, stdin);
   len2 = strlen(str2) - 1;
   str2[len2] = '\0';

   while (1) {
      printf("\n\nChoose the string manipulation function to perform: \n");
      printf("1. Concatenate string 1 and string 2\n");
      printf("2. Copy string 1 to string 2\n");
      printf("3. Reverse string 1\n");
      printf("4. Find substring in string 1\n");
      printf("5. Replace substring in string 1\n");
      printf("6. Exit program\n");
      printf("Enter your choice: ");
      fflush(stdout);
      scanf("%d", &choice);
      fflush(stdin);

      switch (choice) {
         case 1:
            printf("Concatenated string: %s\n", strcat(str1, str2));
            break;

         case 2:
            strcpy(str2, str1);
            printf("String 2 now contains: %s\n", str2);
            break;

         case 3:
            for (i = 0, j = len1 - 1; i < j; i++, j--) {
               temp[i] = str1[j];
               temp[j] = str1[i];
            }
            temp[len1] = '\0';
            printf("Reversed string: %s\n", temp);
            break;

         case 4:
            printf("Enter a substring to search: ");
            fflush(stdout);
            fgets(temp, 50, stdin);
            count = 0;
            for (i = 0; i < len1; i++) {
               flag = 1;
               for (j = 0; temp[j] != '\0'; j++) {
                  if (temp[j] != str1[i + j]) {
                     flag = 0;
                     break;
                  }
               }
               if (flag == 1) {
                  count++;
                  pos = i;
               }
            }
            if (count == 0) {
               printf("Not found.\n");
            } else {
               printf("Found %d times at position %d.\n", count, pos+1);
            }
            break;

         case 5:
            printf("Enter the substring to replace: ");
            fflush(stdout);
            fgets(temp, 50, stdin);
            printf("Enter the replacement string: ");
            fgets(str2, 50, stdin);
            len2 = strlen(str2) - 1;
            str2[len2] = '\0';
            for (i = 0; i < len1; i++) {
               flag = 1;
               for (j = 0; temp[j] != '\0'; j++) {
                  if (temp[j] != str1[i + j]) {
                     flag = 0;
                     break;
                  }
               }
               if (flag == 1) {
                  for (j = i; j < len1 - len2; j++) {
                     str1[j] = str1[j + len2];
                  }
                  for (j = 0; j < len2; j++) {
                     str1[i + j] = str2[j];
                  }
               }
            }
            printf("Resultant string: %s\n", str1);
            break;

         case 6:
            printf("Program exited.\n");
            exit(0);

         default:
            printf("Invalid choice. Try again.\n");
            break;
      }
   }
   return 0;
}