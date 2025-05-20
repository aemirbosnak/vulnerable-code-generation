//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

// Indentation level
int indentLevel = 0;

// Output buffer
char output[MAX_LINE_LENGTH];

// Indentation string
char *indentString = "    ";

// HTML tags that should be indented
char *indentedTags[] = {
  "html", "head", "body", "div", "ul", "ol", "li", "p", "h1", "h2", "h3", "h4", "h5", "h6"
};

// Function to indent a line of HTML
void indentLine(char *line) {
  // Add the appropriate number of indentation strings to the output buffer
  for (int i = 0; i < indentLevel; i++) {
    strcat(output, indentString);
  }

  // Add the line to the output buffer
  strcat(output, line);
}

// Function to beautify a line of HTML
void beautifyLine(char *line) {
  // Remove leading and trailing whitespace
  while (*line == ' ') {
    line++;
  }
  while (line[strlen(line) - 1] == ' ') {
    line[strlen(line) - 1] = '\0';
  }

  // Check if the line is an opening tag
  if (line[0] == '<' && line[1] != '/') {
    // Increase the indentation level
    indentLevel++;

    // Indent the line
    indentLine(line);

    // Add a newline to the output buffer
    strcat(output, "\n");
  }
  // Check if the line is a closing tag
  else if (line[0] == '<' && line[1] == '/') {
    // Decrease the indentation level
    indentLevel--;

    // Indent the line
    indentLine(line);

    // Add a newline to the output buffer
    strcat(output, "\n");
  }
  // Check if the line is an indented tag
  else if (strstr(line, indentString) != NULL) {
    // Indent the line
    indentLine(line);

    // Add a newline to the output buffer
    strcat(output, "\n");
  }
  // Check if the line is a self-closing tag
  else if (line[strlen(line) - 1] == '/') {
    // Indent the line
    indentLine(line);

    // Add a newline to the output buffer
    strcat(output, "\n");
  }
  // Otherwise, the line is a text node
  else {
    // Indent the line
    indentLine(line);

    // Add a newline to the output buffer
    strcat(output, "\n");
  }
}

// Function to beautify a string of HTML
char *beautifyHTML(char *html) {
  // Split the HTML into lines
  char *lines[MAX_LINE_LENGTH];
  int numLines = 0;
  char *line = strtok(html, "\n");
  while (line != NULL) {
    lines[numLines++] = line;
    line = strtok(NULL, "\n");
  }

  // Beautify each line
  for (int i = 0; i < numLines; i++) {
    beautifyLine(lines[i]);
  }

  // Return the beautified HTML
  return output;
}

// Main function
int main() {
  // Get the HTML from the user
  char html[MAX_LINE_LENGTH];
  printf("Enter HTML: ");
  gets(html);

  // Beautify the HTML
  char *beautifiedHTML = beautifyHTML(html);

  // Print the beautified HTML
  printf("Beautified HTML:\n%s", beautifiedHTML);

  return 0;
}