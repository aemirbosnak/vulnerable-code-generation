//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum size of the input string
#define MAX_STRING_SIZE 100

// Define the maximum number of characters in a word
#define MAX_WORD_SIZE 20

// Define the maximum number of words in the input string
#define MAX_WORDS 10

// Define the maximum number of characters in an output line
#define MAX_LINE_SIZE 100

// Define the maximum number of lines in the output string
#define MAX_LINES 10

// Define the maximum number of characters in an output string
#define MAX_OUTPUT_SIZE 1000

// Define the input string
char input_string[MAX_STRING_SIZE];

// Define the output string
char output_string[MAX_OUTPUT_SIZE];

// Define the word array
char words[MAX_WORDS][MAX_WORD_SIZE];

// Define the number of words in the input string
int num_words;

// Define the number of lines in the output string
int num_lines;

// Define the current line number
int current_line;

// Define the current character position in the output string
int current_char;

// Define the function to process the input string
void process_input_string() {
  // Get the input string from the user
  printf("Enter the input string: ");
  fgets(input_string, MAX_STRING_SIZE, stdin);

  // Remove the newline character from the input string
  input_string[strlen(input_string) - 1] = '\0';

  // Split the input string into words
  num_words = 0;
  char *word = strtok(input_string, " ");
  while (word != NULL) {
    strcpy(words[num_words], word);
    num_words++;
    word = strtok(NULL, " ");
  }
}

// Define the function to generate the output string
void generate_output_string() {
  // Initialize the output string
  output_string[0] = '\0';

  // Initialize the number of lines in the output string
  num_lines = 0;

  // Initialize the current line number
  current_line = 0;

  // Initialize the current character position in the output string
  current_char = 0;

  // Loop through the words in the input string
  for (int i = 0; i < num_words; i++) {
    // Check if the current word will fit on the current line
    if (current_char + strlen(words[i]) + 1 > MAX_LINE_SIZE) {
      // If the current word will not fit on the current line, start a new line
      output_string[current_char] = '\n';
      current_char++;
      current_line++;
    }

    // Copy the current word to the output string
    strcpy(output_string + current_char, words[i]);
    current_char += strlen(words[i]);

    // Add a space to the output string
    output_string[current_char] = ' ';
    current_char++;
  }

  // Remove the last space from the output string
  output_string[current_char - 1] = '\0';
}

// Define the main function
int main() {
  // Process the input string
  process_input_string();

  // Generate the output string
  generate_output_string();

  // Print the output string
  printf("The output string is:\n%s", output_string);

  return 0;
}