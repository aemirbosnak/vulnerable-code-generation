//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to execute a command
int execute(char *command) {
  int status;
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    execlp("/bin/sh", "sh", "-c", command, NULL);
    _exit(EXIT_FAILURE);
  } else if (pid > 0) {
    // Parent process
    waitpid(pid, &status, 0);
    return status;
  } else {
    // Error
    perror("fork");
    return EXIT_FAILURE;
  }
}

// Function to handle the shell loop
void shell_loop() {
  char command[1024];
  while (1) {
    // Print the prompt
    printf(":) ");

    // Read the command
    fgets(command, sizeof(command), stdin);

    // Trim the newline character
    command[strlen(command) - 1] = '\0';

    // Exit the shell if the command is "exit"
    if (strcmp(command, "exit") == 0) {
      break;
    }

    // Execute the command
    execute(command);
  }
}

int main() {
  // Start the shell loop
  shell_loop();

  return EXIT_SUCCESS;
}