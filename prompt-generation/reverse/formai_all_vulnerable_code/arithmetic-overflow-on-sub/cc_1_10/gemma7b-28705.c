//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <time.h>

int main() {
  int speed, time, i, total_words = 0, total_chars = 0;
  char text[1000];

  // Initialize the clock
  clock_t start, end;

  // Get the text from the user
  printf("Please paste the text you want to type:");
  gets(text);

  // Start the clock
  start = clock();

  // Type the text as fast as you can
  for (i = 0; text[i] != '\0'; i++) {
    printf("%c", text[i]);
  }

  // Stop the clock
  end = clock();

  // Calculate the time taken
  time = (end - start) / CLOCKS_PER_SEC;

  // Calculate the words and characters typed
  total_words = words_in_text(text);
  total_chars = characters_in_text(text);

  // Display the results
  printf("\nYour typing speed is: %.2f words per second", (double)total_words / time);
  printf("\nYour total number of characters typed is: %d", total_chars);

  return 0;
}

int words_in_text(char *text) {
  int words = 0;

  // Count the number of words in the text
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] == ' ' || text[i] == '\n') {
      words++;
    }
  }

  return words;
}

int characters_in_text(char *text) {
  int chars = 0;

  // Count the number of characters in the text
  for (int i = 0; text[i] != '\0'; i++) {
    chars++;
  }

  return chars;
}