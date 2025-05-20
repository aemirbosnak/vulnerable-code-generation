//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 5000

// This program extracts metadata from a C file and displays it in a statistical style.

int main(void) {
  FILE *fp;
  char filename[100];
  char line[MAX_FILE_SIZE];
  int i, count = 0, num_functions = 0, num_lines = 0, num_variables = 0;
  int len, max = 0, min = MAX_FILE_SIZE;
  int total_chars = 0, total_words = 0, total_functions = 0, total_variables = 0;
  float avg_chars_per_line, avg_words_per_line, avg_lines_per_function, avg_variables_per_function;

  printf("Enter C file name (with extension): ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: File not found.\n");
    exit(1);
  }

  while (fgets(line, MAX_FILE_SIZE, fp)) {
    count++;
    num_lines++;
    len = strlen(line);
    total_chars += len;

    if (len > max) {
      max = len;
    }

    if (len < min) {
      min = len;
    }

    char *word = strtok(line, " \t");

    while (word != NULL) {
      total_words++;
      word = strtok(NULL, " \t");
    }

    if (strstr(line, "int ") || strstr(line, "float ") || strstr(line, "double ") || strstr(line, "char ")) {
      num_variables++;
    }

    if (strstr(line, "(") && strstr(line, ")")) {
      num_functions++;
      total_variables += num_variables;
      total_functions++;
      num_variables = 0;
    }
  }

  if (count == 0) {
    printf("Error: File is empty.\n");
    exit(1);
  }

  avg_chars_per_line = (float) total_chars / num_lines;
  avg_words_per_line = (float) total_words / num_lines;
  avg_lines_per_function = (float) num_lines / total_functions;
  avg_variables_per_function = (float) total_variables / total_functions;

  printf("STATISTICS FOR C FILE %s:\n", filename);
  printf("Number of lines: %d\n", num_lines);
  printf("Number of functions: %d\n", total_functions);
  printf("Number of variables: %d\n", total_variables);
  printf("Average characters per line: %.2f\n", avg_chars_per_line);
  printf("Average words per line: %.2f\n", avg_words_per_line);
  printf("Average lines per function: %.2f\n", avg_lines_per_function);
  printf("Average variables per function: %.2f\n", avg_variables_per_function);
  printf("Longest line: %d characters.\n", max);
  printf("Shortest line: %d characters.\n", min);

  fclose(fp);

  return 0;
}