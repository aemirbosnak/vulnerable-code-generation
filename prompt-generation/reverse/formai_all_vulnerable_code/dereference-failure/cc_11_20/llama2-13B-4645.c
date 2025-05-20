//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 100000

int main(void) {
  FILE *file = fopen("log.txt", "r");
  char line[MAX_LINE_LENGTH];
  size_t line_count = 0;
  size_t total_size = 0;
  struct tm *time;

  if (file == NULL) {
    perror("Failed to open log file");
    return 1;
  }

  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    line_count++;
    total_size += strlen(line);

    // Calculate the average line length
    float avg_len = (float)total_size / line_count;
    printf("Average line length: %f\n", avg_len);

    // Calculate the total number of unique words
    char *word = strtok(line, " ");
    int word_count = 0;
    while (word != NULL) {
      word_count++;
      word = strtok(NULL, " ");
    }
    printf("Total unique words: %d\n", word_count);

    // Calculate the most frequent word
    int max_frequency = 0;
    char *max_word = NULL;
    for (int i = 0; i < word_count; i++) {
      int frequency = 0;
      char *word = strtok(NULL, " ");
      while (word != NULL) {
        frequency++;
        word = strtok(NULL, " ");
      }
      if (frequency > max_frequency) {
        max_frequency = frequency;
        max_word = word;
      }
    }
    printf("Most frequent word: %s (%d times)\n", max_word, max_frequency);

    // Calculate the total number of lines containing the most frequent word
    int line_count_max_word = 0;
    for (int i = 0; i < line_count; i++) {
      if (strstr(line, max_word) != NULL) {
        line_count_max_word++;
      }
    }
    printf("Lines containing most frequent word: %d (%d%% of total lines)\n",
           line_count_max_word,
           (line_count_max_word * 100) / line_count);

    // Calculate the total number of lines containing any word from a given list
    char *words[5];
    words[0] = "word1";
    words[1] = "word2";
    words[2] = "word3";
    words[3] = "word4";
    words[4] = "word5";
    int line_count_any_word = 0;
    for (int i = 0; i < line_count; i++) {
      for (int j = 0; j < 5; j++) {
        if (strstr(line, words[j]) != NULL) {
          line_count_any_word++;
        }
      }
    }
    printf("Lines containing any word from list: %d (%d%% of total lines)\n",
           line_count_any_word,
           (line_count_any_word * 100) / line_count);
  }

  fclose(file);
  return 0;
}