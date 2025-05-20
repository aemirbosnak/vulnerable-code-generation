//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#define RUNTIME_EDITOR "vi"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input = fopen(argv[1], "r");
  if (input == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }

  char *line = NULL;
  size_t line_size = 0;
  ssize_t line_length;
  int line_count = 0;

  while ((line_length = getline(&line, &line_size, input)) != -1) {
    line_count++;

    // Strip whitespace from the beginning and end of the line
    char *start = line;
    while (isspace(*start)) {
      start++;
    }
    char *end = start + line_length - 1;
    while (end >= start && isspace(*end)) {
      end--;
    }
    if (end < start) {
      end = start;
    }

    // Process the line
    char *word = start;
    int word_length;
    int polarity = 0;
    while (word <= end) {
      // Find the end of the current word
      word_length = 1;
      while (word + word_length <= end && !isspace(*(word + word_length))) {
        word_length++;
      }

      // Calculate the polarity of the word
      int i;
      for (i = 0; i < word_length; i++) {
        if (isupper(*(word + i))) {
          polarity -= 1;
        } else if (islower(*(word + i))) {
          polarity += 1;
        }
      }

      // Move to the next word
      word = word + word_length + 1;
    }

    // Print the polarity of the line
    printf("%d\n", polarity);
  }

  free(line);
  fclose(input);

  return EXIT_SUCCESS;
}