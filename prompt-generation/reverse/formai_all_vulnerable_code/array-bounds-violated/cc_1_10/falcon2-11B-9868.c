//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: excited
#include <stdio.h>
#include <string.h>

// Function to generate summary of a given text
void summarize(char* text) {
  // Split the text into words
  char* words[100];
  int num_words = 0;
  int i = 0;

  // Find number of words in the text
  while (text[i]!= '\0') {
    words[num_words++] = text + i;
    i += strlen(text + i);
  }

  // Sort the words based on frequency
  int freq[100];
  memset(freq, 0, sizeof(freq));
  for (int j = 0; j < num_words; j++) {
    freq[words[j][0] - 'a']++;
  }

  // Find most frequent words
  int max_freq = 0;
  int max_word_index = -1;
  for (int k = 0; k < 26; k++) {
    if (freq[k] > max_freq) {
      max_freq = freq[k];
      max_word_index = k;
    }
  }

  // Generate summary
  char* summary = (char*)malloc(50 * sizeof(char));
  strcpy(summary, "The summary is: ");
  strcat(summary, words[max_word_index]);
  strcat(summary, " ");
  strcat(summary, words[max_word_index + 1]);
  strcat(summary, " ");
  strcat(summary, words[max_word_index + 2]);
  printf("%s\n", summary);
}

int main() {
  char text[100];
  printf("Enter the text: ");
  fgets(text, sizeof(text), stdin);

  // Remove trailing newline character
  text[strcspn(text, "\n")] = '\0';

  // Generate summary
  summarize(text);

  return 0;
}