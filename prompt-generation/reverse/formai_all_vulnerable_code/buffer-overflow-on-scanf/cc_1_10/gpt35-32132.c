//FormAI DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables for user input and file handling
  char fileName[50], inputStr[1000], outputStr[1000];
  int wordCount = 0, charCount = 0;

  // Prompt user to enter file name for input
  printf("Enter input file name (including extension): ");
  scanf("%s", fileName);

  // Open input file for reading
  FILE *inputFile = fopen(fileName, "r");

  // Make sure file exists 
  if (inputFile == NULL) {
    printf("Error: file not found. Please check the file name and try again.");
    return 1;
  }

  // Clear output string 
  memset(outputStr, 0, sizeof(outputStr));

  // Read through input file and count number of words and characters
  while (!feof(inputFile)) {
    fscanf(inputFile, "%s", inputStr);
    strcat(outputStr, inputStr);
    strcat(outputStr, " ");
    wordCount++;
    charCount += strlen(inputStr);
  }

  // Close input file
  fclose(inputFile);

  // Prompt user to enter file name for output
  printf("Enter output file name (including extension): ");
  scanf("%s", fileName);

  // Open output file for writing
  FILE *outputFile = fopen(fileName, "w");

  // Make sure file was successfully created
  if (outputFile == NULL) {
    printf("Error: file creation failed. Please try again.");
    return 1;
  }

  // Write word and character counts to output file
  fprintf(outputFile, "Word count: %d\nCharacter count: %d\n", wordCount, charCount);

  // Close output file
  fclose(outputFile);

  // Print success message to console
  printf("File processed successfully.\n");

  // Exit program 
  return 0;
}