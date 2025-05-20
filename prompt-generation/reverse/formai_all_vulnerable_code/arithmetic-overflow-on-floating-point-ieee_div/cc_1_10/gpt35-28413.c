//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char text[10000];
   char summary[2000];

   printf("Enter text to summarize: ");
   fgets(text, sizeof(text), stdin);

   // Remove new line character
   text[strcspn(text, "\n")] = 0;

   // Split text into sentences
   char* sentence = strtok(text, ".");
   int sentenceCount = 0;
   while (sentence != NULL) {
      sentenceCount++;
      sentence = strtok(NULL, ".");
   }

   // Calculate compression ratio
   float compressionRatio = 0.5;
   int targetSentenceCount = (int)(sentenceCount * compressionRatio);

   // Split text into words
   char* word = strtok(text, " ");
   int wordCount = 0;
   while (word != NULL) {
      wordCount++;
      word = strtok(NULL, " ");
   }

   // Calculate average sentence length
   float sentenceLength = (float) wordCount / sentenceCount;

   // Select sentences for summary
   sentence = strtok(text, ".");
   int selectedSentenceCount = 0;
   while (sentence != NULL && selectedSentenceCount < targetSentenceCount) {
      // Check if sentence length is above average
      char* word = strtok(sentence, " ");
      int sentenceWordCount = 0;
      while (word != NULL) {
         sentenceWordCount++;
         word = strtok(NULL, " ");
      }
      if (sentenceWordCount > sentenceLength) {
         strcat(summary, sentence);
         strcat(summary, ".");
         selectedSentenceCount++;
      }
      sentence = strtok(NULL, ".");
   }

   printf("Summary: ");
   puts(summary);

   return 0;
}