//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_WORD "SPELLING_IS_MAGIC"

int main() {
  // Define a dictionary of words
  char words[] = "cat dog car mouse elephant";
  int words_count = sizeof(words) / sizeof(words[0]);

  // Define a sentence to check spelling
  char sentence[] = "The cate chased it's tail but it got away.";

  // Create a randomized list of words to check spelling
  char *words_list[10];
  int i;
  for (i = 0; i < words_count; i++) {
    words_list[i] = words[i];
  }
  srand(time(NULL));
  for (i = 0; i < 5; i++) {
    words_list[i] = words[rand() % words_count];
  }

  // Check spelling of each word in the sentence
  int errors = 0;
  for (i = 0; i < strlen(sentence); i++) {
    char current_word = sentence[i];
    int j = 0;
    for (j = 0; j < words_count; j++) {
      if (current_word == words_list[j]) {
        break;
      }
    }
    if (j == words_count) {
      errors++;
      printf("Error: %c is not in the dictionary\n", current_word);
    }
  }

  // Print the final score
  if (errors == 0) {
    printf("Congratulations! You got 100% of the words correct!\n");
  } else {
    printf("Oops! You got %d errors out of %d words (%d%%).\n", errors, words_count, errors * 100 / words_count);
  }

  return 0;
}