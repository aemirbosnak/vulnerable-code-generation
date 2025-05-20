//FormAI DATASET v1.0 Category: Syntax parsing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 1000

// Function to check if the opening and closing delimiters are a matching pair
int checkMatchingPair(char openDelim, char closedDelim) {
  if (openDelim == '(' && closedDelim == ')') {
    return 1;
  } else if (openDelim == '{' && closedDelim == '}') {
    return 1;
  } else if (openDelim == '[' && closedDelim == ']') {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char code[MAX_CODE_LENGTH];
  int i, len, counter = 0;
  char stack[MAX_CODE_LENGTH];
  
  printf("Enter your code block:\n");
  fgets(code, MAX_CODE_LENGTH, stdin);
  
  len = strlen(code);
  
  for (i = 0; i < len; i++) {
    // If the current character is an opening delimiter, push it onto the stack
    if (code[i] == '(' || code[i] == '{' || code[i] == '[') {
      stack[counter] = code[i];
      counter++;
    } 
    // If the current character is a closing delimiter, pop the top of the stack and compare to see if they match
    else if (code[i] == ')' || code[i] == '}' || code[i] == ']') {
      char openDelim = stack[counter - 1];
      counter--;
      
      if (!checkMatchingPair(openDelim, code[i])) {
        printf("Error: Delimiters do not match.\n");
        exit(0);
      }
    }
  }
  
  if (counter != 0) {
    printf("Error: Code block is missing delimiters.\n");
    exit(0);
  }
  
  printf("Code block is valid.\n");
  
  return 0;
}