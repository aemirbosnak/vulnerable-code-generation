//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *inputFile, *outputFile;
  char inputName[50], outputName[50], line[100];

  // Get input file name
  printf("Enter the input filename: ");
  scanf("%s", inputName);

  // Open input file
  inputFile = fopen(inputName, "r");
  if (inputFile == NULL) {
    printf("Error opening input file.");
    return 1;
  }

  // Get output file name
  printf("\nEnter the output filename: ");
  scanf("%s", outputName);

  // Open output file
  outputFile = fopen(outputName, "w");
  if (outputFile == NULL) {
    printf("Error creating output file.");
    return 1;
  }

  // Read input file line by line, modify data, and write to output file
  while (fgets(line, sizeof(line), inputFile) != NULL) {
    // Modify data
    // For example, replace all commas with semicolons
    for (int i = 0; line[i] != '\0'; i++) {
      if (line[i] == ',') {
        line[i] = ';';
      }
    }

    // Write modified line to output file
    fputs(line, outputFile);
  }

  // Close files
  fclose(inputFile);
  fclose(outputFile);

  printf("\nFile successfully processed!\n");

  return 0;
}