//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// A whimsical function to analyze a log file
void analyzeLog(const char *logFileName) {
  // Open the log file
  FILE *logFile = fopen(logFileName, "r");
  if (logFile == NULL) {
    printf("Oops, couldn't open the log file! Maybe it's missing or you don't have permission to read it.\n");
    exit(1);
  }

  // Variables to store our analysis results
  int numLines = 0;
  int numWarnings = 0;
  int numErrors = 0;

  // Read each line of the log file
  char line[1024];
  while (fgets(line, sizeof(line), logFile)) {
    // Count the number of lines in the log file
    numLines++;

    // Check if the line contains a warning or error
    if (strstr(line, "WARNING") != NULL) {
      numWarnings++;
    } else if (strstr(line, "ERROR") != NULL) {
      numErrors++;
    }
  }

  // Close the log file
  fclose(logFile);

  // Print our analysis results
  printf("Log file analysis complete!\n");
  printf("Number of lines: %d\n", numLines);
  printf("Number of warnings: %d\n", numWarnings);
  printf("Number of errors: %d\n", numErrors);

  // Give a cheerful message based on the analysis results
  if (numErrors == 0) {
    printf("Hooray, no errors found! Everything's looking peachy!\n");
  } else if (numWarnings > 0) {
    printf("Oh dear, there are some warnings. Let's take a closer look and see if we can fix them.\n");
  } else {
    printf("Uh-oh, there are some errors. Time to put on our detective hats and figure out what went wrong.\n");
  }
}

int main() {
  // Get the log file name from the user
  char logFileName[1024];
  printf("Enter the name of the log file you want to analyze: ");
  scanf("%s", logFileName);

  // Analyze the log file
  analyzeLog(logFileName);

  return 0;
}