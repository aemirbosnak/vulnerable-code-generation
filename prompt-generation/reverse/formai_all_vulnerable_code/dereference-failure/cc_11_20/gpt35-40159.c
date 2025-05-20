//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

int main(int argc, char *argv[]) {
   FILE *file;
   char word[MAX_WORD_LENGTH];
   char filename[MAX_WORD_LENGTH];
   int wordCount[MAX_NUM_WORDS] = {0};
   int i, j;
   int numWords = 0;
   int totalWords = 0;
   char c;

   if (argc != 2) {
      printf("Usage: %s <filename>\n", argv[0]);
      return 1;
   }

   strncpy(filename, argv[1], MAX_WORD_LENGTH);

   file = fopen(filename, "r");
   if (file == NULL) {
      printf("Cannot open file %s\n", filename);
      return 1;
   }

   while ((c = fgetc(file)) != EOF) {
      if (isalpha(c)) {
         word[numWords++] = tolower(c);
         if (numWords >= MAX_WORD_LENGTH) {
            numWords = 0;
         }
      } else if (numWords > 0) {
         word[numWords] = '\0';
         numWords = 0;
         totalWords++;

         for (i = 0; i < MAX_NUM_WORDS && wordCount[i] > 0; i++) {
            if (strcmp(word, (char *)&wordCount[i]) == 0) {
               wordCount[i]++;
               break;
            }
         }

         if (i == MAX_NUM_WORDS) {
            printf("Too many unique words in %s\n", filename);
            return 1;
         } else if (wordCount[i] == 0) {
            strncpy((char *)&wordCount[i], word, MAX_WORD_LENGTH);
            wordCount[i]++;
         }
      }
   }

   fclose(file);

   printf("Total words: %d\n", totalWords);

   for (i = 0; i < MAX_NUM_WORDS && wordCount[i] > 0; i++) {
      printf("%s: %d\n", (char *)&wordCount[i], wordCount[i]);
   }

   return 0;
}