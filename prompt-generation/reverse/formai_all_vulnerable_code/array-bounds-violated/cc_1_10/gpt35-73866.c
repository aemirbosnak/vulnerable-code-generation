//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <string.h>
#define MAXCHAR 1000

int main() {
   char str[MAXCHAR];
   char word[MAXCHAR];
   int freq[MAXCHAR];
   int i, j, k, count, len, flag;

   printf("Enter a string: ");
   fgets(str, MAXCHAR, stdin);

   len = strlen(str);
   if (str[len-1] == '\n') {
      str[len-1] = '\0';
   }

   count = 0;
   for (i = 0; str[i] != '\0'; i++) {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
         word[count] = '\0';
         flag = 0;

         for (j = 0; j < i; j++) {
            if (strcmp(word, &str[j]) == 0) {
               flag = 1;
               freq[j]++;
               break;
            }
         }

         if (flag == 0) {
            freq[count] = 1;
            strcpy(&str[count], word);
            count++;
         }
         
         count = 0;
      } else {
         word[count++] = str[i];
      }
   }

   printf("\nWord count:\n\n");
   for (i = 0; i < count; i++) {
      printf("%s: %d\n", &str[i], freq[i]);
   }

   return 0;
}