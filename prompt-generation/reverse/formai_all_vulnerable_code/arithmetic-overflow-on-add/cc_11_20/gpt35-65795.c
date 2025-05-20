//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <string.h>

typedef struct {
   char word[20];
   int count;
} WordCount;

int main() {

   char text[500], word[20];
   int wordCount = 0, i=0, j=0, k=0, n=0;

   printf("Enter some text (not more than 500 characters)\n");
   fgets(text, 500, stdin);

   // replace newline with null character
   if (text[strlen(text)-1] == '\n') {
      text[strlen(text)-1] = '\0';
   }

   // split the text into words
   n = strlen(text);
   WordCount words[n];
   for (i=0; i<n; i++) {

      if (text[i] == ' ') {

         word[j] = '\0';
         j = 0;
         wordCount++;

         // add word to array of word counts
         for (k=0; k<wordCount; k++) {
            if (strcmp(words[k].word, word) == 0) {
               words[k].count++;
               break;
            }
         }

         if (k == wordCount) {
            strcpy(words[k].word, word);
            words[k].count = 1;
         }

      } else {
         word[j++] = text[i];
      }
   }

   // add last word to array of word counts
   word[j] = '\0';
   wordCount++;
   for (k=0; k<wordCount; k++) {
      if (strcmp(words[k].word, word) == 0) {
         words[k].count++;
         break;
      }
   }

   if (k == wordCount) {
      strcpy(words[k].word, word);
      words[k].count = 1;
   }

   // print word counts
   printf("\n");
   printf("Word Count Statistics\n");
   printf("=====================\n");
   printf("Word\t\tCount\n");

   for (i=0; i<wordCount; i++) {
      printf("%s\t\t%d\n", words[i].word, words[i].count);
   }

   return 0;
}