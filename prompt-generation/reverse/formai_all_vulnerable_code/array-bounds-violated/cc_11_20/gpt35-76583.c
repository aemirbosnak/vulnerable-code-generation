//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: summarizer <input file> <output file>\n");
    return 1;
  }

  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Error: Unable to open input file\n");
    return 1;
  }

  FILE *output_file = fopen(argv[2], "w");
  if (output_file == NULL) {
    fclose(input_file);
    printf("Error: Unable to open output file\n");
    return 1;
  }

  char buffer[2048]; // buffer for reading files
  char summary[1024]; // summary buffer, max length of 1024 characters
  int summary_length = 0;
  int sentence_count = 0;
  int target_sentence_count = 5;

  while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
    int buffer_length = strlen(buffer);

    // Remove trailing newline if present
    if (buffer[buffer_length - 1] == '\n') {
      buffer[buffer_length - 1] = '\0';
      buffer_length--;
    }

    // Split text into sentences and summarize
    char *sentence = strtok(buffer, ".!?"); // Split at end of sentence
    while (sentence != NULL) {
      int sentence_length = strlen(sentence);

      // Remove leading/trailing whitespace
      while (isspace(sentence[0])) {
        sentence++;
        sentence_length--;
      }
      while (isspace(sentence[sentence_length - 1])) {
        sentence_length--;
      }

      // Capitalize first letter
      sentence[0] = toupper(sentence[0]);

      // Add sentence to summary if not too long
      if (summary_length + sentence_length < sizeof(summary) - 1) {
        strcat(summary, sentence);
        strcat(summary, ". ");
        summary_length += sentence_length + 2; // Add 2 for period and space
        sentence_count++;
      }

      // Check if we've reached the desired number of sentences
      if (sentence_count == target_sentence_count) {
        break;
      }

      // Get next sentence
      sentence = strtok(NULL, ".!?");
    }

    // Check if we've reached the desired number of sentences
    if (sentence_count == target_sentence_count) {
      break;
    }
  }

  // Write summary to output file
  fprintf(output_file, "%s", summary);

  // Close files and exit
  fclose(input_file);
  fclose(output_file);
  return 0;
}