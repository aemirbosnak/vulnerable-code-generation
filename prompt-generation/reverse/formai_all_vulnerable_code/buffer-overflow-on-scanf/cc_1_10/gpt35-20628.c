//FormAI DATASET v1.0 Category: Data recovery tool ; Style: high level of detail
/* This is a program for a unique C Data Recovery Tool */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char file_name[50];
  char search_word[20];
  char replace_word[20];
  FILE *fp;
  FILE *temp_fp;
  char temp_file_name[50] = "temp.txt";
  char ch;
  int i, j, k, count;

  printf("Enter the file name to read: ");
  scanf("%s", file_name);

  // Open the file for reading
  fp = fopen(file_name, "r");
  
  // Check if the file exists
  if(fp == NULL) {
    printf("\nError: unable to open file '%s'\n", file_name);
    exit(EXIT_FAILURE);
  }

  // Get the word to be searched for and the word to replace it
  printf("Enter the word to search for: ");
  scanf("%s", search_word);

  printf("Enter the word to replace it with: ");
  scanf("%s", replace_word);

  // Open a temporary file for writing
  temp_fp = fopen(temp_file_name, "w");

  // Check if the file exists
  if(temp_fp == NULL) {
    printf("\nError: unable to create temporary file.\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  // Read the contents of the file and replace the words
  i = 0;
  while((ch = fgetc(fp)) != EOF) {
    if(ch == search_word[i]) {
      i++;
      if(i == strlen(search_word)) {
        // Word found, replace it
        fputs(replace_word, temp_fp);
        i = 0;
        count++;
      }
    }
    else {
      for(j = 0; j < i; j++) {
        // Write the characters that do not match the search word
        fputc(search_word[j], temp_fp);
      }
      i = 0;
      fputc(ch, temp_fp);
    }
  }

  // Copy any remaining characters from the search word
  for(j = 0; j < i; j++) {
    fputc(search_word[j], temp_fp);
  }

  printf("'%s' has been replaced with '%s' %d times.\n", search_word, replace_word, count);

  // Close the input and temporary files
  fclose(fp);
  fclose(temp_fp);

  // Delete the input file
  remove(file_name);

  // Rename the temporary file to the input file
  if(rename(temp_file_name, file_name) != 0) {
    printf("Error: unable to update file.\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}