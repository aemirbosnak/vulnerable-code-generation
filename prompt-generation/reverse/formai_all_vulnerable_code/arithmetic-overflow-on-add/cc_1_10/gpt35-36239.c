//FormAI DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include<stdio.h>
#define MAX_SIZE 1024

int main() {
  //declare variables
  char input[MAX_SIZE], output[MAX_SIZE];
  int i, j, indent = 0;

  //read input from user
  printf("Enter your HTML code:\n");
  fgets(input, MAX_SIZE, stdin);

  //beautify the code
  for(i = 0; input[i] != '\0'; i++) {
    if(input[i] == '<') {
      output[j] = input[i];
      j++;
      if(input[i+1] == '/') {
        //decrease indent for closing tags
        indent--;
      }
      else {
        //increase indent for opening tags
        indent++;
      }
    }
    else if(input[i] == '>') {
      output[j] = input[i];
      j++;
      if(input[i-1] == '/') {
        //do not change indent for self-closing tags
      }
      else if(input[i-1] == '-') {
        //do not change indent for comments
      }
      else if(input[i-1] != '/') {
        //add newline and indent
        output[j] = '\n';
        j++;
        for(int k = 0; k < indent; k++) {
          output[j] = '\t';
          j++;
        }
      }
    }
    else {
      output[j] = input[i];
      j++;
    }
  }

  //print the beautified code
  printf("Your beautified HTML code is:\n%s", output);

  return 0;
}