//FormAI DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Welcome message
  printf("Welcome to my curious C Log Analysis program!\n\n");

  // Get user input for log file name
  char filename[100];
  printf("Please enter the log file name: ");
  scanf("%s", filename);

  // Open the log file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("\nError: Unable to open file %s\n", filename);
    return 1;
  }

  // Declare variables for log analysis
  int num_lines = 0;
  int num_info = 0;
  int num_warnings = 0;
  int num_errors = 0;
  char line[100];

  // Read each line of the log file
  while (fgets(line, sizeof(line), file) != NULL) {
    // Increment line count
    num_lines++;

    // Check log type and update counts accordingly
    if (strstr(line, "INFO") != NULL) {
      num_info++;
    } else if (strstr(line, "WARN") != NULL) {
      num_warnings++;
    } else if (strstr(line, "ERROR") != NULL) {
      num_errors++;
    }
  }

  // Close the log file
  fclose(file);

  // Output log analysis results
  printf("\n===============================\n");
  printf("Log Analysis Results:\n");
  printf("===============================\n");
  printf("Log file name: %s\n", filename);
  printf("Number of lines: %d\n", num_lines);
  printf("Number of information logs: %d\n", num_info);
  printf("Number of warning logs: %d\n", num_warnings);
  printf("Number of error logs: %d\n", num_errors);

  // Output additional analysis results for fun
  printf("\n===============================\n");
  printf("Additional Analysis Results:\n");
  printf("===============================\n");
  printf("That's a lot of logging! You must really like to keep track of things.\n");
  printf("Did you notice that the log file contains %d unique words?\n", countUniqueWords(filename));
  printf("Based on the logs, I can tell that you're running a web server. Neat!\n");

  // End program
  return 0;
}

// Helper function to count unique words in a file
int countUniqueWords(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return -1;
  }

  // Declare variables
  char line[100];
  char *word;
  char words[100][100];
  int count = 0;

  // Read each line and add non-duplicate words to array
  while (fgets(line, sizeof(line), file) != NULL) {
    // Tokenize the line into words
    word = strtok(line, " \n");
    while (word != NULL) {
      // Check if word already exists in array
      int duplicate = 0;
      for (int i = 0; i < count; i++) {
        if (strcmp(words[i], word) == 0) {
          duplicate = 1;
          break;
        }
      }

      // Add new word to array if it doesn't exist already
      if (!duplicate) {
        strcpy(words[count], word);
        count++;
      }

      // Tokenize next word
      word = strtok(NULL, " \n");
    }
  }

  // Close the file and return count
  fclose(file);
  return count;
}