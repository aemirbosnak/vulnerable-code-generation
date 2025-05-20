//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to preprocess the text
char *preprocess(char *text) {
  // Convert all characters to lowercase
  for (int i = 0; i < strlen(text); i++) {
    text[i] = tolower(text[i]);
  }

  // Remove all punctuation and special characters
  char *new_text = malloc(strlen(text) + 1);
  int j = 0;
  for (int i = 0; i < strlen(text); i++) {
    if ((text[i] >= 'a' && text[i] <= 'z') || text[i] == ' ') {
      new_text[j++] = text[i];
    }
  }

  return new_text;
}

// Function to calculate the frequency of each word
int *calculate_frequency(char *text) {
  int *frequency = malloc(26 * sizeof(int));
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      frequency[text[i] - 'a']++;
    }
  }

  return frequency;
}

// Function to extract the top 5 frequent words
char **extract_top_words(int *frequency) {
  char **top_words = malloc(5 * sizeof(char *));

  // Find the indices of the top 5 frequent words
  int top_indices[5];
  for (int i = 0; i < 5; i++) {
    int max_index = -1;
    int max_frequency = -1;
    for (int j = 0; j < 26; j++) {
      if (frequency[j] > max_frequency) {
        max_index = j;
        max_frequency = frequency[j];
      }
    }

    frequency[max_index] = -1;  // Mark the word as processed
    top_indices[i] = max_index;
  }

  // Convert the indices to words
  for (int i = 0; i < 5; i++) {
    top_words[i] = malloc(2);
    top_words[i][0] = top_indices[i] + 'a';
    top_words[i][1] = '\0';
  }

  return top_words;
}

// Function to summarize the text
char *summarize(char *text) {
  // Preprocess the text
  char *preprocessed_text = preprocess(text);

  // Calculate the frequency of each word
  int *frequency = calculate_frequency(preprocessed_text);

  // Extract the top 5 frequent words
  char **top_words = extract_top_words(frequency);

  // Construct the summary
  char *summary = malloc(100);
  strcpy(summary, "Here's a summary of the text: ");
  for (int i = 0; i < 5; i++) {
    strcat(summary, top_words[i]);
    strcat(summary, ", ");
  }

  free(preprocessed_text);
  free(frequency);
  for (int i = 0; i < 5; i++) {
    free(top_words[i]);
  }
  free(top_words);

  return summary;
}

int main() {
  // Get the input text
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize(text);

  // Print the summary
  printf("Summary: %s\n", summary);

  free(summary);
  return 0;
}