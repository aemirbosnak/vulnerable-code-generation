//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty antivirus scanner
void antivirus_scan(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Oops! Couldn't open the file. Maybe it's hiding?\n");
    return;
  }

  // Read the file into memory
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);
  char *data = malloc(size);
  if (data == NULL) {
    printf("Uh-oh! Not enough memory to scan this file. Time for a diet!\n");
    fclose(file);
    return;
  }
  fread(data, 1, size, file);
  fclose(file);

  // Do a cheerful little dance while we scan the file
  printf("\n(\\ /)\n( o.o )\n(> <)  Scanning the file...\n");

  // Check for known virus signatures
  char *virus1 = "VIRUS1";
  char *virus2 = "VIRUS2";
  char *virus3 = "VIRUS3";
  if (strstr(data, virus1) || strstr(data, virus2) || strstr(data, virus3)) {
    printf("Oh no! We found a nasty virus!\n");
    printf("Deleting the file like a superhero!\n");
    remove(filename);
  } else {
    printf("Yay! This file is clean as a whistle!\n");
  }

  // Free the memory we allocated for the file
  free(data);
}

int main() {
  // Get the filename from the user
  char filename[100];
  printf("Hi there! What file would you like me to scan?\n");
  scanf("%s", filename);

  // Scan the file
  antivirus_scan(filename);

  // Say goodbye
  printf("Ta-da! Scanning complete. Your computer is now protected from evildoers.\n");
  return 0;
}