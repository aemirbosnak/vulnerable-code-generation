//FormAI DATASET v1.0 Category: Browser Plugin ; Style: complete
#include <stdio.h>

// Define the plugin structure
struct plugin {
    char* name;
    char* description;
    void (*action)(char*);
};

// Define the simple print action
void print_action(char* message) {
    printf("%s\n", message);
}

// Define the action for opening a new tab
void new_tab_action(char* url) {
    printf("Opening new tab with url: %s\n", url);
}

int main() {
    // Create plugin instances
    struct plugin plugins[2];
    plugins[0].name = "Print";
    plugins[0].description = "Prints the given message";
    plugins[0].action = print_action;

    plugins[1].name = "New Tab";
    plugins[1].description = "Opens a new tab with the given url";
    plugins[1].action = new_tab_action;

    // List available plugins
    printf("Available Plugins:\n");
    for(int i=0; i<2; i++) {
        printf("%d. %s: %s\n", i+1, plugins[i].name, plugins[i].description);
    }

    // Let user choose a plugin
    int choice;
    printf("\nEnter the number of the plugin you want to use: ");
    scanf("%d", &choice);

    // Perform the chosen plugin action
    if(choice >= 1 && choice <= 2) {
        char input[256];
        printf("\nEnter the required input: ");
        scanf("%s", input);

        plugins[choice-1].action(input);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}