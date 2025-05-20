//FormAI DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the mysterious log analyzer!\n");
  printf("Please enter the name of the log file you want to analyze: \n");

  char file_name[100];
  scanf("%s", file_name);

  printf("Analyzing %s...\n", file_name);

  FILE *log_file = fopen(file_name, "r");
  if (log_file == NULL) {
    printf("Error: Could not open file %s\n", file_name);
    exit(EXIT_FAILURE);
  }

  int total_lines = 0;
  int error_count = 0;
  int warning_count = 0;
  char line[1000];
  char last_line[1000];

  fgets(last_line, 1000, log_file); // Read first line before loop

  while (fgets(line, 1000, log_file)) {
    total_lines++;

    if (strstr(line, "Error")) {
      error_count++;

      if (error_count > 10) {
        printf("Error: Too many errors detected! Aborting analysis...\n");
        exit(EXIT_FAILURE);
      }

      if (strcmp(line, last_line) == 0) {
        printf("Warning: Duplicate error detected, check your log file!\n");
        warning_count++;
      }
    }

    memcpy(last_line, line, strlen(line)+1); // Keep copy of last line
  }

  printf("Analysis complete.\n");
  printf("Total lines in log file: %d\n", total_lines);

  if (error_count == 0) {
    printf("No errors found.\n");
  } else {
    printf("Total errors found: %d\n", error_count);
  }

  if (warning_count > 0) {
    printf("Total warnings found: %d\n", warning_count);
  }

  fclose(log_file);
  return 0;
}