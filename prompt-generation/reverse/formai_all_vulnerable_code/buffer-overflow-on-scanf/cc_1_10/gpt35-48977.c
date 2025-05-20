//FormAI DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Define variables
  int total_requests = 0, successful_requests = 0, failed_requests = 0;
  double total_size = 0.0;
  char filename[100];
  FILE *file;

  // Ask user for filename
  printf("Please enter the name of the log file: ");
  scanf("%s", filename);

  // Open the log file
  file = fopen(filename, "r");

  // Check for errors in opening the file
  if (!file) {
    printf("Error: could not open %s\n", filename);
    exit(1);
  }

  // Read the log file line by line
  char line[200];
  while (fgets(line, 200, file)) {
    // Find the HTTP status code in the line
    char *status = strstr(line, "\" 2");

    // If the status code is found
    if (status) {
      // Increment the successful requests counter
      successful_requests++;

      // Find the size of the response in the line
      char *size_str = strtok(line, "\"");
      size_str = strtok(NULL, "\"");
      size_str = strtok(NULL, "\"");
      size_str = strtok(NULL, " ");
      total_size += atof(size_str);
    } else {
      // Increment the failed requests counter
      failed_requests++;
    }

    // Increment the total requests counter
    total_requests++;
  }

  // Close the file
  fclose(file);

  // Calculate percentage of successful requests
  double success_rate = (double) successful_requests / (double) total_requests * 100.0;

  // Print results
  printf("Total requests: %d\n", total_requests);
  printf("Successful requests: %d\n", successful_requests);
  printf("Failed requests: %d\n", failed_requests);
  printf("Average response size: %.2f bytes\n", total_size / (double) successful_requests);
  printf("Success rate: %.2f%%\n", success_rate);

  return 0;
}