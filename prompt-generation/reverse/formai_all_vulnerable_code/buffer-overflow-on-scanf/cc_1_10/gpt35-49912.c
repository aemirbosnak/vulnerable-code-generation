//FormAI DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
   FILE *fp;
   char filename[100];
   char c;

   printf("Enter the name of the e-book file: ");
   scanf("%s", filename);

   fp = fopen(filename, "r");

   if (fp == NULL) {
      printf("Error: could not open file %s", filename);
      return 1;
   }

   int num_words = 0;
   int num_chars = 0;
   int num_spaces = 0;
   int num_lines = 0;

   while ((c = fgetc(fp)) != EOF) {
      if (isspace(c)) {
         num_spaces++;
      }

      if (c == '\n') {
         num_lines++;
      }

      num_chars++;

      // update word count when finding a word boundary
      if (isspace(c) || ispunct(c)) {
         num_words++;
      }
   }

   fclose(fp);

   printf("Total characters: %d\n", num_chars);
   printf("Total words: %d\n", num_words);
   printf("Total spaces: %d\n", num_spaces);
   printf("Total lines: %d\n", num_lines);

   return 0;
}