//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char filename[100], oldWord[50], newWord[50], tempString[500], fileContents[10000];
  FILE *fp;

  printf("Enter the filename (including extension): ");
  scanf("%s", filename);

  printf("Enter the word to replace: ");
  scanf("%s", oldWord);

  printf("Enter the word to replace it with: ");
  scanf("%s", newWord);

  // Open file for reading
  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: Could not open file\n");
    exit(0);
  }

  // Read file contents into a string
  fgets(fileContents, 10000, fp);

  // Close file
  fclose(fp);

  // Replace all occurrences of oldWord with newWord in the string
  char *pos = strstr(fileContents, oldWord);
  while (pos != NULL) {
    int index = pos - fileContents;
    strncpy(tempString, fileContents, index);
    tempString[index] = '\0';
    strcat(tempString, newWord);
    strcat(tempString, fileContents + index + strlen(oldWord));
    strcpy(fileContents, tempString);
    pos = strstr(fileContents + index + strlen(newWord), oldWord);
  }

  // Open file for writing
  fp = fopen(filename, "w");

  if (fp == NULL) {
    printf("Error: Could not open file\n");
    exit(0);
  }

  // Write modified string back to file
  fputs(fileContents, fp);

  // Close file
  fclose(fp);

  printf("File successfully modified!\n");

  return 0;
}