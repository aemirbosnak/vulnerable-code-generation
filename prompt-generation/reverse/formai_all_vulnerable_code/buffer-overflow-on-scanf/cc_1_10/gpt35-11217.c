//FormAI DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void logEvent(int type, char* message);

int main() {
  int eventType;
  char eventMessage[256];

  printf("Enter event type (0 - Info, 1 - Warning, 2 - Error): ");
  scanf("%d", &eventType);
  
  printf("Enter event message: ");
  scanf(" %[^\n]s", eventMessage);

  logEvent(eventType, eventMessage);

  return 0;
}

void logEvent(int type, char* message) {
  char eventTypeStr[10];
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

  if (type == 0) {
    strcpy(eventTypeStr, "INFO");
  } else if (type == 1) {
    strcpy(eventTypeStr, "WARNING");
  } else if (type == 2) {
    strcpy(eventTypeStr, "ERROR");
  } else {
    printf("Invalid event type: %d\n", type);
    return;
  }

  FILE *fptr;
  char filename[50];
  sprintf(filename, "system_events_%d-%02d-%02d.log", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
  fptr = fopen(filename, "a+");
  if (fptr == NULL) {
    printf("Error opening log file!\n");
    return;
  }

  fprintf(fptr, "[%s] %s: %s\n", timestamp, eventTypeStr, message);

  fclose(fptr);

  printf("Event logged successfully!\n");
}