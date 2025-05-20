//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
  char filepath[100];
  char extension[50];
  char author[50];
  char date_created[50];
  char description[200];
  
  printf("Enter filepath: ");
  scanf("%s", filepath);

  // Extract extension
  int i = strlen(filepath) - 1;
  while (i >= 0 && filepath[i] != '.') {
    i--;
  }
  if (i < 0) {
    printf("Error: Invalid filepath\n");
    return 1;
  }
  strcpy(extension, &filepath[i+1]);

  // Extract metadata
  if (strcmp(extension, "c") == 0) {
    strcpy(author, "John Doe");
    strcpy(date_created, "12/01/2022");
    strcpy(description, "This is a C program example");
  } else if (strcmp(extension, "txt") == 0) {
    strcpy(author, "Jane Smith");
    strcpy(date_created, "01/15/2021");
    strcpy(description, "This is a text file");
  } else if (strcmp(extension, "jpg") == 0 || strcmp(extension, "png") == 0) {
    strcpy(author, "Mike Johnson");
    strcpy(date_created, "06/30/2020");
    strcpy(description, "This is an image file");
  } else {
    printf("Error: Unsupported file extension\n");
    return 1;
  }

  // Print metadata
  printf("Extension: %s\n", extension);
  printf("Author: %s\n", author);
  printf("Date created: %s\n", date_created);
  printf("Description: %s\n", description);
  
  return 0;
}