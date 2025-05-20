//FormAI DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char*, int);
void displayLastEvent(void);

int main(void) {
  char event[50];
  int severity = 0;
  time_t now;

  printf("Welcome to the Event Logger v1.0\n\n");

  while (1) {
    printf("Enter the event name (max 50 characters, 'q' to quit): ");
    fgets(event, sizeof(event), stdin);
    event[strcspn(event, "\n")] = 0;  // remove trailing newline

    if (strcmp(event, "q") == 0) {
      printf("\nExiting Event Logger...\n");
      break;
    }

    printf("Enter the event severity (0-10): ");
    scanf("%d", &severity);
    getchar();  // consume the newline character

    if (severity < 0 || severity > 10) {
      printf("Invalid severity entered. Please enter a value between 0 and 10\n");
      continue;
    }

    logEvent(event, severity);
    displayLastEvent();
  }

  return 0;
}

void logEvent(char* event, int severity) {
  time_t now;
  struct tm* time_info;

  now = time(NULL);
  time_info = localtime(&now);

  FILE* fp = fopen("event_log.txt", "a");  // open file for appending
  if (fp == NULL) {
    printf("Error opening event log file\n");
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%s - %s - Severity: %d\n", asctime(time_info), event, severity);
  fclose(fp);
}

void displayLastEvent() {
  FILE* fp = fopen("event_log.txt", "r");  // open file for reading
  if (fp == NULL) {
    printf("Error opening event log file\n");
    exit(EXIT_FAILURE);
  }

  char last_event[100];
  char current_event[100];
  while (fgets(current_event, sizeof(current_event), fp) != NULL) {
    strcpy(last_event, current_event);
  }

  printf("\nLast Event Logged: %s\n\n", last_event);
  fclose(fp);
}