//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Read the word list into an array of strings
  char *words[MAX_WORDS];
  FILE *file = fopen("words.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening word list file\n");
    exit(1);
  }
  int i = 0;
  while (fscanf(file, "%s", words[i]) != EOF) {
    i++;
  }
  fclose(file);

  // Get the user's input
  char input[MAX_WORD_LEN];
  printf("Type the following words as quickly and accurately as possible:\n");
  for (i = 0; i < MAX_WORDS; i++) {
    printf("%s ", words[i]);
  }
  printf("\n");

  // Start the timer
  time_t start = time(NULL);

  // Get the user's input
  i = 0;
  while (i < MAX_WORDS) {
    scanf("%s", input);
    if (strcmp(input, words[i]) == 0) {
      i++;
    } else {
      printf("Incorrect! The correct word is %s\n", words[i]);
    }
  }

  // Stop the timer
  time_t end = time(NULL);

  // Calculate the typing speed
  double speed = (double)i / (end - start);

  // Print the results
  printf("Your typing speed is %.2f words per minute\n", speed);

  return 0;
}