//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of characters in a line of input
#define MAX_LINE_LENGTH 1024

// Create a structure to represent a single line of input
typedef struct line_of_input {
  char *line;
  int line_length;
} line_of_input;

// Create a function to read a single line of input from the user
line_of_input read_line_of_input() {
  char line[MAX_LINE_LENGTH];
  int line_length;

  // Read a line of input from the user
  fgets(line, MAX_LINE_LENGTH, stdin);

  // Calculate the length of the line
  line_length = strlen(line);

  // Remove the newline character from the end of the line
  if (line[line_length - 1] == '\n') {
    line[line_length - 1] = '\0';
  }

  // Create a new line of input structure and copy the line and line length into it
  line_of_input new_line_of_input;
  new_line_of_input.line = strdup(line);
  new_line_of_input.line_length = line_length;

  // Return the new line of input structure
  return new_line_of_input;
}

// Create a function to free the memory allocated for a line of input
void free_line_of_input(line_of_input *line_of_input) {
  // Free the memory allocated for the line
  free(line_of_input->line);

  // Free the memory allocated for the line of input structure
  free(line_of_input);
}

// Create a function to count the number of words in a line of input
int count_words_in_line_of_input(line_of_input *line_of_input) {
  int word_count = 0;
  int in_word = 0;

  // Iterate over each character in the line
  for (int i = 0; i < line_of_input->line_length; i++) {
    // If the character is a space, then we are not in a word
    if (line_of_input->line[i] == ' ') {
      in_word = 0;
    }
    // If the character is not a space, then we are in a word
    else {
      if (!in_word) {
        word_count++;
        in_word = 1;
      }
    }
  }

  // Return the word count
  return word_count;
}

// Create a function to count the number of lines of input
int count_lines_of_input() {
  int line_count = 0;
  char line[MAX_LINE_LENGTH];

  // Read a line of input from the user
  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    // Increment the line count
    line_count++;
  }

  // Return the line count
  return line_count;
}

// Create a function to print the results
void print_results(int word_count, int line_count) {
  // Print the word count
 printf("Word count: %d\n", word_count);

  // Print the line count
  printf("Line count: %d\n", line_count);
}

// Create a function to run the program
void run_program() {
  // Read a line of input from the user
  line_of_input line_of_input = read_line_of_input();

  // Count the number of words in the line of input
  int word_count = count_words_in_line_of_input(&line_of_input);

  // Count the number of lines of input
  int line_count = count_lines_of_input();

  // Print the results
  print_results(word_count, line_count);

  // Free the memory allocated for the line of input
  free_line_of_input(&line_of_input);
}

// Create a main function to call the run_program function
int main() {
  // Run the program
  run_program();

  // Return 0 to indicate that the program ran successfully
  return 0;
}