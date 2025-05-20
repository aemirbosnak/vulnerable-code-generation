//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of a log message
#define MAX_LOG_MSG_LEN 256

// Define the types of log messages
#define LOG_TYPE_INFO 1
#define LOG_TYPE_WARNING 2
#define LOG_TYPE_ERROR 3

// Define the log file name
#define LOG_FILE_NAME "log.txt"

// Define the function to write a log message to the log file
void write_log_message(int type, const char *msg) {
  // Get the current time
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  // Open the log file
  FILE *f = fopen(LOG_FILE_NAME, "a");
  if (f == NULL) {
    perror("Error opening log file");
    return;
  }

  // Write the log message to the file
  fprintf(f, "[%04d-%02d-%02d %02d:%02d:%02d] ", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
  switch (type) {
    case LOG_TYPE_INFO:
      fprintf(f, "INFO: %s\n", msg);
      break;
    case LOG_TYPE_WARNING:
      fprintf(f, "WARNING: %s\n", msg);
      break;
    case LOG_TYPE_ERROR:
      fprintf(f, "ERROR: %s\n", msg);
      break;
  }

  // Close the log file
  fclose(f);
}

// Define the main function
int main(int argc, char **argv) {
  // Check if the user has specified a log message
  if (argc < 2) {
    printf("Usage: %s <log message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the log message from the user
  char *log_msg = argv[1];

  // Get the log message type from the user
  int log_type = LOG_TYPE_INFO;
  if (argc >= 3) {
    if (strcmp(argv[2], "-w") == 0) {
      log_type = LOG_TYPE_WARNING;
    } else if (strcmp(argv[2], "-e") == 0) {
      log_type = LOG_TYPE_ERROR;
    }
  }

  // Write the log message to the log file
  write_log_message(log_type, log_msg);

  // Return success
  return EXIT_SUCCESS;
}