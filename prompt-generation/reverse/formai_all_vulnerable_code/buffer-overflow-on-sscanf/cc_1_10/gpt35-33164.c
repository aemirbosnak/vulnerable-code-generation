//FormAI DATASET v1.0 Category: Log analysis ; Style: genious
/* Log Analysis Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum log file size */
#define MAX_FILE_SIZE 1000

/* Define log file structure */
typedef struct {
  char date[20];
  char time[20];
  char level[10];
  char message[500];
} Log;

/* Function to parse log file */
Log* parseLogFile(char* fileName, int* numLogs) {
  /* Open log file */
  FILE* file = fopen(fileName, "r");

  /* Check if file was opened successfully */
  if (file == NULL) {
    printf("Error opening %s\n", fileName);
    exit(1);
  }

  /* Read log file into buffer */
  char buffer[MAX_FILE_SIZE];
  size_t fileSize = fread(buffer, 1, MAX_FILE_SIZE, file);
  fclose(file);

  /* Check if file was read successfully */
  if (fileSize == 0) {
    printf("Error reading %s\n", fileName);
    exit(1);
  }

  /* Split buffer into lines */
  char* line;
  char* rest = buffer;
  int lineCount = 0;
  while ((line = strtok_r(rest, "\n", &rest))) {
    lineCount++;
  }

  /* Allocate memory for log array */
  Log* logs = (Log*) malloc(lineCount * sizeof(Log));

  /* Reopen file and parse log lines */
  file = fopen(fileName, "r");
  lineCount = 0;
  while ((line = strtok_r(rest, "\n", &rest))) {
    sscanf(line, "%s %s %s %[^\n]", logs[lineCount].date, logs[lineCount].time, logs[lineCount].level, logs[lineCount].message);
    lineCount++;
  }

  /* Set number of logs */
  *numLogs = lineCount;

  /* Return log array */
  return logs;
}

/* Function to filter logs by level */
Log* filterLogsByLevel(Log* logs, int numLogs, char* level, int* filteredLogsCount) {
  /* Allocate memory for filtered log array */
  Log* filteredLogs = (Log*) malloc(numLogs * sizeof(Log));

  /* Filter logs by level */
  int filteredCount = 0;
  for (int i = 0; i < numLogs; i++) {
    if (strcmp(logs[i].level, level) == 0) {
      filteredLogs[filteredCount] = logs[i];
      filteredCount++;
    }
  }

  /* Set number of filtered logs */
  *filteredLogsCount = filteredCount;

  /* Return filtered log array */
  return filteredLogs;
}

/* Main function */
int main() {
  /* Parse log file */
  int numLogs;
  Log* logs = parseLogFile("app.log", &numLogs);

  /* Filter logs by level */
  int filteredLogsCount;
  Log* errorLogs = filterLogsByLevel(logs, numLogs, "ERROR", &filteredLogsCount);

  /* Print filtered logs to console */
  printf("Filtered %d ERROR logs:\n", filteredLogsCount);
  for (int i = 0; i < filteredLogsCount; i++) {
    printf("%s %s %s %s\n", errorLogs[i].date, errorLogs[i].time, errorLogs[i].level, errorLogs[i].message);
  }

  /* Free memory */
  free(logs);
  free(errorLogs);

  /* Exit program */
  return 0;
}