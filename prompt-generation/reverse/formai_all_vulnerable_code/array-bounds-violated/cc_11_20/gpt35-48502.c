//FormAI DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000 // maximum length of each line in the C program

int main(int argc, char *argv[]) {
  char *filename = argv[1]; // filename of the input C program
  FILE *fp = fopen(filename, "r"); // open the input file in read mode
  char line[MAX_LEN]; // buffer to read each line in the program

  // check if the input file is valid
  if (fp == NULL) {
    printf("Error: Unable to open file %s\n", filename);
    exit(1);
  }

  int lineno = 1; // line number of the program being parsed
  int braces = 0; // number of open braces in the program

  // read each line in the program and check its syntax
  while (fgets(line, MAX_LEN, fp)) {
    // check for missing semicolons
    if (line[strlen(line) - 2] != ';' && line[strlen(line) - 2] != '{') {
      printf("Error: Missing semicolon at line %d\n", lineno);
      exit(1);
    } 

    // check for missing parentheses
    int open_parens = 0;
    int closed_parens = 0;
    for (int i = 0; i < strlen(line) - 1; i++) {
      if (line[i] == '(') {
        open_parens++;
      } else if (line[i] == ')') {
        closed_parens++;
      }
    }
    if (open_parens != closed_parens) {
      printf("Error: Unmatched parentheses at line %d\n", lineno);
      exit(1);
    }

    // check for missing braces
    for (int i = 0; i < strlen(line) - 1; i++) {
      if (line[i] == '{') {
        braces++;
      } else if (line[i] == '}') {
        braces--;
      }
    }

    // check if all braces have been closed properly
    if (braces < 0) {
      printf("Error: Unmatched closing brace at line %d\n", lineno);
      exit(1);
    }

    lineno++;
  }

  // check if all braces have been closed properly at the end of the program
  if (braces != 0) {
    printf("Error: Unmatched opening brace at line %d\n", lineno);
    exit(1);
  }

  printf("Syntax of the program is correct.\n");

  return 0;
}