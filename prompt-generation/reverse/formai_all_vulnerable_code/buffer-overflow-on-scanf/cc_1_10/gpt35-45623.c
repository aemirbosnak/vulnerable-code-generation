//FormAI DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

/* This program demonstrates the use of File Handling in C. It reads a file, modifies its content and writes it back to the same file. */

int main() {
  FILE *file;
  char filename[100], content[100], c;
  int count = 0, index = 0;
  
  // Get the filename from the user
  printf("Enter filename: ");
  scanf("%s", filename);
  
  // Open the file in read mode
  file = fopen(filename, "r+");
  
  if (file == NULL) {
    printf("File not found!\n");
    exit(1);
  }
  
  // Read the content of the file
  while ((c = fgetc(file)) != EOF) {
    content[index++] = c;
    
    if (c == ' ') {
      count++;
    }
  }
  
  // Modify the content of the file
  for (int i = 0; i < index; i++) {
    if (content[i] == 'a') {
      content[i] = 'A';
    }
  }
  
  // Write the modified content back to the file
  rewind(file);
  
  for (int i = 0; i < index; i++) {
    fputc(content[i], file);
  }
  
  printf("Number of spaces in the file: %d\n", count);
  
  // Close the file
  fclose(file);
  
  return 0;
}