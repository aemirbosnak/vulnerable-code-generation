//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
  // Check for correct usage
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
    exit(1);
  }

  // Open the input file for reading
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Failed to open %s for reading.\n", argv[1]);
    exit(2);
  }

  // Read the input file into an array of strings
  char *text = (char*)malloc(sizeof(char) * 4096);
  int n = fread(text, sizeof(char), 4096, fp);
  text[n] = '\0';

  // Convert the input text into an array of words
  char *words[100];
  int num_words = 0;
  char *word = strtok(text, " \t\n\r");
  while (word!= NULL) {
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " \t\n\r");
  }

  // Count the frequency of each word
  int freq[100];
  for (int i = 0; i < num_words; i++) {
    freq[i] = 0;
  }
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        freq[i]++;
      }
    }
  }

  // Find the most frequent word
  int max_freq = 0;
  int max_index = -1;
  for (int i = 0; i < num_words; i++) {
    if (freq[i] > max_freq) {
      max_freq = freq[i];
      max_index = i;
    }
  }

  // Print the result
  printf("The most frequent word is: %s\n", words[max_index]);

  // Free allocated memory
  free(text);
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }
  free(words);

  fclose(fp);

  return 0;
}