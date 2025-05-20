//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's create a dynamic array to store our log messages!
char** logMessages;
int logSize = 0;
int logCapacity = 10;

// Here comes the star of the show: our log analysis function!
void analyzeLog(char* logFile) {
  // First, let's open the log file and read its contents into our array.
  FILE* file = fopen(logFile, "r");
  if (file == NULL) {
    perror("Error opening log file");
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), file) != NULL) {
    // Hooray! We've got a new log message. Let's add it to our array.
    if (logSize == logCapacity) {
      // Oops, we're running out of space! Let's expand our array.
      logCapacity *= 2;
      logMessages = realloc(logMessages, logCapacity * sizeof(char*));
    }
    logMessages[logSize++] = strdup(line);
  }
  fclose(file);

  // Now, let's have some fun analyzing the logs!

  // How many times did "error" occur?
  int errorCount = 0;
  for (int i = 0; i < logSize; i++) {
    if (strstr(logMessages[i], "error") != NULL) {
      errorCount++;
    }
  }
  printf("Number of errors: %d\n", errorCount);

  // What are the top 3 most frequent log messages?
  char* frequentMessages[3];
  int frequentCounts[3];
  memset(frequentMessages, 0, sizeof(frequentMessages));
  memset(frequentCounts, 0, sizeof(frequentCounts));
  for (int i = 0; i < logSize; i++) {
    int found = 0;
    for (int j = 0; j < 3; j++) {
      if (strcmp(logMessages[i], frequentMessages[j]) == 0) {
        frequentCounts[j]++;
        found = 1;
        break;
      }
    }
    if (!found) {
      // We haven't encountered this message before. Let's add it to our list.
      int minIndex = 0;
      for (int j = 1; j < 3; j++) {
        if (frequentCounts[j] < frequentCounts[minIndex]) {
          minIndex = j;
        }
      }
      frequentMessages[minIndex] = logMessages[i];
      frequentCounts[minIndex] = 1;
    }
  }
  printf("Top 3 most frequent log messages:\n");
  for (int i = 0; i < 3; i++) {
    printf("%d. %s (%d occurrences)\n", i + 1, frequentMessages[i], frequentCounts[i]);
  }

  // Free up the memory we allocated for the log messages.
  for (int i = 0; i < logSize; i++) {
    free(logMessages[i]);
  }
  free(logMessages);
}

int main() {
  // Prepare to be amazed by our log analysis skills!
  printf("Welcome to the Log Analyzer Extraordinaire!\n\n");

  // Let's get the log file from the user.
  char logFile[256];
  printf("Enter the path to the log file: ");
  scanf("%s", logFile);

  // Time to analyze the log file and uncover its secrets!
  analyzeLog(logFile);

  printf("\nTa-da! Your log has been analyzed. Happy debugging!\n");
  return 0;
}