//FormAI DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
   char str[100], search[20], replace[20], newstr[100];
   int i, j, k, found;

   printf("Enter the string: ");
   gets(str);

   printf("\nEnter the search string: ");
   gets(search);

   printf("\nEnter the replace string: ");
   gets(replace);

   i = j = found = 0;

   while(str[i] != '\0') {
      if (str[i] == search[j]) {
         found = 1;
         k = i;
         while(search[j] != '\0') {
            if (str[k] == search[j]) {
               k++;
               j++;
            } else {
               found = 0;
               break;
            }
         }
         if (found) {
            for (k = 0; replace[k] != '\0'; k++, j++)
               newstr[j] = replace[k];
            i = k - 1;
            j = 0;
         }
      } else {
         newstr[j] = str[i];
      }
      i++;
      j++;
   }

   newstr[j] = '\0';

   printf("\nThe original string is: %s", str);
   printf("\nThe new string is: %s", newstr);

   return 0;
}