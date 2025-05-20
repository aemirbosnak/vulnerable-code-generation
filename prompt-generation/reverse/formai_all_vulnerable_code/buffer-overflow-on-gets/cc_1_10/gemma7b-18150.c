//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

char **words_list = NULL;
char **sentences_list = NULL;

int main() {
  char sentence[MAX_SENTENCE_LENGTH];
  char word[MAX_WORDS];
  int i, j, k, count = 0, spam_score = 0;

  // Allocate memory for the lists
  words_list = (char**)malloc(MAX_WORDS * sizeof(char*));
  sentences_list = (char**)malloc(MAX_SENTENCE_LENGTH * sizeof(char*));

  // Get the sentence from the user
  printf("Enter a sentence: ");
  gets(sentence);

  // Split the sentence into words
  i = 0;
  words_list[i] = strtok(sentence, " ");
  while (words_list[i] != NULL) {
    i++;
    words_list[i] = strtok(NULL, " ");
  }

  // Calculate the spam score
  for (j = 0; words_list[j] != NULL; j++) {
    for (k = 0; k < MAX_WORDS; k++) {
      if (strcmp(words_list[j], words_list[k]) == 0) {
        count++;
      }
    }

    if (count > 3) {
      spam_score++;
    }
    count = 0;
  }

  // Print the spam score
  printf("Your spam score is: %d", spam_score);

  // Free the allocated memory
  free(words_list);
  free(sentences_list);

  return 0;
}