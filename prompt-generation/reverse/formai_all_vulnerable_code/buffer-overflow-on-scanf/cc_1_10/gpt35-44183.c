//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct plugin { // Define a plugin struct
  char name[20];
  int version;
};

int add_plugin(struct plugin **plugins, int *count) { // Function to add plugin to array
  struct plugin *temp;
  temp = (struct plugin *)realloc(*plugins, sizeof(struct plugin) * (*count + 1)); // Allocate memory for new plugin and copy old plugins
  if (temp == NULL) {
    printf("Failed to allocate memory\n");
    return 0;
  }
  *plugins = temp;

  printf("Enter plugin name: ");
  scanf("%s", (*plugins)[*count].name);
  printf("Enter plugin version: ");
  scanf("%d", &(*plugins)[*count].version);
  *count += 1;
  return 1;
}

void list_plugins(struct plugin *plugins, int count) { // Function to print list of plugins
  int i;
  for (i = 0; i < count; i++) {
    printf("%d. %s (v%d)\n", i + 1, plugins[i].name, plugins[i].version);
  }
}

void delete_plugin(struct plugin **plugins, int *count, int index) { // Function to delete a plugin from array
  int i;
  for (i = index; i < *count - 1; i++) { // Shift remaining plugins left to replace deleted plugin
    (*plugins)[i] = (*plugins)[i + 1];
  }
  *count -= 1;
  *plugins = (struct plugin *)realloc(*plugins, sizeof(struct plugin) * (*count)); // Reallocate memory for smaller array
}

int main() {
  struct plugin *plugins = NULL; // Initialize plugin array to null pointer
  int count = 0;
  int choice, index;

  while (1) { // Loop until user chooses to exit
    printf("\nPlease choose an option:\n");
    printf("1. Add a plugin\n");
    printf("2. List plugins\n");
    printf("3. Delete a plugin\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_plugin(&plugins, &count);
        printf("Plugin added successfully\n");
        break;
      case 2:
        if (count == 0) {
          printf("No plugins found\n");
        } else {
          list_plugins(plugins, count);
        }
        break;
      case 3:
        if (count == 0) {
          printf("No plugins found\n");
        } else {
          printf("Enter index of plugin to delete: ");
          scanf("%d", &index);
          if (index < 1 || index > count) {
            printf("Invalid index\n");
          } else {
            delete_plugin(&plugins, &count, index - 1);
            printf("Plugin deleted successfully\n");
          }
        }
        break;
      case 4:
        printf("Exiting program\n");
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }
}