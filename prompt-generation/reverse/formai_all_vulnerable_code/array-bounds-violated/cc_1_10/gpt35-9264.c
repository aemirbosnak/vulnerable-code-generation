//FormAI DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(char fName[]) {
  FILE *fp;
  char input[100];
  int num;

  fp = fopen(fName, "w");  // Open the file for writing

  if(fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  printf("Enter an integer: ");
  scanf("%d", &num);
  fprintf(fp, "%d\n", num);  // Write the integer to the file
  
  printf("Enter a string (max 100 characters): ");
  getchar();  // Clear the input buffer
  fgets(input, 100, stdin);
  input[strlen(input) - 1] = '\0';  // Remove the newline character
  fputs(input, fp);  // Write the string to the file
  
  fclose(fp);  // Close the file
}

void readFromFile(char fName[]) {
  FILE *fp;
  char input[100];
  int num;

  fp = fopen(fName, "r");  // Open the file for reading

  if(fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  fscanf(fp, "%d", &num);  // Read the integer from the file
  fgets(input, 100, fp);  // Read the rest of the line
  printf("Integer: %d\n", num);
  
  fgets(input, 100, fp);  // Read the string from the file
  printf("String: %s\n", input);
  
  fclose(fp);  // Close the file
}

int main() {
  char fName[50] = "example.txt";

  writeToFile(fName);  // Call the function to write to the file
  
  printf("\nFile contents:\n");
  readFromFile(fName);  // Call the function to read from the file

  return 0;
}