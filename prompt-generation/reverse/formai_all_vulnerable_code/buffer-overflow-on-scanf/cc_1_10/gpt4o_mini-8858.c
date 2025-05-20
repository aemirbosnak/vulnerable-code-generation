//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#include <unistd.h>
#else
#error "This code is intended to run on Linux."
#endif

// Function to change webpage background color
void change_bg_color(const char *color) {
    printf("Changing background color to: %s\n", color);
    // This will send the color information to the JavaScript running in an HTML page
    printf("document.body.style.backgroundColor = '%s';\n", color);
}

// Function to prompt user for a color and adjust the background accordingly
void prompt_color_change() {
    char color[20];
    
    printf("Enter a color (e.g., red, #ff0000): ");
    fgets(color, sizeof(color), stdin);
    
    // Remove newline character if present
    size_t len = strlen(color);
    if (len > 0 && color[len - 1] == '\n') {
        color[len - 1] = '\0';
    }
    
    // Validate simple color input (in a real plugin, more robust checks would apply)
    if (strlen(color) > 0) {
        change_bg_color(color);
    } else {
        printf("Invalid color input.\n");
    }
}

// Function to display the menu options to the user
void display_menu() {
    printf("=== Browser Plugin Menu ===\n");
    printf("1. Change Background Color\n");
    printf("2. Exit\n");
    printf("==========================\n");
}

// Main interaction loop
int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                prompt_color_change();
                break;
            case 2:
                printf("Exiting the plugin.\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}