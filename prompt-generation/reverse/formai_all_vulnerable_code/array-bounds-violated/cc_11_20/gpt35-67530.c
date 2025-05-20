//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Happy Text Summarizer!\n");

  // Get input text from user
  char input[1000];
  printf("Enter the text you want to summarize: ");
  fgets(input, 1000, stdin);

  // Calculate length of input text
  int len = strlen(input);

  // Remove new line character from input text
  if (input[len-1] == '\n') {
    input[len-1] = '\0';
  }

  // Convert input text to lowercase
  for (int i = 0; i < len; i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] += 32;
    }
  }

  // Split input text into sentences
  char* sentence;
  sentence = strtok(input, ".?!");

  printf("\nHere's the summary:\n");

  // Loop through each sentence and check for keywords
  while (sentence != NULL) {
    int happy_count = 0;
    int keyword_count = 0;
    char* word;
    word = strtok(sentence, " ,");

    // Loop through each word in sentence and check for keywords
    while (word != NULL) {
      if (strcmp(word, "happy") == 0 || strcmp(word, "joyful") == 0 || strcmp(word, "delighted") == 0) {
        happy_count++;
        keyword_count++;
      } else if (strcmp(word, "sad") == 0 || strcmp(word, "unhappy") == 0 || strcmp(word, "depressed") == 0) {
        keyword_count++;
      }

      word = strtok(NULL, " ,");
    }

    // Print sentence if it contains keywords and is a reasonable length
    if (keyword_count > 0 && strlen(sentence) < 50) {
      printf("- %s.\n", sentence);
    }

    sentence = strtok(NULL, ".?!");
  }

  printf("\nThat's it! Have a happy day :)\n");

  return 0;
}