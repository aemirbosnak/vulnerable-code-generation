//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // declare variables
  char input[1000], output[1000], temp[1000];
  int len, i, j, indent = 0;
  FILE *fptr;

  // read input file
  fptr = fopen("input.html", "r");
  if (fptr == NULL) {
    printf("Error opening file!");
    exit(1);
  }
  fgets(input, 1000, fptr);
  fclose(fptr);

  // remove all newlines
  len = strlen(input);
  j = 0;
  for (i = 0; i < len; i++) {
    if (input[i] != '\n') {
      temp[j] = input[i];
      j++;
    }
  }
  temp[j] = '\0';

  // insert newlines at appropriate places
  len = strlen(temp);
  j = 0;
  for (i = 0; i < len; i++) {
    output[j] = temp[i];
    j++;
    if (temp[i] == '<') {
      // increase indent
      for (int k = 0; k < indent; k++) {
        output[j] = ' ';
        j++;
      }
      indent += 2;
    } else if (temp[i] == '>') {
      // decrease indent
      indent -= 2;
      if (output[j-2] == '/') {
        indent += 2;
      }
      output[j] = '\n';
      j++;
      for (int k = 0; k < indent; k++) {
        output[j] = ' ';
        j++;
      }
    }
  }
  output[j] = '\0';

  // write output file
  fptr = fopen("output.html", "w");
  if (fptr == NULL) {
    printf("Error opening file!");
    exit(1);
  }
  fputs(output, fptr);
  fclose(fptr);

  return 0;
}