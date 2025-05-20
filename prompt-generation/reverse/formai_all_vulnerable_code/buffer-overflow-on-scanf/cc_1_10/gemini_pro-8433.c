//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Greeting the user with a happy message
  printf("Hello there, my cheerful file backup buddy!\n");
  printf("Let's get this backup party started with a smile!\n\n");

  // Get the input file and output file names
  char inputFile[100], outputFile[100];
  printf("Input the name of the file you want to backup: ");
  scanf("%s", inputFile);
  printf("Input the name of the backup file: ");
  scanf("%s", outputFile);

  // Open the input file in read mode
  FILE *inputFilePointer = fopen(inputFile, "r");
  if (inputFilePointer == NULL) {
    printf("Oops! We couldn't find the file you're asking for.\n");
    printf("Please make sure the file exists and try again!\n");
    return 1;
  }

  // Open the output file in write mode
  FILE *outputFilePointer = fopen(outputFile, "w");
  if (outputFilePointer == NULL) {
    printf("Whoops! We had a little trouble creating the backup file.\n");
    printf("Please check if you have permission to write in this directory and try again!\n");
    return 1;
  }

  // Copy the contents of the input file to the output file
  char character;
  while ((character = fgetc(inputFilePointer)) != EOF) {
    fputc(character, outputFilePointer);
  }

  // Close both the files
  fclose(inputFilePointer);
  fclose(outputFilePointer);

  // Announce the successful backup with a cheerful message
  printf("\nTa-da! Your file has been backed up successfully.\n");
  printf("Now, you can rest assured that your precious data is safe and sound!\n\n");

  // Say goodbye with a happy note
  printf("Thank you for using our backup system. Stay happy and keep backing up!\n");

  return 0;
}