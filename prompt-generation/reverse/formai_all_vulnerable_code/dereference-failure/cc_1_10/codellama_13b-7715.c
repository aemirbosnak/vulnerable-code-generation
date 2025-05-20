//Code Llama-13B DATASET v1.0 Category: System administration ; Style: rigorous
// system_administration_example.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Declare variables
  char *command;
  char *arguments[10];
  int num_args = 0;
  int i;

  // Parse command-line arguments
  for (i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      // Handle options
      if (argv[i][1] == 'h') {
        // Print help message and exit
        printf("Usage: system_administration_example [-h]\n");
        printf("Options:\n");
        printf("  -h        Print this help message and exit\n");
        return 0;
      } else {
        // Unknown option
        fprintf(stderr, "Unknown option: %s\n", argv[i]);
        return 1;
      }
    } else {
      // Add argument to arguments array
      arguments[num_args++] = argv[i];
    }
  }

  // Check number of arguments
  if (num_args < 1) {
    // Not enough arguments
    fprintf(stderr, "Not enough arguments\n");
    return 1;
  }

  // Get command
  command = arguments[0];

  // Check if command is valid
  if (strcmp(command, "shutdown") != 0 && strcmp(command, "reboot") != 0) {
    // Unknown command
    fprintf(stderr, "Unknown command: %s\n", command);
    return 1;
  }

  // Execute command
  if (strcmp(command, "shutdown") == 0) {
    // Shutdown system
    system("shutdown -h now");
  } else {
    // Reboot system
    system("reboot");
  }

  return 0;
}