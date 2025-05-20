//Gemma-7B DATASET v1.0 Category: System event logger ; Style: irregular
#include <stdio.h>
#include <time.h>

int main() {
  time_t timestamp;
  struct tm *tm_ptr;
  char log_buffer[512];
  int log_index = 0;
  char event_name[256];
  char event_details[512];

  while (1) {
    // Get the current timestamp
    timestamp = time(NULL);
    tm_ptr = localtime(&timestamp);

    // Format the timestamp
    sprintf(log_buffer + log_index, "%d/%d/%d %d:%d:%d: ", tm_ptr->tm_year, tm_ptr->tm_mon + 1, tm_ptr->tm_mday, tm_ptr->tm_hour, tm_ptr->tm_min);

    // Get the event name and details
    printf("Enter event name: ");
    scanf("%s", event_name);

    printf("Enter event details: ");
    scanf("%s", event_details);

    // Add the event name and details to the log
    sprintf(log_buffer + log_index, "%s - %s\n", event_name, event_details);

    // Increment the log index
    log_index += strlen(log_buffer) + 1;

    // Check if the log buffer is full
    if (log_index >= 512) {
      // Log full, reset the log index and write the log to a file
      FILE *log_file = fopen("event_log.txt", "w");
      fwrite(log_buffer, log_index, 1, log_file);
      fclose(log_file);
      log_index = 0;
    }

    // Prompt the user to continue or quit
    char continue_yn;
    printf("Continue? (Y/N): ");
    scanf("%c", &continue_yn);

    // Break out of the loop if the user enters N
    if (continue_yn == 'N') {
      break;
    }
  }

  return 0;
}