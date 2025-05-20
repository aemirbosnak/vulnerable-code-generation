//FormAI DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
// Donald Knuth Style Log Analysis Example
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 100

// Struct to hold log entry information
typedef struct {
  char timestamp[20];
  char level[10];
  char message[MAX_LOG_ENTRY_LENGTH];
} log_entry;

// Function to parse a log line into its components
void parse_log_line(char *log_line, log_entry *entry) {
  char *token = strtok(log_line, " ");
  strcpy(entry->timestamp, token);
  token = strtok(NULL, " ");
  strcpy(entry->level, token);
  token = strtok(NULL, "\n");
  strcpy(entry->message, token);
}

int main() {
  char log_file_name[50];
  printf("Enter the name of the log file: ");
  scanf("%s", log_file_name);

  // Open the log file
  FILE *log_file = fopen(log_file_name, "r");

  if (log_file == NULL) {
    printf("Error opening log file!\n");
    exit(1);
  }

  // Read in the log entries
  log_entry entries[MAX_LOG_ENTRIES];
  int num_entries = 0;
  char line[MAX_LOG_ENTRY_LENGTH];
  
  while(fgets(line, sizeof(line), log_file) != NULL) {
    parse_log_line(line, &entries[num_entries]);
    num_entries++;
  }
  
  fclose(log_file);

  // Display the log entries
  printf("LOG ENTRIES:\n");
  
  for (int i = 0; i < num_entries; i++) {
      printf("Timestamp: %s | Level: %s | Message: %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
  }

  return 0;
}