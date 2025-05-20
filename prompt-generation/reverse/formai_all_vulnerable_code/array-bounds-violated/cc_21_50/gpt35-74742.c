//FormAI DATASET v1.0 Category: HTML beautifier ; Style: careful
// A simple C program to beautify HTML code 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000], output[1000];     // declaring variables to store input and output
  int i, j;                           // loop variables
  int indent_level = 0;               // to keep track of indent level
  int is_tag = 0;                     // to keep track if character is inside tag
  int is_single = 0;                  // to keep track if tag is self closing
  int is_comment = 0;                 // to keep track if character is inside comment
  int is_literal = 0;                 // to keep track if character is inside a literal
  int len = 0;                        // to keep track of length of current tag/ comment/ literal
  int last_char_was_space = 0;        // to keep track of whether last character printed was a space
  int last_char_was_newline = 0;      // to keep track of whether last character printed was a newline
  
  // Taking input from user
  printf("Enter the HTML code:\n");
  fgets(input, 1000, stdin);
  int input_len = strlen(input);
  
  // Loop through each character of input and beautify the code
  for (i = 0, j = 0; i < input_len; i++) {
    if (input[i] == '<') {
      is_tag = 1;
      len = 1;
      if (input[i+1] == '/') {
        indent_level--;
        i += 2;
        len++;
      }
      else if (input[i+1] == '!') {
        is_comment = 1;
        i += 2;
        len += 2;
      }
      else if (input[i+1] == '?') {
        i += 2;
        len += 2;
      }
      else {
        indent_level++;
        i++;
      }
    }
    else if (input[i] == '>') {
      is_tag = 0;
      if (input[i-1] == '/') {
        is_single = 1;
      }
      len++;
      if (last_char_was_space || last_char_was_newline) {
        len--;
        j--;
      }
    }
    else if (input[i] == '"' || input[i] == '\'') {
      is_literal = !is_literal;
    }
    else if (is_comment) {
      len++;
    }
    else {
      len++;
    }
    
    if (is_single) {
      indent_level--;
      is_single = 0;
    }
    if (input[i] == '\n') {
      last_char_was_newline = 1;
    }
    else if (input[i] == ' ' || input[i] == '\t') {
      last_char_was_space = 1;
    }
    else {
      last_char_was_space = 0;
      last_char_was_newline = 0;
    }
    
    if (len == 1) {
      output[j++] = input[i];
    }
    else {
      if (last_char_was_newline) {
        int k;
        for (k = 0; k < indent_level; k++) {
          output[j++] = '\t';
        }
      }
      output[j++] = input[i];
      if (!is_literal && !is_comment && input[i] == '>') {
        output[j++] = '\n';
        last_char_was_newline = 1;
      }
    }
    
    if (input[i] == '-' && is_comment) {
      if (i > len && input[i-1] == '-') {
        is_comment = 0;
        len++;
      }
    }
  }
  output[j] = '\0';   // adding null character at the end of output
  
  // Printing the beautified HTML code
  printf("Formatted HTML:\n%s", output);

  return 0;   // End of program
}