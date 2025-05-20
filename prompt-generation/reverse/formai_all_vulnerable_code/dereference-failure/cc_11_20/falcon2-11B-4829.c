//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_LEN 100

int main() {
  // Open the input file
  FILE *fp;
  char file_path[100];
  sprintf(file_path, "%s", "input.txt");
  fp = fopen(file_path, "r");

  // Check if the file was opened successfully
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the text file and store its contents in a buffer
  char buffer[MAX_LEN];
  fgets(buffer, MAX_LEN, fp);

  // Close the input file
  fclose(fp);

  // Initialize variables
  char *sentences[MAX_SENTENCES];
  int sentence_count = 0;
  int total_sentences = 0;
  int max_freq = 0;

  // Iterate through the text and extract sentences
  while (fgets(buffer, MAX_LEN, fp)) {
    // Convert the text to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(buffer); i++) {
      buffer[i] = tolower(buffer[i]);
    }

    // Split the text into sentences using regular expressions
    char *sentence;
    while ((sentence = strtok_r(buffer, " \n\r\t", &buffer))) {
      if (strlen(sentence) > 0) {
        // Increase the sentence count
        sentence_count++;

        // Store the sentence in the sentences array
        sentences[total_sentences++] = sentence;

        // Calculate the frequency of the sentence
        int freq = 0;
        for (int i = 0; i < total_sentences; i++) {
          if (strcmp(sentences[i], sentence) == 0) {
            freq++;
          }
        }

        // Update the maximum frequency
        if (freq > max_freq) {
          max_freq = freq;
        }
      }
    }
  }

  // Close the input file
  fclose(fp);

  // Print the summary
  printf("Summary:\n");
  for (int i = 0; i < sentence_count; i++) {
    printf("%s (%d)\n", sentences[i], max_freq);
  }

  // Free the memory allocated for the sentences array
  for (int i = 0; i < total_sentences; i++) {
    free(sentences[i]);
  }

  // Return 0 to indicate successful execution
  return 0;
}