//FormAI DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>

int main(void) {
  printf("Welcome to the Log Analysis Program in Medieval Style!\n\n");
  
  // Gathering user input
  printf("Please enter the name of the log file you would like to analyze: ");
  char filename[50];
  scanf("%s", filename);
  printf("\nGather your quills and parchment, for we shall begin!\n\n");
  
  // Reading log file
  FILE *logfile;
  logfile = fopen(filename, "r");
  if (logfile == NULL) {
    printf("The log file does not exist or cannot be accessed. Please try again with a valid file.\n");
    return 1;
  } else {
    printf("The log file has been accessed successfully.\n\n");
  }
  
  // Initializing variables for analysis
  int num_lines = 0;
  int num_successful_logins = 0;
  int num_failed_logins = 0;
  char buffer[1000];
  fgets(buffer, 1000, logfile); // Skipping header line
  
  // Analyzing log file
  while(fgets(buffer, 1000, logfile)) {
    num_lines++;
    char status[20];
    sscanf(buffer, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s", status);
    if (strcmp(status, "success") == 0) {
      num_successful_logins++;
    } else if (strcmp(status, "failure") == 0) {
      num_failed_logins++;
    }
  }

  // Displaying analysis results
  printf("Through my eye of wisdom, I have analyzed the log file called %s.\n\n", filename);
  printf("Number of lines in the file: %d\n", num_lines);
  printf("Number of successful logins: %d\n", num_successful_logins);
  printf("Number of failed logins: %d\n", num_failed_logins);

  // Closing log file
  fclose(logfile);
  
  printf("\nAnd so my task is complete. Until next time, farewell traveler!\n");

  return 0;
}