//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000   // Maximum length of input string

int main()
{
   char inputString[MAX_LENGTH];
   int positiveWords = 0, negativeWords = 0, neutralWords = 0;

   // Open files with pre-defined positive and negative words
   FILE* fpPositiveWords = fopen("positive_words.txt", "r");
   FILE* fpNegativeWords = fopen("negative_words.txt", "r");

   // Check if files are opened successfully
   if (fpPositiveWords == NULL || fpNegativeWords == NULL)
   {
      printf("Error opening files!\n");
      exit(1);
   }

   // Read input string from user
   printf("Enter a sentence or phrase to analyze sentiment:\n");
   fgets(inputString, MAX_LENGTH, stdin);

   // Tokenize the input string into words
   char* word = strtok(inputString, " ");
   while (word != NULL)
   {
      // Remove trailing newline character
      if (word[strlen(word) - 1] == '\n')
      {
         word[strlen(word) - 1] = '\0';
      }

      // Search for positive word in the file
      char positiveWord[MAX_LENGTH];
      while (fgets(positiveWord, MAX_LENGTH, fpPositiveWords) != NULL)
      {
         if (strcmp(word, positiveWord) == 0)
         {
            positiveWords++;
         }
      }

      // Search for negative word in the file
      char negativeWord[MAX_LENGTH];
      while (fgets(negativeWord, MAX_LENGTH, fpNegativeWords) != NULL)
      {
         if (strcmp(word, negativeWord) == 0)
         {
            negativeWords++;
         }
      }

      // Reset file cursor to beginning of file to search for next word
      rewind(fpPositiveWords);
      rewind(fpNegativeWords);

      // Move to next word in input string
      word = strtok(NULL, " ");
   }

   // Close files
   fclose(fpPositiveWords);
   fclose(fpNegativeWords);

   // Determine sentiment based on positive and negative words counts
   if (positiveWords > negativeWords)
   {
      printf("Sentiment: positive\n");
   }
   else if (negativeWords > positiveWords)
   {
      printf("Sentiment: negative\n");
   }
   else
   {
      printf("Sentiment: neutral\n");
   }
   
   return 0;
}