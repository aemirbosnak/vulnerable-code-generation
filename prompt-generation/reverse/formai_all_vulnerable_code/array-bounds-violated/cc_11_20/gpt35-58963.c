//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
   char sentence[1000], word[100], new_word[100], ch;
   int i, j, k, len, word_len, match, count;

   // Get the sentence to be processed
   printf("Enter a sentence: ");
   fgets(sentence, sizeof(sentence), stdin);
   
   // Remove the newline character from fgets
   len = strlen(sentence);
   if (sentence[len - 1] == '\n') 
      sentence[len - 1] = '\0';

   // Get the word to be replaced
   printf("\nEnter the word to be replaced: ");
   scanf("%s", word);
   word_len = strlen(word);
   
   // Get the new word to replace the old one
   printf("\nEnter the new word: ");
   scanf("%s", new_word);

   count = 0;
   for (i = 0; sentence[i] != '\0'; i++) {
      // Check for word starting position
      if (sentence[i] == word[0]) {
         match = 1;
         for (j = 1, k = i+1; word[j]!='\0' && sentence[k]!='\0'; j++, k++) {
            if (word[j]!=sentence[k]) {
               match = 0;
               break;
            }
         }
         if (match == 1 && (sentence[k]==' ' || sentence[k]=='\0') && (i==0 || sentence[i-1]==' ')) {
            // Replace the word with the new word
            for (j = 0; new_word[j] != '\0'; j++, i++) {
               sentence[i] = new_word[j];
            }
            count++;
         }
      }
   }

   // Print the processed sentence
   printf("\nProcessed sentence: %s\n", sentence);
   
   // Print the count of words replaced
   printf("\n%d occurrences replaced.\n", count);
   
   return 0;
}