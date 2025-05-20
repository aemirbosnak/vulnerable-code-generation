//Falcon-180B DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE_NAME "event_log.txt"

typedef struct {
  time_t timestamp;
  char event[100];
} LogEntry;

FILE *logFile;

void initLogFile() {
  logFile = fopen(LOG_FILE_NAME, "a");
  if (logFile == NULL) {
    printf("Error: Cannot open log file.\n");
    exit(1);
  }
}

void writeLogEntry(LogEntry entry) {
  fprintf(logFile, "%s - %s\n", ctime(&entry.timestamp), entry.event);
}

void closeLogFile() {
  fclose(logFile);
}

int main() {
  initLogFile();

  LogEntry entries[MAX_LOG_ENTRIES];
  int numEntries = 0;

  while (1) {
    char input[100];
    printf("Enter an event to log (or type 'exit' to quit): ");
    scanf("%s", input);

    if (strcmp(input, "exit") == 0) {
      break;
    }

    if (numEntries >= MAX_LOG_ENTRIES) {
      printf("Error: Log is full.\n");
      continue;
    }

    strcpy(entries[numEntries].event, input);
    entries[numEntries].timestamp = time(NULL);
    writeLogEntry(entries[numEntries]);
    numEntries++;
  }

  closeLogFile();
  return 0;
}