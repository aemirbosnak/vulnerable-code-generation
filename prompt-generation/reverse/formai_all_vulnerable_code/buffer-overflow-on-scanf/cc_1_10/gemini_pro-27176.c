//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our star-crossed lovers.
char *romeo = "Romeo";
char *juliet = "Juliet";

// Define the function to summarize the text.
void summarize(char *text) {
  // Create an array to store the summary.
  char summary[500];

  // Copy the first sentence of the text into the summary.
  char *firstSentence = strtok(text, ".");
  strcpy(summary, firstSentence);

  // Find the next sentence that contains the name of one of the lovers.
  char *nextSentence;
  while ((nextSentence = strtok(NULL, ".")) != NULL) {
    if (strstr(nextSentence, romeo) != NULL || strstr(nextSentence, juliet) != NULL) {
      // Append the next sentence to the summary.
      strcat(summary, " ");
      strcat(summary, nextSentence);
    }
  }

  // Print the summary.
  printf("%s", summary);
}

// Get the text from the user.
char *getInput() {
  // Allocate memory for the text.
  char *text = malloc(500);

  // Get the text from the user.
  printf("Enter the text you want to summarize: ");
  scanf("%s", text);

  // Return the text.
  return text;
}

// Main function.
int main() {
  // Get the text from the user.
  char *text = getInput();

  // Summarize the text.
  summarize(text);

  // Free the memory allocated for the text.
  free(text);

  return 0;
}