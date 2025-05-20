//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of maximum users that can be created.
#define MAX_USERS 100

// Define the length of maximum password string.
#define MAX_PASSWORD_LENGTH 20

// Define the length of maximum command string.
#define MAX_COMMAND_LENGTH 50

// Define the maximum number of commands.
#define MAX_COMMANDS 10

// Define the structure for the User.
struct User {
  char name[50];
  char password[MAX_PASSWORD_LENGTH];
};

// Define the structure for the Command.
struct Command {
  char name[MAX_COMMAND_LENGTH];
  char description[100];
  void (*functionPointer)();
};

struct User users[MAX_USERS]; // Array of Users.
int numOfUsers = 0; // The number of users currently created.
int numOfCommands = 0; // The number of commands currently registered.
struct Command commands[MAX_COMMANDS]; // Array of Commands.

// Define the function that adds a new user.
void addUser() {
  char name[50], password[MAX_PASSWORD_LENGTH];
  
  // Get the name from the user.
  printf("Enter user name: ");
  scanf("%s", name);
  
  // Get the password from the user.
  printf("Enter password: ");
  scanf("%s", password);
  
  // Check if the user already exists.
  for (int i = 0; i < numOfUsers; i++) {
    if (strcmp(users[i].name, name) == 0) {
      printf("User with name '%s' already exists.\n", name);
      return;
    }
  }
  
  strcpy(users[numOfUsers].name, name);
  strcpy(users[numOfUsers].password, password);
  numOfUsers++;
  printf("User '%s' has been created successfully.\n", name);
}

// Define the function that lists all registered users.
void listUsers() {
  if (numOfUsers == 0) {
    printf("No users found.\n");
    return;
  }
  
  printf("Registered users:\n");
  for (int i = 0; i < numOfUsers; i++)
    printf("%s\n", users[i].name);
}

// Define the function that adds a new command.
void addCommand() {
  char name[MAX_COMMAND_LENGTH], description[100];
  
  // Get the name from the user.
  printf("Enter command name: ");
  scanf("%s", name);
  
  // Check if the command already exists.
  for (int i = 0; i < numOfCommands; i++) {
    if (strcmp(commands[i].name, name) == 0) {
      printf("Command with name '%s' already exists.\n", name);
      return;
    }
  }
  
  // Get the description from the user.
  printf("Enter command description: ");
  scanf("%s", description);
  
  // Create the command and register it.
  strcpy(commands[numOfCommands].name, name);
  strcpy(commands[numOfCommands].description, description);
  numOfCommands++;
  printf("Command '%s' has been registered successfully.\n", name);
}

// Define the function that lists all registered commands.
void listCommands() {
  if (numOfCommands == 0) {
    printf("No commands found.\n");
    return;
  }
  
  printf("Registered commands:\n");
  for (int i = 0; i < numOfCommands; i++)
    printf("%s - %s\n", commands[i].name, commands[i].description);
}

// Define the function that shows the help menu.
void help() {
  printf("Commands:\n");
  printf("adduser - Add a new user\n");
  printf("listusers - List all registered users\n");
  printf("addcommand - Add a new command\n");
  printf("listcommands - List all registered commands\n");
  printf("help - Show this help menu\n");
}

// Define the main function.
int main() {
  printf("Welcome to the system administration program.\n");
  printf("Please login to continue.\n");
  
  // Get the user's username and password.
  char username[50], password[MAX_PASSWORD_LENGTH];
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);
  
  // Check the user's credentials.
  int isAuthenticated = 0;
  for (int i = 0; i < numOfUsers; i++) {
    if (strcmp(users[i].name, username) == 0 && strcmp(users[i].password, password) == 0) {
      isAuthenticated = 1;
      break;
    }
  }
  
  if (!isAuthenticated) {
    printf("Invalid username or password. Exiting...\n");
    return 0;
  }
  
  // Define the available commands.
  commands[numOfCommands].functionPointer = addUser;
  strcpy(commands[numOfCommands].name, "adduser");
  strcpy(commands[numOfCommands].description, "Create a new user.");
  numOfCommands++;
  
  commands[numOfCommands].functionPointer = listUsers;
  strcpy(commands[numOfCommands].name, "listusers");
  strcpy(commands[numOfCommands].description, "List all registered users.");
  numOfCommands++;
  
  commands[numOfCommands].functionPointer = addCommand;
  strcpy(commands[numOfCommands].name, "addcommand");
  strcpy(commands[numOfCommands].description, "Register a new command.");
  numOfCommands++;
  
  commands[numOfCommands].functionPointer = listCommands;
  strcpy(commands[numOfCommands].name, "listcommands");
  strcpy(commands[numOfCommands].description, "List all registered commands.");
  numOfCommands++;
  
  commands[numOfCommands].functionPointer = help;
  strcpy(commands[numOfCommands].name, "help");
  strcpy(commands[numOfCommands].description, "Show this help menu.");
  numOfCommands++;
  
  // Start the main loop.
  printf("Type 'help' for a list of available commands.\n");
  while (1) {
    // Get the user input.
    char input[MAX_COMMAND_LENGTH];
    scanf("%s", input);
    
    // Find the matching command.
    int foundCommand = 0;
    for (int i = 0; i < numOfCommands; i++) {
      if (strcmp(input, commands[i].name) == 0) {
        commands[i].functionPointer();
        foundCommand = 1;
        break;
      }
    }
    
    if (!foundCommand)
      printf("Command not found. Type 'help' for a list of available commands.\n");
  }
  
  return 0;
}