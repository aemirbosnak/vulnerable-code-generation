//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: systematic
// C Log Analysis Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 1024
#define MAX_LOG_LINES 100

// Structure to store log entries
typedef struct {
  char timestamp[20];
  char message[MAX_LOG_LENGTH];
} log_entry;

// Function to parse a log line into a log entry
void parse_log_line(char *line, log_entry *entry) {
  // Split the line into timestamp and message
  char *timestamp = strtok(line, " ");
  char *message = strtok(NULL, "\n");

  // Copy the timestamp and message into the log entry
  strcpy(entry->timestamp, timestamp);
  strcpy(entry->message, message);
}

// Function to sort log entries by timestamp
int compare_log_entries(const void *a, const void *b) {
  log_entry *entry_a = (log_entry *)a;
  log_entry *entry_b = (log_entry *)b;

  return strcmp(entry_a->timestamp, entry_b->timestamp);
}

// Function to print a log entry
void print_log_entry(log_entry *entry) {
  printf("%s: %s\n", entry->timestamp, entry->message);
}

int main(int argc, char *argv[]) {
  // Open the log file
  FILE *log_file = fopen("log.txt", "r");

  // Read the log file line by line
  char line[MAX_LOG_LENGTH];
  log_entry log_entries[MAX_LOG_LINES];
  int num_log_entries = 0;
  while (fgets(line, MAX_LOG_LENGTH, log_file)) {
    // Parse the log line into a log entry
    log_entry entry;
    parse_log_line(line, &entry);

    // Add the log entry to the array
    log_entries[num_log_entries++] = entry;
  }

  // Sort the log entries by timestamp
  qsort(log_entries, num_log_entries, sizeof(log_entry), compare_log_entries);

  // Print the sorted log entries
  for (int i = 0; i < num_log_entries; i++) {
    print_log_entry(&log_entries[i]);
  }

  // Close the log file
  fclose(log_file);

  return 0;
}