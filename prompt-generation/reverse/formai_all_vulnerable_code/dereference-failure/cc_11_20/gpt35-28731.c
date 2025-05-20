//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is the introspective C Word Count Tool example program.
// The program counts and displays the frequency of each unique word in a file.

int main(int argc, char *argv[]) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  if (argc < 2) {
    printf("Usage: ./wordcount file.txt\n");
    return 1;
  }

  // Open the file
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Unable to open file\n");
    return 1;
  }

  // Create a hash table to store the word frequencies
  int table_size = 1000;
  int *freq_table = (int*) calloc(table_size, sizeof(int));
  if (freq_table == NULL) {
    printf("Unable to allocate memory\n");
    return 1;
  }

  // Read each line of the file and count the words
  while ((read = getline(&line, &len, fp)) != -1) {
    char *word = strtok(line, " ,.;\n\t");
    while (word != NULL) {
      // Convert the word to lowercase
      for (int i=0; word[i]; i++) {
        word[i] = tolower(word[i]);
      }

      // Compute the hash code for the word
      unsigned long hash = 5381;
      int c;
      while ((c = *word++))
        hash = ((hash << 5) + hash) + c;

      // Update the frequency table
      freq_table[hash % table_size]++;

      word = strtok(NULL, " ,.;\n\t");
    }
  }

  // Print the results
  printf("Word frequencies:\n");
  for (int i=0; i<table_size; i++) {
    if (freq_table[i] > 0) {
      printf("%d: %d\n", i, freq_table[i]);
    }
  }

  // Clean up
  if (line) {
    free(line);
  }
  fclose(fp);
  free(freq_table);

  return 0;
}