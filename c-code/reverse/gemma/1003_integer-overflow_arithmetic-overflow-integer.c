#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
  char text[BUFFER_SIZE];
  printf("Enter text: ");
  fgets(text, BUFFER_SIZE, stdin);

  // Tokenize the text and count word frequency
  char *tokens = strtok(text, " ");
  int word_frequency[256] = {0};
  while (tokens) {
    word_frequency[tokens[0]]++;
    tokens = strtok(NULL, " ");
  }

  // Identify the most important words based on frequency and context
  int summary_length = 0;
  char summary[BUFFER_SIZE] = "";
  for (int i = 0; i < 256; i++) {
    if (word_frequency[i] > 5) {
      char word = i;
      snprintf(summary, BUFFER_SIZE - summary_length, "%s ", word);
      summary_length += strlen(word) + 1;
    }
  }

  // Output the summary
  if (summary_length) {
    printf("Summary: %s", summary);
  } else {
    printf("No summary could be generated.");
  }

  return 0;
}
