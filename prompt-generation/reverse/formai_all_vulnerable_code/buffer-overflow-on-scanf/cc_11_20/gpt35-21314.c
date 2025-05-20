//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to my fantastic file handling program!\n");
  printf("Prepare to be amazed!\n\n");

  // Ask user for input file name
  char fileName[50];
  printf("Please enter the name of the input file: ");
  scanf("%s", fileName);

  // Open input file
  FILE* inputFile = fopen(fileName, "r");

  // Check if input file exists
  if (inputFile == NULL) {
    printf("\nFile does not exist! Aborting program...\n");
    exit(1);
  }

  // Read input file contents into array
  char inputArray[100][100];
  int row = 0;
  while (fgets(inputArray[row], 100, inputFile)) {
    row++;
  }
  fclose(inputFile);

  // Tell user how many rows were read into array
  printf("\nFile %s has been read successfully.\n", fileName);
  printf("The file contains %d rows.\n\n", row);

  // Ask user for output file name
  char outputName[50];
  printf("Please enter the name of the output file: ");
  scanf("%s", outputName);

  // Create output file
  FILE* outputFile = fopen(outputName, "w");

  // Check if output file was created successfully
  if (outputFile == NULL) {
    printf("\nFailed to create output file! Aborting program...\n");
    exit(1);
  }

  // Write input file contents to output file in reverse order
  for (int i = row - 1; i >= 0; i--) {
    fputs(inputArray[i], outputFile);
  }
  fclose(outputFile);

  // Tell user how many rows were written to output file
  printf("\nFile %s has been written successfully.\n", outputName);
  printf("The file contains %d rows in reversed order.\n\n", row);

  // Surprise user with an extra feature!
  printf("\nBut wait! There's more!\n");
  printf("I can also duplicate any row of the input file!\n");
  printf("Please enter the row number you want to duplicate: ");

  int rowNum;
  scanf("%d", &rowNum);
  if (rowNum > row || rowNum < 1) {
    printf("\nInvalid row number! Aborting program...\n");
    exit(1);
  }
  printf("\n");

  // Ask user for number of times to duplicate the selected row
  int numDuplicates;
  printf("How many times would you like to duplicate this row? ");
  scanf("%d", &numDuplicates);

  // Create new output file with duplicated rows
  char duplicateName[50];
  sprintf(duplicateName, "duplicated_%s", outputName);
  FILE* duplicateFile = fopen(duplicateName, "w");

  // Check if new output file was created successfully
  if (duplicateFile == NULL) {
    printf("\nFailed to create duplicated output file! Aborting program...\n");
    exit(1);
  }

  // Write input file contents to new output file with duplicated rows
  for (int i = 0; i < row; i++) {
    fputs(inputArray[i], duplicateFile);
    if (i == rowNum - 1) {
      for (int j = 0; j < numDuplicates; j++) {
        fputs(inputArray[i], duplicateFile);
      }
    }
  }
  fclose(duplicateFile);

  // Tell user how many rows were written to duplicated output file
  printf("\nFile %s has been written successfully.\n", duplicateName);
  printf("The file contains %d rows with row number %d duplicated %d times.\n", row + numDuplicates, rowNum, numDuplicates);

  printf("\nAmazing, right? Thank you for using my program!\n");

  return 0;
}