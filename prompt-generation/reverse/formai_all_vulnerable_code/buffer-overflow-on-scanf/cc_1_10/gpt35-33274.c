//FormAI DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 500

void analyze_log(char* filename) {
  FILE *fp;
  char line[LINE_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int info_count = 0;
  int log_count = 0;
  int total_count = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file: %s\n", filename);
    return;
  }

  while (fgets(line, LINE_LENGTH, fp)) {
    if (strstr(line, "ERROR") != NULL) {
      error_count++;
    } else if (strstr(line, "WARNING") != NULL) {
      warning_count++;
    } else if (strstr(line, "INFO") != NULL) {
      info_count++;
    } else if (strstr(line, "LOG") != NULL) {
      log_count++;
    }
    total_count++;
  }

  printf("Log file analysis for %s\n\n", filename);
  printf("Total lines: %d\n\n", total_count);
  printf("Error lines: %d\n", error_count);
  printf("Warning lines: %d\n", warning_count);
  printf("Info lines: %d\n", info_count);
  printf("Log lines: %d\n", log_count);

  fclose(fp);
}

int main() {
  char filename[100];
  printf("Enter the filename of log file to be analyzed: ");
  scanf("%s", filename);

  analyze_log(filename);

  return 0;
}