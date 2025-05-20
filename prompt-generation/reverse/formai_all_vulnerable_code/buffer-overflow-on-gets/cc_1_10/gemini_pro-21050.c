//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

// Ada Lovelace-inspired C program to beautify HTML

// Function to beautify a single line of HTML
char *beautify_line(char *line) {
  // Allocate memory for the beautified line
  char *beautified_line = malloc(sizeof(char) * MAX_LINE_LENGTH);

  // Initialize the beautified line
  strcpy(beautified_line, "");

  // Iterate over the characters in the line
  int i = 0;
  while (line[i] != '\0') {
    // If the current character is a '<' or '>', add a newline and indent
    if (line[i] == '<' || line[i] == '>') {
      strcat(beautified_line, "\n");
      for (int j = 0; j < i; j++) {
        strcat(beautified_line, " ");
      }
    }

    // Add the current character to the beautified line
    strncat(beautified_line, &line[i], 1);

    // Increment the character index
    i++;
  }

  // Return the beautified line
  return beautified_line;
}

// Function to beautify an array of HTML lines
char **beautify_lines(char **lines, int num_lines) {
  // Allocate memory for the beautified lines
  char **beautified_lines = malloc(sizeof(char *) * MAX_NUM_LINES);

  // Initialize the beautified lines
  for (int i = 0; i < num_lines; i++) {
    beautified_lines[i] = "";
  }

  // Iterate over the lines
  for (int i = 0; i < num_lines; i++) {
    // Beautify the current line
    char *beautified_line = beautify_line(lines[i]);

    // Add the beautified line to the array
    beautified_lines[i] = beautified_line;
  }

  // Return the beautified lines
  return beautified_lines;
}

// Function to print an array of HTML lines
void print_lines(char **lines, int num_lines) {
  // Iterate over the lines
  for (int i = 0; i < num_lines; i++) {
    // Print the current line
    printf("%s", lines[i]);
  }
}

// Main function
int main() {
  // Get the HTML input from the user
  char *html = malloc(sizeof(char) * MAX_LINE_LENGTH);
  printf("Enter HTML code: ");
  gets(html);

  // Split the HTML input into lines
  char **lines = malloc(sizeof(char *) * MAX_NUM_LINES);
  int num_lines = 0;
  char *line = strtok(html, "\n");
  while (line != NULL) {
    lines[num_lines] = line;
    num_lines++;
    line = strtok(NULL, "\n");
  }

  // Beautify the HTML lines
  char **beautified_lines = beautify_lines(lines, num_lines);

  // Print the beautified HTML lines
  print_lines(beautified_lines, num_lines);

  // Free the memory allocated for the HTML input, lines, and beautified lines
  free(html);
  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
    free(beautified_lines[i]);
  }
  free(lines);
  free(beautified_lines);

  return 0;
}