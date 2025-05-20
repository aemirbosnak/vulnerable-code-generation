//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7 // Maximum length for hex color code including '#'
#define MAX_COLOR_NAME_LENGTH 50 // Maximum length for color names
#define MAX_COLORS 256 // Limit for colors

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[MAX_COLORS];
int colorCount = 0;

void initializeColors() {
    // A sample of colors to convert from name to hex and vice versa
    strcpy(colors[0].name, "Black");
    strcpy(colors[0].hex, "#000000");
    strcpy(colors[1].name, "White");
    strcpy(colors[1].hex, "#FFFFFF");
    strcpy(colors[2].name, "Red");
    strcpy(colors[2].hex, "#FF0000");
    strcpy(colors[3].name, "Green");
    strcpy(colors[3].hex, "#00FF00");
    strcpy(colors[4].name, "Blue");
    strcpy(colors[4].hex, "#0000FF");
    strcpy(colors[5].name, "Yellow");
    strcpy(colors[5].hex, "#FFFF00");
    strcpy(colors[6].name, "Cyan");
    strcpy(colors[6].hex, "#00FFFF");
    strcpy(colors[7].name, "Magenta");
    strcpy(colors[7].hex, "#FF00FF");
    
    colorCount = 8; // Update the count of colors
}

int findColorByName(const char* name) {
    for (int i = 0; i < colorCount; i++) {
        if (strcasecmp(colors[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Color not found
}

int findColorByHex(const char* hex) {
    for (int i = 0; i < colorCount; i++) {
        if (strcasecmp(colors[i].hex, hex) == 0) {
            return i;
        }
    }
    return -1; // Color not found
}

void convertColor() {
    char input[100];
    printf("Enter a color name or hex code (e.g., #FF5733 or Red): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    if (input[0] == '#') { // Check if input is a hex color
        int index = findColorByHex(input);
        if (index != -1) {
            printf("The color '%s' corresponds to hex code '%s'\n", colors[index].name, colors[index].hex);
        } else {
            printf("Invalid hex code or color not found!\n");
        }
    } else {
        int index = findColorByName(input);
        if (index != -1) {
            printf("The color '%s' has hex code '%s'\n", colors[index].name, colors[index].hex);
        } else {
            printf("Invalid color name or color not found!\n");
        }
    }
}

void listAvailableColors() {
    printf("\nAvailable Colors:\n");
    for (int i = 0; i < colorCount; i++) {
        printf("%s (%s)\n", colors[i].name, colors[i].hex);
    }
}

int main() {
    initializeColors();
    
    while (1) {
        printf("\n--- Color Code Converter ---\n");
        printf("1. Convert color code\n");
        printf("2. List available colors\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                convertColor();
                break;
            case 2:
                listAvailableColors();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}