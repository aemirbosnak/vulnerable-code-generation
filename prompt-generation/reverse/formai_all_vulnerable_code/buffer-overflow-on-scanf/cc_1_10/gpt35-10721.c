//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Log {
  char date[11];
  char time[9];
  char msg[512];
};

int main() {
  FILE *fp;
  char filename[100];
  char statusmsg[20];
  struct Log arr[1000];
  int count = 0;

  printf("Enter filename: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read each line of log file and store in struct
  char line[550];
  while (fgets(line, sizeof(line), fp)) {
    char date[11], time[9], msg[512];
    sscanf(line, "%s %s %[^\n]", date, time, msg);

    strcpy(arr[count].date, date);
    strcpy(arr[count].time, time);
    strcpy(arr[count].msg, msg);
    count++;
  }

  fclose(fp);

  // Count number of error messages
  int num_errors = 0;
  for (int i = 0; i < count; i++) {
    if (strstr(arr[i].msg, "ERROR")) {
      num_errors++;
    }
  }

  // Determine overall status of logs
  if (num_errors == 0) {
    strcpy(statusmsg, "SUCCESS");
  } else if (num_errors < 5) {
    strcpy(statusmsg, "WARNING");
  } else {
    strcpy(statusmsg, "CRITICAL");
  }

  // Output log results
  printf("\n--- Log Analysis Results ---\n");
  printf("Total logs: %d\n", count);
  printf("Number of errors: %d\n", num_errors);
  printf("Overall status: %s\n", statusmsg);

  return 0;
}