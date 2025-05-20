//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
// Welcome to our unique Sentiment Analysis Tool!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our maximum string length
#define MAX_LENGTH 1000

int main() {

  // Variables
  char input[MAX_LENGTH];
  int positive = 0;
  int negative = 0;
  int neutral = 0;
  char *filename = "input.txt";
  FILE *file = fopen(filename, "r");

  // Check if file could be opened
  if (file == NULL) {
    printf("Could not open file %s", filename);
    return 0;
  }

  // Read strings from file
  while (fgets(input, MAX_LENGTH, file) != NULL) {

    // Loop through string to check for positive/negative words
    for (int i = 0; i < strlen(input); i++) {
      char current_char = input[i];
      char next_char = input[i+1];

      // Check for positive words
      if (current_char == 'g' && next_char == 'o' && (input[i-1] == ' ' || i == 0) && (input[i+2] == ' ' || next_char == '\n')) {
        positive++;
      } else if (current_char == 'a' && next_char == 'm' && (input[i-1] == ' ' || i == 0) && (input[i+2] == ' ' || next_char == '\n')) {
        positive++;
      } else if (current_char == 'a' && next_char == 'w' && (input[i-1] == ' ' || i == 0) && (input[i+2] == ' ' || next_char == '\n')) {
        positive++;
      } 

      // Check for negative words
      if (current_char == 'n' && next_char == 'o' && (input[i-1] == ' ' || i == 0) && (input[i+2] == ' ' || next_char == '\n')) {
        negative++;
      } else if (current_char == 'd' && next_char == 'i' && (input[i-1] == ' ' || i == 0) && (input[i+2] == ' ' || next_char == '\n')) {
        negative++;
      } else if (current_char == 'b' && next_char == 'a' && (input[i-1] == ' ' || i == 0) && (input[i+2] == ' ' || next_char == '\n')) {
        negative++;
      } 

    }

  }

  // Close file
  fclose(file);

  // Determine sentiment
  if (positive > negative) {
    printf("Great news! The sentiment of the text is positive.\n");
  } else if (positive < negative) {
    printf("Oh no! The sentiment of the text is negative.\n");
  } else {
    printf("Hm, seems like the sentiment of the text is neutral.\n");
  }

  return 0;

}