//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
// Retro Text to ASCII Art Generator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII art character set
static const char *ascii_chars = " .:-=+*#%@";

// Function to convert a character to an ASCII art representation
char *char_to_ascii(char c) {
  int index = (c - ' ') * strlen(ascii_chars) / 128;
  return strndup(ascii_chars + index, 1);
}

// Function to convert a string to an ASCII art representation
char *string_to_ascii(const char *str) {
  char *ascii_str = malloc(strlen(str) * 8 + 1);
  int i;
  for (i = 0; i < strlen(str); i++) {
    strcat(ascii_str, char_to_ascii(str[i]));
  }
  return ascii_str;
}

// Function to generate a random ASCII art character
char random_ascii_char() {
  return ascii_chars[rand() % strlen(ascii_chars)];
}

// Function to generate a random ASCII art string
char *random_ascii_string(int len) {
  char *ascii_str = malloc(len + 1);
  int i;
  for (i = 0; i < len; i++) {
    ascii_str[i] = random_ascii_char();
  }
  ascii_str[len] = '\0';
  return ascii_str;
}

// Print a character in ASCII art
void print_ascii_char(char c) {
  printf("%s", char_to_ascii(c));
}

// Print a string in ASCII art
void print_ascii_string(const char *str) {
  printf("%s\n", string_to_ascii(str));
}

// Print a random ASCII art character
void print_random_ascii_char() {
  printf("%c", random_ascii_char());
}

// Print a random ASCII art string
void print_random_ascii_string(int len) {
  printf("%s\n", random_ascii_string(len));
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Print a welcome message
  printf("Welcome to the Retro Text to ASCII Art Generator!\n");

  // Get the user's input
  char input[1024];
  printf("Enter a character, string, or number to convert to ASCII art:\n");
  scanf("%s", input);

  // Convert the input to ASCII art
  char *ascii_output;
  if (strlen(input) == 1) {
    ascii_output = char_to_ascii(input[0]);
  } else if (atoi(input) > 0) {
    ascii_output = random_ascii_string(atoi(input));
  } else {
    ascii_output = string_to_ascii(input);
  }

  // Print the ASCII art output
  printf("ASCII art output:\n");
  printf("%s\n", ascii_output);

  // Free the allocated memory
  free(ascii_output);

  return 0;
}