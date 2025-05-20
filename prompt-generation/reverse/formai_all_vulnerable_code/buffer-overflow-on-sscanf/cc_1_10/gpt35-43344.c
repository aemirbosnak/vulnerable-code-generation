//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void greet() {
  printf("Hello! How can I assist you today?\n");
}

void display_options() {
  printf("Enter one of the following commands:\n");
  printf("- open <filename>: to open an Ebook\n");
  printf("- read: to start reading the Ebook\n");
  printf("- close: to close the Ebook\n");
  printf("- help: to show available commands\n");
  printf("- exit: to exit the program\n");
}

void open_ebook(char *filename) {
  printf("Opening Ebook: %s\n", filename);
  // Load Ebook data from file into memory
}

void read_ebook() {
  // Display Ebook content
  printf("Reading Ebook...\n");
}

void close_ebook() {
  // Unload Ebook data from memory
  printf("Closing Ebook...\n");
}

void help() {
  display_options();
}

int main() {
  char command[MAX_LENGTH];
  char arg[MAX_LENGTH];

  greet();

  while (1) {
    printf(">>> ");
    fgets(command, MAX_LENGTH, stdin);
    command[strcspn(command, "\r\n")] = '\0'; // Remove trailing newline character

    if (sscanf(command, "%s %s", arg, arg) == 1) {
      strcpy(arg, "");
    }

    if (strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      break;
    } else if (strcmp(command, "help") == 0) {
      help();
    } else if (strcmp(command, "open") == 0) {
      printf("Enter Ebook filename: ");
      fgets(arg, MAX_LENGTH, stdin);
      arg[strcspn(arg, "\r\n")] = '\0'; // Remove trailing newline character
      open_ebook(arg);
    } else if (strcmp(command, "read") == 0) {
      read_ebook();
    } else if (strcmp(command, "close") == 0) {
      close_ebook();
    } else {
      printf("Invalid command. Type 'help' for available commands.\n");
    }
  }

  return 0;
}