//FormAI DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct event {
  char date[20];
  char time[20];
  char description[200];
  int severity;
};

void log_event(char* description, int severity) {
  time_t t = time(NULL);
  struct tm* tm = localtime(&t);
  char date[20], time[20];
  strftime(date, sizeof(date), "%Y-%m-%d", tm);
  strftime(time, sizeof(time), "%H:%M:%S", tm);
  
  struct event new_event;
  strcpy(new_event.date, date);
  strcpy(new_event.time, time);
  strcpy(new_event.description, description);
  new_event.severity = severity;
  
  FILE* log_file = fopen("event_log.txt", "a");
  if (log_file == NULL) {
    printf("Error opening log file!\n");
    exit(1);
  }
  fwrite(&new_event, sizeof(struct event), 1, log_file);
  fclose(log_file);
}

void display_events() {
  FILE* log_file = fopen("event_log.txt", "r");
  if (log_file == NULL) {
    printf("Error opening log file!\n");
    exit(1);
  }
  printf("%-11s%-9s%-15s%s\n", "Date", "Time", "Severity", "Description");
  printf("---------------------------------------------------------\n");
  struct event current_event;
  while (fread(&current_event, sizeof(struct event), 1, log_file)) {
    printf("%-11s%-9s%-15d%s\n", current_event.date, current_event.time, current_event.severity, current_event.description);
  }
  fclose(log_file);
}

int main() {
  char description[200];
  int severity;
  printf("Welcome to the event logger!\n");
  printf("What event would you like to log?\n");
  fgets(description, sizeof(description), stdin);
  printf("What is the severity of the event? (1-10)\n");
  scanf("%d", &severity);
  log_event(description, severity);
  printf("Event logged successfully!\n");
  display_events();
  return 0;
}