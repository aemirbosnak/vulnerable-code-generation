//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: energetic
// Unleash the Power of Log Analysis!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some vibrant colors for dynamic log output
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

// Our energetic log analyzer
int main() {
  // Grab the log file name from the user
  char filename[100];
  printf("Enter the log file name: ");
  scanf("%s", filename);

  // Open the log file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf(ANSI_RED "Error: Failed to open the log file.\n" ANSI_RESET);
    return 1;
  }

  // Parse the log file line by line
  char line[1024];
  int line_num = 0;
  while (fgets(line, sizeof(line), fp)) {
    // Increment the line number for context
    line_num++;

    // Extract the timestamp
    char timestamp[30];
    sscanf(line, "%s ", timestamp);

    // Parse the log level
    char level[10];
    sscanf(line + strlen(timestamp), "%s ", level);

    // Categorize the log level
    int level_color;
    if (strcmp(level, "ERROR") == 0) {
      level_color = ANSI_RED;
    } else if (strcmp(level, "WARNING") == 0) {
      level_color = ANSI_YELLOW;
    } else if (strcmp(level, "INFO") == 0) {
      level_color = ANSI_GREEN;
    } else if (strcmp(level, "DEBUG") == 0) {
      level_color = ANSI_BLUE;
    } else {
      level_color = ANSI_MAGENTA;
    }

    // Print the formatted log line
    printf("%s%s%s | %s%s %s%s\n", ANSI_CYAN, line_num, ANSI_RESET, 
           level_color, level, ANSI_RESET, line + strlen(timestamp) + strlen(level));
  }

  // Close the log file
  fclose(fp);

  // Unleash the analysis power!
  printf(ANSI_GREEN "\nLog analysis complete! Unleash the insights!\n" ANSI_RESET);

  return 0;
}