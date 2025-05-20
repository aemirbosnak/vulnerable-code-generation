//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 1000  // Maximum size of the data array
#define MAX_LINES 1000  // Maximum number of lines in the log file
#define MAX_LENGTH 1000  // Maximum length of a line in the log file

// Define the structure of a log entry
typedef struct {
  time_t timestamp;  // Timestamp of the log entry
  char *message;     // Message of the log entry
} log_entry;

// Function to read the log file and store the log entries in an array
int read_log_file(const char *filename, log_entry *log_entries) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  int line_count = 0;
  char line[MAX_LENGTH];
  while (fgets(line, MAX_LENGTH, file)) {
    // Parse the timestamp and message from the line
    time_t timestamp;
    char message[MAX_LENGTH];
    sscanf(line, "%ld %s", &timestamp, message);

    // Store the log entry in the array
    log_entries[line_count].timestamp = timestamp;
    log_entries[line_count].message = strdup(message);

    line_count++;
  }

  fclose(file);
  return line_count;
}

// Function to print the log entries in the array
void print_log_entries(const log_entry *log_entries, int line_count) {
  for (int i = 0; i < line_count; i++) {
    // Print the timestamp and message of the log entry
    printf("%ld %s\n", log_entries[i].timestamp, log_entries[i].message);
  }
}

// Function to free the memory allocated for the log entries
void free_log_entries(log_entry *log_entries, int line_count) {
  for (int i = 0; i < line_count; i++) {
    free(log_entries[i].message);
  }
  free(log_entries);
}

// Function to main
int main() {
  // Declare an array to store the log entries
  log_entry log_entries[DATA_SIZE];

  // Read the log file and store the log entries in the array
  int line_count = read_log_file("log.txt", log_entries);
  if (line_count == -1) {
    return EXIT_FAILURE;
  }

  // Print the log entries in the array
  print_log_entries(log_entries, line_count);

  // Free the memory allocated for the log entries
  free_log_entries(log_entries, line_count);

  return EXIT_SUCCESS;
}