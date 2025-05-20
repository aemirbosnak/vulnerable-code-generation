//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  char logfile[] = "access.log";
  FILE *fptr;
  char line[200];
  char ip[20];
  char date[20];
  char request[100];
  int status_code;
  
  fptr = fopen(logfile, "r");
  
  printf("***********************************\n");
  printf("** C Log Analysis Example Program **\n");
  printf("***********************************\n\n");
  printf("Analyzing '%s' log file...\n\n", logfile);
  
  if (fptr == NULL) {
    printf("Error: could not open file.\n");
    exit(1);
  }
  
  int lines_processed = 0;
  int successful_requests = 0;
  int failed_requests = 0;
  int unique_ips = 0;
  
  // loop through each line in the log file
  while (fgets(line, sizeof(line), fptr)) {
    // extract IP address, date, request, and status code from each line
    sscanf(line, "%s - - [%[^]]] \"%[^\"]\" %d", ip, date, request, &status_code);
    
    // increment lines processed
    lines_processed++;
    
    // check if request was successful (status code 200-299)
    if (status_code >= 200 && status_code < 300) {
      successful_requests++;
    } else {
      failed_requests++;
    }
    
    // check if this is a new IP address
    if (strstr(line, ip) == line) {
      unique_ips++;
    }
  }
  
  // close file
  fclose(fptr);
  
  // print statistics
  printf("Total lines processed: %d\n", lines_processed);
  printf("Successful requests: %d\n", successful_requests);
  printf("Failed requests: %d\n", failed_requests);
  printf("Unique IP addresses: %d\n", unique_ips);
  
  return 0;
}