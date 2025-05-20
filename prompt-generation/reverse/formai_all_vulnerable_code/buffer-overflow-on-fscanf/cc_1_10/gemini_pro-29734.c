//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a log entry.
typedef struct log_entry {
  char *timestamp;
  char *message;
} log_entry;

// Define the structure of a log file.
typedef struct log_file {
  FILE *file;
  char *filename;
} log_file;

// Open a log file.
log_file *log_file_open(char *filename) {
  log_file *log = malloc(sizeof(log_file));
  log->filename = filename;
  log->file = fopen(filename, "r");
  return log;
}

// Close a log file.
void log_file_close(log_file *log) {
  fclose(log->file);
  free(log);
}

// Read a log entry from a file.
log_entry *log_entry_read(log_file *log) {
  // Allocate memory for the log entry.
  log_entry *entry = malloc(sizeof(log_entry));

  // Read the timestamp.
  entry->timestamp = malloc(sizeof(char) * 20);
  fscanf(log->file, "%s", entry->timestamp);

  // Read the message.
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, log->file);
  entry->message = line;

  // Return the log entry.
  return entry;
}

// Free a log entry.
void log_entry_free(log_entry *entry) {
  free(entry->timestamp);
  free(entry->message);
  free(entry);
}

// Analyze a log file.
void log_file_analyze(log_file *log) {
  // Read the log entries.
  log_entry *entry;
  while ((entry = log_entry_read(log)) != NULL) {
    // Analyze the log entry.
    printf("Timestamp: %s\n", entry->timestamp);
    printf("Message: %s\n", entry->message);

    // Free the log entry.
    log_entry_free(entry);
  }
}

// Main function.
int main(int argc, char **argv) {
  // Open the log file.
  log_file *log = log_file_open("log.txt");

  // Analyze the log file.
  log_file_analyze(log);

  // Close the log file.
  log_file_close(log);

  return 0;
}