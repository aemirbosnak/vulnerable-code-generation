//FormAI DATASET v1.0 Category: Syntax parsing ; Style: high level of detail
#include <stdio.h>
#define MAX_SIZE 100

int main() {
  char input[MAX_SIZE];
  int length = 0;
  int index = 0;
  
  printf("Enter a C syntax expression: ");
  fgets(input, MAX_SIZE, stdin);
  
  // Count length of input
  while(input[length] != '\0') {
    length++;
  }
  
  // Check for invalid characters
  for(index = 0; index < length; index++) {
    char current = input[index];
    if(!((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9') || current == ' ' || current == ',' || current == '(' || current == ')' || current == '{' || current == '}' || current == ';' || current == '<' || current == '>' || current == '=')) {
      printf("Error: Invalid character '%c'\n", current);
      return 1;
    }
  }
  
  // Check for missing semicolon
  if(input[length - 2] != ';') {
    printf("Error: Missing semicolon\n");
    return 1;
  }
  
  // Tokenize input
  char* tokens[10];
  int numTokens = 0;
  char* current = strtok(input, " \t\n(),;{}<>=+");
  while(current != NULL && numTokens < 10) {
    tokens[numTokens] = current;
    numTokens++;
    current = strtok(NULL, " \t\n(),;{}<>=+");
  }
  
  // Check for valid syntax
  if(numTokens == 4 && strcmp(tokens[0], "int") == 0 && strcmp(tokens[2], "=") == 0) {
    // Valid declaration and initialization
    printf("Syntax is valid: %s %s %s %s\n", tokens[0], tokens[1], tokens[2], tokens[3]);
  } else if(numTokens == 3 && strcmp(tokens[1], "=") == 0) {
    // Valid assignment
    printf("Syntax is valid: %s %s %s\n", tokens[0], tokens[1], tokens[2]);
  } else {
    printf("Syntax is not valid\n");
    return 1;
  }
  
  return 0;
}