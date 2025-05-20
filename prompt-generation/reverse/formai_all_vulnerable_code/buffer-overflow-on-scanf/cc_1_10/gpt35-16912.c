//FormAI DATASET v1.0 Category: File handling ; Style: Ada Lovelace
// This program demonstrates file handling in C language.
// Created by Ada Lovelace.

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[50], ch;

  // User input for filename
  printf("Enter the filename to create: ");
  scanf("%s", filename);

  // Open file for writing
  fp = fopen(filename, "w");

  // Check if file was successfully opened
  if (fp == NULL) {
    printf("Error creating file.\n");
    exit(1);
  } else {
    printf("File created successfully.\n");
  }

  // User input for file content
  printf("\nEnter the content to write in the file:\n");
  while ((ch = getchar()) != EOF) {
    fputc(ch, fp);
  }

  // Close the file
  fclose(fp);

  // Open file for reading
  fp = fopen(filename, "r");

  // Check if file was successfully opened
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  } else {
    printf("File opened successfully. Here is the content:\n");
  }

  // Output file content
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  // Close the file
  fclose(fp);

  return 0;
}