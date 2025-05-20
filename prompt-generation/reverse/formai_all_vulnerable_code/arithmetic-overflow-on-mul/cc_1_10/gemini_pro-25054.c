//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str) {
  int i, count = 1;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ' && str[i + 1] != ' ') {
      count++;
    }
  }
  return count;
}

// Function to create a summary of a text
char *summarizeText(char *text, int numWords) {
  // Count the number of words in the text
  int numWordsInText = countWords(text);

  // Check if the number of words in the summary is valid
  if (numWords > numWordsInText) {
    printf("Error: The number of words in the summary cannot be greater than the number of words in the text.\n");
    return NULL;
  }

  // Create an array to store the summary
  char *summary = (char *)malloc(numWords * 20);

  // Initialize the summary with the first word
  int i, j, k = 0;
  for (i = 0; i < numWords; i++) {
    // Find the next space character
    while (text[j] != ' ' && text[j] != '\0') {
      j++;
    }

    // Copy the word to the summary
    for (k = 0; k < j - i; k++) {
      summary[k] = text[i + k];
    }
    summary[k] = ' ';
    k++;

    // Move to the next word
    i = j + 1;
  }

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text: ");
  scanf("%[^\n]s", text);

  // Get the number of words in the summary
  int numWords;
  printf("Enter the number of words in the summary: ");
  scanf("%d", &numWords);

  // Create the summary
  char *summary = summarizeText(text, numWords);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the memory allocated for the summary
  free(summary);

  return 0;
}