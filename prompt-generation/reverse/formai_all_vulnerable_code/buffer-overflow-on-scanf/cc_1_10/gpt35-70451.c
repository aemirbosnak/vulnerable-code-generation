//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {

  char log_file[100];    // name of the log file

  printf("Enter the name of the log file: ");
  scanf("%s", log_file);

  FILE *log_ptr;     // log file pointer
  char log_line[1000];    // buffer to store each line of the log
  int error_count = 0;    // count of error lines in the log

  log_ptr = fopen(log_file, "r");    // open the log file in read mode

  if (log_ptr == NULL) {
    printf("Error: Unable to open log file!\n");
    return 0;
  }

  while (fgets(log_line, sizeof(log_line), log_ptr)) {
    char log_state[10];    // variable to track the state of each log line
      
    // check for errors in the log line
    if (strstr(log_line, "ERROR") != NULL) {
      error_count++;
      strcpy(log_state, "error");
    } else if (strstr(log_line, "WARNING") != NULL) {
      strcpy(log_state, "warning");
    } else {
      strcpy(log_state, "normal");
    }

    // print the log line with appropriate formatting based on its state
    if (strcmp(log_state, "error") == 0) {
      printf("\033[31m%s\033[0m", log_line);    // if error, print in red
    } else if (strcmp(log_state, "warning") == 0) {
      printf("\033[33m%s\033[0m", log_line);    // if warning, print in yellow
    } else {
      printf("%s", log_line);    // if normal, print as is
    }
  }

  printf("Total number of error lines: %d\n", error_count);

  fclose(log_ptr);    // close the log file

  return 0;
}