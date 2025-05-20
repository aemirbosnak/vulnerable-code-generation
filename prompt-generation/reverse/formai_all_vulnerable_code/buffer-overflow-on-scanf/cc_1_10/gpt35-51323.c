//FormAI DATASET v1.0 Category: Browser Plugin ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the URL
#define MAX_URL_LENGTH 2048

// Define the maximum length of the browser plugin name
#define MAX_PLUGIN_NAME_LENGTH 64

// Define the maximum number of plugins that can be installed
#define MAX_PLUGINS 10

// Define the structure for the browser plugin
typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
    char url[MAX_URL_LENGTH];
} Plugin;

// Define the function prototypes
void print_menu();
void add_plugin(Plugin plugins[], int *num_plugins);
void remove_plugin(Plugin plugins[], int *num_plugins);
void list_plugins(Plugin plugins[], int num_plugins);
int find_plugin_index(Plugin plugins[], int num_plugins, char *name);

int main() {
    Plugin plugins[MAX_PLUGINS];
    int num_plugins = 0;
    char choice;

    // Display the main menu
    print_menu();

    // Keep prompting the user for input until they choose to quit
    while (choice != 'q') {
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_plugin(plugins, &num_plugins);
                break;
            case 'r':
                remove_plugin(plugins, &num_plugins);
                break;
            case 'l':
                list_plugins(plugins, num_plugins);
                break;
            case 'q':
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    }
 
    return 0;
}

// Function to print the main menu
void print_menu() {
    printf("*** Browser Plugin Manager ***\n");
    printf("Select an option:\n");
    printf("[a] Add a new plugin\n");
    printf("[r] Remove an existing plugin\n");
    printf("[l] List all plugins\n");
    printf("[q] Quit the program\n\n");
}

// Function to add a new plugin to the list
void add_plugin(Plugin plugins[], int *num_plugins) {
    char name[MAX_PLUGIN_NAME_LENGTH];
    char url[MAX_URL_LENGTH];

    // Check if the maximum number of plugins has been reached
    if (*num_plugins >= MAX_PLUGINS) {
        printf("Cannot add any more plugins. Maximum limit reached.");
        return;
    }

    // Prompt the user for the plugin details
    printf("Enter the name of the plugin: ");
    scanf("%s", name);

    // Check if the plugin name already exists
    if (find_plugin_index(plugins, *num_plugins, name) != -1) {
        printf("Plugin with the same name already exists. Cannot add another one.");
        return;
    }

    printf("Enter the URL of the plugin: ");
    scanf("%s", url);

    // Add the new plugin to the list
    strcpy(plugins[*num_plugins].name, name);
    strcpy(plugins[*num_plugins].url, url);
    (*num_plugins)++;

    printf("Plugin \"%s\" has been added successfully.\n", name);
}

// Function to remove an existing plugin from the list
void remove_plugin(Plugin plugins[], int *num_plugins) {
    char name[MAX_PLUGIN_NAME_LENGTH];
    int index;

    // Prompt the user for the plugin name
    printf("Enter the name of the plugin to be removed: ");
    scanf("%s", name);

    // Find the index of the plugin in the list
    index = find_plugin_index(plugins, *num_plugins, name);

    if (index == -1) {
        printf("Plugin not found.\n");
        return;
    }

    // Shift all the elements after the index by one position to the left
    for (int i = index; i < (*num_plugins) - 1; i++) {
        plugins[i] = plugins[i+1];
    }

    // Decrement the number of plugins
    (*num_plugins)--;

    printf("Plugin \"%s\" has been removed successfully.\n", name);
}

// Function to list all the plugins in the list
void list_plugins(Plugin plugins[], int num_plugins) {
    printf("List of all installed plugins:\n");

    // Print the details of each plugin
    for (int i = 0; i < num_plugins; i++) {
        printf("[%d] %s - %s\n", i+1, plugins[i].name, plugins[i].url);
    }
}

// Function to find the index of a plugin in the list
int find_plugin_index(Plugin plugins[], int num_plugins, char *name) {
    for (int i = 0; i < num_plugins; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}