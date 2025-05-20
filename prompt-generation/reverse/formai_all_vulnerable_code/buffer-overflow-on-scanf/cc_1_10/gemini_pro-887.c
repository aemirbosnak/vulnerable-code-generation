//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function checks if the input string contains any naughty words.
int is_naughty(char *input) {
  char *naughty_words[] = {"damn", "hell", "shit", "fuck", "cunt"};
  int num_naughty_words = sizeof(naughty_words) / sizeof(char *);

  for (int i = 0; i < num_naughty_words; i++) {
    if (strstr(input, naughty_words[i]) != NULL) {
      return 1;
    }
  }

  return 0;
}

// This function sanitizes the input string by replacing any naughty words with the string "CENSORED".
char *sanitize_input(char *input) {
  char *sanitized_input = malloc(strlen(input) + 1);
  strcpy(sanitized_input, input);

  char *naughty_words[] = {"damn", "hell", "shit", "fuck", "cunt"};
  int num_naughty_words = sizeof(naughty_words) / sizeof(char *);

  for (int i = 0; i < num_naughty_words; i++) {
    char *naughty_word = naughty_words[i];
    int naughty_word_len = strlen(naughty_word);

    char *pos = sanitized_input;
    while ((pos = strstr(pos, naughty_word)) != NULL) {
      memset(pos, 'X', naughty_word_len);
      pos += naughty_word_len;
    }
  }

  return sanitized_input;
}

int main() {
  char input[1024];

  printf("Enter your input: ");
  scanf("%s", input);

  if (is_naughty(input)) {
    printf("Your input contains naughty words. Please try again.\n");
  } else {
    char *sanitized_input = sanitize_input(input);
    printf("Your sanitized input is: %s\n", sanitized_input);
    free(sanitized_input);
  }

  return 0;
}