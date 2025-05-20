//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of log entries
#define MAX_LOG_ENTRIES 100

// Define the maximum length of a log entry
#define MAX_LOG_ENTRY_LENGTH 1024

// Define the structure of a log entry
typedef struct {
  char timestamp[20];
  char level[10];
  char message[MAX_LOG_ENTRY_LENGTH];
} log_entry;

// Define an array of log entries
log_entry log_entries[MAX_LOG_ENTRIES];

// Define the current number of log entries
int num_log_entries = 0;

// Read the log file into the array of log entries
void read_log_file(char *filename) {
  FILE *fp;
  char line[MAX_LOG_ENTRY_LENGTH];

  // Open the log file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening log file");
    exit(1);
  }

  // Read the log file line by line
  while (fgets(line, MAX_LOG_ENTRY_LENGTH, fp) != NULL) {
    // Parse the log entry
    sscanf(line, "%s %s %[^\n]", log_entries[num_log_entries].timestamp, log_entries[num_log_entries].level, log_entries[num_log_entries].message);

    // Increment the number of log entries
    num_log_entries++;
  }

  // Close the log file
  fclose(fp);
}

// Print the log entries to the console
void print_log_entries() {
  for (int i = 0; i < num_log_entries; i++) {
    printf("%s %s %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
  }
}

// Filter the log entries by level
void filter_log_entries(char *level) {
  for (int i = 0; i < num_log_entries; i++) {
    if (strcmp(log_entries[i].level, level) == 0) {
      printf("%s %s %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
    }
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 2) {
    printf("Usage: %s <log_file>\n", argv[0]);
    exit(1);
  }

  // Read the log file
  read_log_file(argv[1]);

  // Print the log entries
  print_log_entries();

  // Filter the log entries by level
  filter_log_entries("ERROR");

  return 0;
}