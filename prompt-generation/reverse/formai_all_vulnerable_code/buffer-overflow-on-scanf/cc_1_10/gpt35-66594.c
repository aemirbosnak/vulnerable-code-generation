//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
// Donald Knuth inspired C Browser Plugin

#include <stdio.h>
#include <stdlib.h>

// Define structure for plugin
typedef struct {
  char* name;
  void (*function)();
} Plugin;

// Function to print plugin name
void printName()
{
  printf("Plugin Name: C Browser Plugin\n");
}

// Function to exit the program
void exitProgram()
{
  printf("Goodbye!\n");
  exit(0);
}

// Define the list of available plugins
Plugin pluginList[] = {
  {"Print Name", printName},
  {"Exit Program", exitProgram},
};

// Main function to display menu and run selected plugin
int main()
{
  // Display menu
  printf("AVAILABLE PLUGINS:\n");
  int numPlugins = sizeof(pluginList) / sizeof(pluginList[0]);
  for (int i = 0; i < numPlugins; i++) {
    printf("%d. %s\n", i+1, pluginList[i].name);
  }
  printf("Enter plugin number (1-%d): ", numPlugins);

  // Get user input and run selected plugin
  int choice;
  scanf("%d", &choice);
  if (choice < 1 || choice > numPlugins) {
    printf("Invalid choice. Exiting...\n");
    exit(1);
  } else {
    printf("Running %s...\n", pluginList[choice-1].name);
    pluginList[choice-1].function();
  }

  return 0;
}