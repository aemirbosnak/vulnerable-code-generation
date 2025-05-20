#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *log_message = NULL;
  int log_message_length = 0;

  // Allocate memory for the log message
  log_message = malloc(1024);

  // Write the log message
  log_message_length = sprintf(log_message, "This is a log message of length %d.", 1024);

  // Read the log message out of bounds
  char *vulnerable_read = log_message + log_message_length;

  // Print the vulnerable read
  printf("%s", vulnerable_read);

  // Free the memory allocated for the log message
  free(log_message);

  return 0;
}
