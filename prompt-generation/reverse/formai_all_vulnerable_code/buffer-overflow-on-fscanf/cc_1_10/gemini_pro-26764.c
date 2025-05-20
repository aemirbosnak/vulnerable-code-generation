//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_words() {
  FILE *f = fopen("words.txt", "r");
  if (f == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while (fscanf(f, "%s", words[num_words]) != EOF) {
    num_words++;
  }

  fclose(f);
}

int main() {
  // Load the words into memory
  load_words();

  // Get the current time
  time_t start = time(NULL);

  // Print the instructions
  printf("Welcome to the Cyberpunk Typing Speed Test!\n");
  printf("Type the words that appear on the screen as fast as you can.\n");
  printf("Press any key to start the test.\n");
  getchar();

  // Start the test
  int i = 0;
  int errors = 0;
  char input[MAX_WORD_LENGTH];
  while (i < num_words) {
    // Print the word
    printf("%s\n", words[i]);

    // Get the user's input
    scanf("%s", input);

    // Check if the input is correct
    if (strcmp(input, words[i]) != 0) {
      errors++;
    }

    // Move to the next word
    i++;
  }

  // Get the current time
  time_t end = time(NULL);

  // Calculate the typing speed
  double time_taken = difftime(end, start);
  double words_per_minute = (double)num_words / time_taken * 60;

  // Print the results
  printf("Your typing speed is: %.2f words per minute.\n", words_per_minute);
  printf("You made %d errors.\n", errors);

  return 0;
}