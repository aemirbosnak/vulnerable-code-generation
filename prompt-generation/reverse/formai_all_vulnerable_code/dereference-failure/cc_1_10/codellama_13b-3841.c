//Code Llama-13B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  char input_file[MAX_FILE_NAME_LENGTH];
  char output_file[MAX_FILE_NAME_LENGTH];
  strcpy(input_file, argv[1]);
  strcpy(output_file, argv[2]);

  FILE *input = fopen(input_file, "r");
  if (input == NULL) {
    printf("Error opening input file: %s\n", input_file);
    return 1;
  }

  FILE *output = fopen(output_file, "w");
  if (output == NULL) {
    printf("Error opening output file: %s\n", output_file);
    fclose(input);
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, input) != NULL) {
    int length = strlen(line);
    for (int i = 0; i < length; i++) {
      if (isspace(line[i])) {
        continue;
      }
      if (isalpha(line[i])) {
        line[i] = tolower(line[i]);
      }
    }
    fputs(line, output);
  }

  fclose(input);
  fclose(output);
  return 0;
}