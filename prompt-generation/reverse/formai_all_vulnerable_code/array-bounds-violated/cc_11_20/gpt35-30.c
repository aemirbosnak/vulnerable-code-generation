//FormAI DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include<stdio.h>
#include<string.h>

int main() {
  char input[100];
  printf("Enter a C syntax statement: ");
  scanf("%[^\n]s", input);

  // Removing unnecessary whitespace
  char stripped[100];
  int index = 0;
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] != ' ' && input[i] != '\t') {
      stripped[index] = input[i];
      index++;
    }
  }
  stripped[index] = '\0';

  // Checking if statement ends with semicolon
  if(stripped[strlen(stripped) - 1] != ';') {
    printf("Error: Statement should end with a semicolon.\n");
    return 1;
  }

  // Checking if statement starts with data type
  char* types[6] = {"int", "float", "double", "char", "void", "long"};
  char* ptr = strtok(stripped, "()");
  while(ptr != NULL) {
    for(int i = 0; i < 6; i++) {
      if(strcmp(ptr, types[i]) == 0) {
        printf("Data type: %s\n", types[i]);
        break;
      } else if(i == 5) {
        printf("Error: Statement should start with a data type.\n");
        return 1;
      }
    }
    ptr = strtok(NULL, "()");
  }

  // Checking if parentheses are balanced
  int open_paren = 0, close_paren = 0;
  for(int i = 0; i < strlen(stripped); i++) {
    if(stripped[i] == '(') {
      open_paren++;
    } else if(stripped[i] == ')') {
      close_paren++;
    }
  }
  if(open_paren != close_paren) {
    printf("Error: Parentheses are not balanced.\n");
    return 1;
  }

  printf("Syntax statement is valid.\n");
  return 0;
}