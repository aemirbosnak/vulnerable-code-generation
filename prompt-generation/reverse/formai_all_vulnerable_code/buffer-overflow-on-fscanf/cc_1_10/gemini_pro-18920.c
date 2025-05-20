//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 30

char *words[MAX_WORDS];
char *word;
char *buffer;
int numWords;
int numChars;
int numErrors;
int numCorrect;
int totalChars;
int totalWords;
int totalErrors;
int totalCorrect;
int speedWPM;
int accuracy;
time_t start;
time_t end;
double elapsed;

void init() {
  // Read the word list from a file.
  FILE *fp = fopen("words.txt", "r");
  if (fp == NULL) {
    printf("Error: could not open the word list file.\n");
    exit(1);
  }
  numWords = 0;
  while (fscanf(fp, "%s", word) != EOF) {
    words[numWords++] = strdup(word);
  }
  fclose(fp);

  // Initialize the other variables.
  numChars = 0;
  numErrors = 0;
  numCorrect = 0;
  totalChars = 0;
  totalWords = 0;
  totalErrors = 0;
  totalCorrect = 0;
  speedWPM = 0;
  accuracy = 0;
  start = time(NULL);
  end = time(NULL);
  elapsed = 0.0;
  buffer = malloc(MAX_WORD_LEN * sizeof(char));
}

void cleanup() {
  // Free the memory that was allocated for the word list.
  for (int i = 0; i < numWords; i++) {
    free(words[i]);
  }

  // Free the memory that was allocated for the buffer.
  free(buffer);
}

int main() {
  // Initialize the program.
  init();

  // Get the user's input.
  printf("Type the following text as fast and accurately as you can:\n");
  while (gets(buffer) != NULL) {
    // Check if the user's input matches the word.
    if (strcmp(buffer, word) == 0) {
      // The user's input is correct.
      numCorrect++;
    } else {
      // The user's input is incorrect.
      numErrors++;
    }

    // Update the other variables.
    numChars += strlen(buffer);
    totalChars += strlen(buffer);
    totalWords++;
    totalErrors += numErrors;
    totalCorrect += numCorrect;
    speedWPM = (int) ((numChars / 5.0) / elapsed * 60.0);
    accuracy = (int) ((numCorrect / (double) (numCorrect + numErrors)) * 100.0);
    start = time(NULL);

    // Print the results.
    printf("\n** Results **\n");
    printf("Total words: %d\n", totalWords);
    printf("Total correct: %d\n", totalCorrect);
    printf("Total errors: %d\n", totalErrors);
    printf("Speed: %d WPM\n", speedWPM);
    printf("Accuracy: %d%%\n", accuracy);
  }

  // Cleanup the program.
  cleanup();

  return 0;
}