//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

/* A struct to store words and their count */
struct word_count {
   char word[MAX_WORD_LENGTH];
   int count;
};

/* Function to get input and split into words */
void get_input(char* input, struct word_count words[]) {
   char* word;
   int i = 0;
   word = strtok(input, " ");
   while (word != NULL && i < MAX_WORDS) {
      strcpy(words[i].word, word);
      words[i].count = 1;
      word = strtok(NULL, " ");
      i++;
   }
}

/* Function to count the frequency of each word */
void count_words(int num_words, struct word_count words[]) {
   int i, j;
   for (i = 0; i < num_words; i++) {
      for (j = i + 1; j < num_words; j++) {
         if (strcasecmp(words[i].word, words[j].word) == 0) {
            words[i].count++;
            words[j].count = 0;
         }
      }
   }
}

/* Function to sort words by count and output to console */
void output_results(int num_words, struct word_count words[]) {
   int i, j;
   struct word_count temp;
   for (i = 0; i < num_words-1; i++) {
      for (j = i + 1; j < num_words; j++) {
         if (words[i].count < words[j].count) {
            temp = words[i];
            words[i] = words[j];
            words[j] = temp;
         }
      }
   }
   printf("| %15s | %5s |\n", "Word", "Count");
   printf("+----------------+-------+\n");
   for (i = 0; i < num_words; i++) {
      if (words[i].count != 0) {
         printf("| %15s | %5d |\n", words[i].word, words[i].count);
      }
   }
}

int main() {
   char input[500];
   struct word_count words[MAX_WORDS];
   printf("Enter text to analyze: ");
   fgets(input, sizeof(input), stdin);
   get_input(input, words);
   count_words(MAX_WORDS, words);
   output_results(MAX_WORDS, words);

   return 0;
}