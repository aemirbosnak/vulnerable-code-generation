//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCRIPT_SIZE 1024

void inject_css(const char *css) {
    char script[MAX_SCRIPT_SIZE];
    
    snprintf(script, sizeof(script),
        "var style = document.createElement('style');"
        "style.type = 'text/css';"
        "style.appendChild(document.createTextNode('%s'));"
        "document.head.appendChild(style);",
        css);
    
    printf("%s\n", script);
}

void display_menu() {
    printf("Minimalist Browser Plugin\n");
    printf("1. Change Background Color\n");
    printf("2. Change Text Color\n");
    printf("3. Apply Custom CSS\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char css[256];

    while(1) {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                inject_css("body { background-color: #f0f0f0; }");
                break;
            case 2:
                inject_css("body { color: #333; }");
                break;
            case 3:
                printf("Enter your CSS code: ");
                // Clear the input buffer
                while (getchar() != '\n');
                fgets(css, sizeof(css), stdin);
                css[strcspn(css, "\n")] = 0; // Remove newline character
                inject_css(css);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}