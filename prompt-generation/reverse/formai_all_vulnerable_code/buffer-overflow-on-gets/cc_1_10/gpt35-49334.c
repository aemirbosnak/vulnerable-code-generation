//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *log_file;
  char log_file_name[100];
  int lines_count = 0;
  int status = 0;
  
  printf("Enter the file name to analyze: ");
  gets(log_file_name);  // user input
  
  log_file = fopen(log_file_name, "r");
  
  if (log_file == NULL) {
    printf("\nError: Could not locate the file!\n");
    exit(0);  // exit program if file not found
  }
  
  while (!feof(log_file)) {
    if (fgetc(log_file) == '\n') {
      lines_count++;  // count the number of lines in file
    }
  }
  
  fclose(log_file);  // close the file pointer
  
  log_file = fopen(log_file_name, "r");
  
  if (log_file == NULL) {
    printf("\nError: Could not locate the file!\n");
    exit(0);
  }
  
  printf("\n---------------------------------- Analysis Report ----------------------------------\n\n");
  printf("Total number of log entries: %d\n", lines_count);
  printf("Details:\n\n");
  printf("Time Stamp\t\t\t\t\t\t\t Level\t\tMessage\n");
  printf("------------------------------------------------------------------------------------\n");
  
  char timestamp[30], level[15], message[100];
  
  while (!feof(log_file)) {
    status = fscanf(log_file, "%s %s", timestamp, level);
    
    if (status != 2) {
      break;
    }
    
    fgets(message, 100, log_file);
    printf("%s\t%s\t%s", timestamp, level, message);
  }
  
  printf("\n\n---------------------------------- End of Report ----------------------------------\n");
  
  fclose(log_file);
  
  return 0;  // exit success
}