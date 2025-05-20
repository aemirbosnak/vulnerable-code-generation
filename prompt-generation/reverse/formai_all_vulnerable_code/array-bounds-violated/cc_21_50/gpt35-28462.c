//FormAI DATASET v1.0 Category: Syntax parsing ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  printf("Welcome to the Post-Apocalyptic C Syntax Parsing Program.\n");
  printf("Please enter your C code:\n");

  char code[1000];
  fgets(code, 1000, stdin); // Get user input

  // Remove any comments from the code
  for(int i = 0; code[i] != '\0'; i++) {
    if(code[i] == '/' && code[i+1] == '/') {
      while(code[i] != '\n') {
        code[i] = ' ';
        i++;
      }
    }
    if(code[i] == '/' && code[i+1] == '*') {
      while(!(code[i] == '*' && code[i+1] == '/')) {
        code[i] = ' ';
        i++;
      }
      code[i] = ' ';
      code[i+1] = ' ';
    }
  }

  // Parse the code for syntax errors
  int indent_level = 0;
  for(int i = 0; code[i] != '\0'; i++) {
    if(code[i] == '{') {
      indent_level++;
    }
    if(code[i] == '}') {
      indent_level--;
    }
    if(code[i] == ';' && indent_level == 0) {
      printf("Error: semicolon outside of function body.\n");
      return 1;
    }
    if(code[i] == '(' && code[i-1] != ' ') {
      printf("Error: function call must have a space between function name and opening parenthesis.\n");
      return 1;
    }
    if(code[i] == ')' && code[i+1] != ' ' && code[i+1] != ';' && code[i+1] != '\n') {
      printf("Error: closing parenthesis must be followed by a space, semicolon, or newline.\n");
      return 1;
    }
    if(code[i] == '{' && code[i-1] != ' ') {
      printf("Error: opening brace must be preceded by a space.\n");
      return 1;
    }
    if(code[i] == '}' && code[i+1] != ';' && code[i+1] != '\n') {
      printf("Error: closing brace must be followed by a semicolon or newline.\n");
      return 1;
    }
  }

  printf("Your code is free of syntax errors. Congratulations survivor!\n");
  return 0;
}