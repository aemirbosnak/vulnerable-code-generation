//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024
#define MAX_LOG_ENTRIES 100

typedef struct {
  char message[MAX_LOG_SIZE];
  int level;
} log_entry_t;

void print_log(log_entry_t* log_entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s (level %d)\n", log_entries[i].message, log_entries[i].level);
  }
}

int main() {
  log_entry_t log_entries[MAX_LOG_ENTRIES];
  int num_entries = 0;

  while (1) {
    char message[MAX_LOG_SIZE];
    int level;

    printf("Enter a message: ");
    fgets(message, MAX_LOG_SIZE, stdin);

    printf("Enter a level (1-5): ");
    scanf("%d", &level);

    if (level < 1 || level > 5) {
      printf("Invalid level. Must be between 1 and 5.\n");
      continue;
    }

    strcpy(log_entries[num_entries].message, message);
    log_entries[num_entries].level = level;

    num_entries++;

    if (num_entries == MAX_LOG_ENTRIES) {
      break;
    }
  }

  print_log(log_entries, num_entries);

  return 0;
}