//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize the text.
char* summarize(char* text) {
  // Check if the text is empty.
  if (!text || strlen(text) == 0) {
    return NULL;
  }

  // Tokenize the text into words.
  char** words = malloc(strlen(text) * sizeof(char*));
  int num_words = 0;
  char* word = strtok(text, " ");
  while (word != NULL) {
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " ");
  }

  // Count the frequency of each word.
  int* frequencies = malloc(num_words * sizeof(int));
  for (int i = 0; i < num_words; i++) {
    frequencies[i] = 0;
    for (int j = 0; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        frequencies[i]++;
      }
    }
  }

  // Find the most frequent words.
  int max_frequency = 0;
  for (int i = 0; i < num_words; i++) {
    if (frequencies[i] > max_frequency) {
      max_frequency = frequencies[i];
    }
  }

  // Generate the summary.
  char* summary = malloc(100);
  int num_summary_words = 0;
  for (int i = 0; i < num_words; i++) {
    if (frequencies[i] == max_frequency) {
      summary[num_summary_words] = words[i];
      num_summary_words++;
    }
  }

  // Return the summary.
  return summary;
}

// Main function.
int main() {
  // Get the text from the user.
  char text[1000];
  printf("Enter the text: ");
  gets(text);

  // Summarize the text.
  char* summary = summarize(text);

  // Print the summary.
  printf("Summary: %s\n", summary);

  return 0;
}