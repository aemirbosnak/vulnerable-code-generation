//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[100], c;
  int option, count = 0, ch_count = 0;
  
  printf("Enter the name of the file to create or modify: ");
  scanf("%s", filename);
  
  fp = fopen(filename, "r");
  
  if (fp == NULL) {
    printf("Cannot open %s file.\n", filename);
    exit(0);
  }
  
  printf("Successfully opened %s\n", filename);
  
  printf("Please choose one of the following options:\n");
  printf("1. Count the number of characters in the file.\n");
  printf("2. Count the number of lines in the file.\n");
  scanf("%d", &option);
  
  switch(option) {
    case 1:
      // Counting number of characters in the file
      while ((c = getc(fp)) != EOF) {
        if (c != ' ' && c != '\n')
          ch_count++;
      }
      printf("Total number of characters in the file: %d\n", ch_count);
      break;
      
    case 2:
      // Counting number of lines in the file
      while ((c = getc(fp)) != EOF) {
        if (c == '\n')
          count++;
      }
      printf("Total number of lines in the file: %d\n", count);
      break;
      
    default:
      printf("Invalid option selected.\n");
      break;
  }
  
  fclose(fp);
  
  return 0;
}