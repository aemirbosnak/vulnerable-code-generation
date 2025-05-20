//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to log event and write it to file
void log_event(char* event) {
  FILE* fp = fopen("event_log.txt", "a");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  time_t now = time(NULL);
  char* timestamp = ctime(&now);
  timestamp[strlen(timestamp) - 1] = '\0'; // remove newline character

  fprintf(fp, "%s | %s\n", timestamp, event);
  fclose(fp);
}

// Function to display event log in the console
void display_log() {
  FILE* fp = fopen("event_log.txt", "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  char buffer[100];
  while (fgets(buffer, 100, fp) != NULL) {
    printf("%s", buffer);
  }

  fclose(fp);
}

int main() {
  char input[50];

  printf("Welcome to the System Event Logger!\n");

  while (1) {
    printf("\nEnter '1' to log an event or '2' to display event log: ");
    fgets(input, 50, stdin);
    input[strlen(input) - 1] = '\0'; // remove newline character

    if (strcmp(input, "1") == 0) {
      printf("Enter event description: ");
      fgets(input, 50, stdin);
      input[strlen(input) - 1] = '\0'; // remove newline character
      log_event(input);
      printf("Event logged successfully!\n");
    } else if (strcmp(input, "2") == 0) {
      printf("\nEvent Log:\n");
      display_log();
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }

  return 0;
}