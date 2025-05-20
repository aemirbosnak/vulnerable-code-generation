//FormAI DATASET v1.0 Category: Browser Plugin ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the plugin structure
struct plugin {
  char name[50];
  char description[100];
  void (*execute)();
};

// Define plugin functions
void plugin1() {
  printf("Plugin 1 executed!\n");
}

void plugin2() {
  printf("Plugin 2 executed!\n");
}

void plugin3() {
  printf("Plugin 3 executed!\n");
}

int main() {
  // Create an array of plugins
  struct plugin plugins[3];

  // Populate the array with plugin information
  strcpy(plugins[0].name, "Plugin 1");
  strcpy(plugins[0].description, "This plugin does something cool!");
  plugins[0].execute = plugin1;

  strcpy(plugins[1].name, "Plugin 2");
  strcpy(plugins[1].description, "This plugin does something even cooler!");
  plugins[1].execute = plugin2;

  strcpy(plugins[2].name, "Plugin 3");
  strcpy(plugins[2].description, "This plugin does something amazing!");
  plugins[2].execute = plugin3;

  // Print out the available plugins
  printf("Available plugins:\n");
  for (int i = 0; i < 3; i++) {
    printf("%d. %s - %s\n", i+1, plugins[i].name, plugins[i].description);
  }

  // Prompt the user to select a plugin
  int choice;
  printf("Select a plugin (1-3): ");
  scanf("%d", &choice);

  // Execute the chosen plugin
  if (choice < 1 || choice > 3) {
    printf("Invalid choice!\n");
    return 1;
  } else {
    plugins[choice-1].execute();
    return 0;
  }
}