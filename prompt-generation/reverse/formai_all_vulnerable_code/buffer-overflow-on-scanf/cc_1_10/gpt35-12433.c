//FormAI DATASET v1.0 Category: Browser Plugin ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct browser_plugin {
    char* name;
    char* version;
    char* description;
    char* author;
    bool enabled;
} browser_plugin;

browser_plugin plugins[10];
int num_plugins = 0;

void enable_plugin(int index) {
    plugins[index].enabled = true;
}

void disable_plugin(int index) {
    plugins[index].enabled = false;
}

void list_plugins() {
    printf("List of Browser Plugins:\n");
    for (int i = 0; i < num_plugins; i++) {
        printf("%d. %s v%s (%s) by %s%s\n", i+1, plugins[i].name, plugins[i].version,
               plugins[i].description, plugins[i].author,
               plugins[i].enabled ? " [enabled]" : "");
    }
}

int main() {
    char option[10];
    
    do {
        printf("Enter Option [list/enable/disable/exit]: ");
        scanf("%s", option);
        
        if (strcmp(option, "list") == 0) {
            list_plugins();
        } else if (strcmp(option, "enable") == 0) {
            int index;
            printf("Enter Plugin Number to Enable: ");
            scanf("%d", &index);
            if (index > 0 && index <= num_plugins) {
                enable_plugin(index-1);
                printf("%s Enabled!\n", plugins[index-1].name);
            } else {
                printf("Invalid Plugin Number!\n");
            }
        } else if (strcmp(option, "disable") == 0) {
            int index;
            printf("Enter Plugin Number to Disable: ");
            scanf("%d", &index);
            if (index > 0 && index <= num_plugins) {
                disable_plugin(index-1);
                printf("%s Disabled!\n", plugins[index-1].name);
            } else {
                printf("Invalid Plugin Number!\n");
            }
        } else if (strcmp(option, "exit") != 0) {
            printf("Invalid Option. Please Try Again.\n");
        }
    } while (strcmp(option, "exit") != 0);
    
    printf("Thanks for Using this Browser Plugin Example Program!");
    
    return 0;
}