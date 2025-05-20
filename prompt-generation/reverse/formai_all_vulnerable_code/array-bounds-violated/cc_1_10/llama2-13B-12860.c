//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_USERS 10
#define MAX_COMMANDS 5

// Global variables
char *users[MAX_USERS];
char *commands[MAX_COMMANDS];
int user_count = 0;
int command_count = 0;

void add_user(char *name) {
  if (user_count < MAX_USERS) {
    users[user_count] = name;
    user_count++;
  }
}

void add_command(char *command) {
  if (command_count < MAX_COMMANDS) {
    commands[command_count] = command;
    command_count++;
  }
}

int main() {
  // Welcome message
  printf("Welcome to the System Administration Playground!\n");

  // Add users
  add_user("Alice");
  add_user("Bob");
  add_user("Charlie");

  // Add commands
  add_command("ls -l");
  add_command("cd /");
  add_command("mkdir mydir");
  add_command("rm mydir");

  // Loop through users and execute commands
  for (int i = 0; i < user_count; i++) {
    char *user = users[i];
    char *command = commands[command_count];
    printf("User %s running command %s...\n", user, command);

    // Execute the command
    system(command);

    // Increment command counter
    command_count++;
  }

  // Clean up
  for (int i = 0; i < command_count; i++) {
    free(commands[i]);
  }

  return 0;
}