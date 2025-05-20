//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some funky colors to spice things up!
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"

// Our very own text processing masterpiece!
int main() {
  // Let's get some text from the user, shall we?
  printf(GREEN "Enter a sentence, my friend: " RESET);
  char sentence[100];
  fgets(sentence, 100, stdin);

  // Time to break it down into words!
  char *words[10]; // Assuming we won't have more than 10 words
  int num_words = 0;

  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Let's have some colorful fun with our words!
  printf("\nBehold, your words in all their glory:\n");
  for (int i = 0; i < num_words; i++) {
    printf(YELLOW "%s " RESET, words[i]);
  }
  printf("\n");

  // Now, let's count the vowels!
  int vowel_count = 0;
  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < strlen(words[i]); j++) {
      char c = words[i][j];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        vowel_count++;
      }
    }
  }

  // And the grand finale: the vowel count!
  printf(CYAN "Vowel count: " RESET "%d\n", vowel_count);

  // Don't forget to clean up!
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }

  return 0;
}