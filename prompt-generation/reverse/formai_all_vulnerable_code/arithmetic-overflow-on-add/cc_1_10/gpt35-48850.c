//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 10000

// Declare function for adding a word to the frequency counter
int add_word(char *word, int count, char word_list[MAX_WORDS][MAX_WORD_LEN], int freq[MAX_WORDS]);

// Declare function for comparing words
int compare_words(const void *a, const void *b);

int main()
{
   char input[1000];
   char current_word[MAX_WORD_LEN];
   int word_count = 0;
   char word_list[MAX_WORDS][MAX_WORD_LEN];
   int freq[MAX_WORDS];
   int i;

   printf("Enter a sentence or paragraph (max 1000 characters):\n");
   fgets(input, 1000, stdin);

   // Loop through the input character by character
   for (i = 0; input[i] != '\0'; i++)
   {
      // If the character is a letter or a digit, add it to the current word
      if (isalnum(input[i]))
      {
         strncat(current_word, &input[i], 1);
      }
      // If the character is not a letter or a digit and the current word is not empty, add it to the frequency counter
      else if (strlen(current_word) > 0)
      {
         word_count = add_word(current_word, word_count, word_list, freq);
         memset(current_word, 0, MAX_WORD_LEN); // Reset current_word
      }
   }
   // If the last character in the input was a letter or a digit, add the last word to the frequency counter
   if (strlen(current_word) > 0)
   {
      word_count = add_word(current_word, word_count, word_list, freq);
   }

   // Sort the word list by frequency
   qsort(word_list, word_count, MAX_WORD_LEN * sizeof(char), compare_words);

   // Print out the word frequency results
   printf("Word Frequency\n");
   printf("----------------\n");
   for (i = 0; i < word_count; i++)
   {
      printf("%-15s %d\n", word_list[i], freq[i]);
   }

   return 0;
}

// Function for adding a word to the frequency counter
int add_word(char *word, int count, char word_list[MAX_WORDS][MAX_WORD_LEN], int freq[MAX_WORDS])
{
   int i;

   // Convert the word to lowercase
   for (i = 0; word[i] != '\0'; i++)
   {
      word[i] = tolower(word[i]);
   }

   // Check if the word is already in the word list
   for (i = 0; i < count; i++)
   {
      if (strcmp(word_list[i], word) == 0)
      {
         freq[i]++;
         return count;
      }
   }

   // If the word is not in the word list, add it
   if (count < MAX_WORDS)
   {
      strcpy(word_list[count], word);
      freq[count]++;
      return count + 1;
   }
   else
   {
      printf("Error: Exceeded maximum number of words\n");
      exit(EXIT_FAILURE);
   }
}

// Function for comparing words by frequency for use in qsort
int compare_words(const void *a, const void *b)
{
   const char *word1 = (const char *)a;
   const char *word2 = (const char *)b;
   int freq1 = 0, freq2 = 0, i;

   // Get the frequency of word1
   for (i = 0; word1[i] != '\0'; i++)
   {
      freq1 += (int)word1[i];
   }

   // Get the frequency of word2
   for (i = 0; word2[i] != '\0'; i++)
   {
      freq2 += (int)word2[i];
   }

   // Compare the frequencies
   return (freq2 - freq1);
}