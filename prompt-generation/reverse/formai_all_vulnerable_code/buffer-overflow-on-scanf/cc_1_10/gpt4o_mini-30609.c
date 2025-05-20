//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void rgbToHex();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            continue;
        }

        switch (choice) {
            case 1:
                rgbToHex();
                break;
            case 2:
                printf("Exiting the program... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select 1 or 2.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n======================================\n");
    printf("           Color Code Converter       \n");
    printf("======================================\n");
    printf("1. Convert RGB to Hexadecimal\n");
    printf("2. Exit\n");
}

void rgbToHex() {
    int r, g, b;
    char hexColor[8];

    printf("Enter Red (0-255): ");
    scanf("%d", &r);
    if (r < 0 || r > 255) {
        printf("Invalid value for Red! Must be between 0 and 255.\n");
        return;
    }

    printf("Enter Green (0-255): ");
    scanf("%d", &g);
    if (g < 0 || g > 255) {
        printf("Invalid value for Green! Must be between 0 and 255.\n");
        return;
    }

    printf("Enter Blue (0-255): ");
    scanf("%d", &b);
    if (b < 0 || b > 255) {
        printf("Invalid value for Blue! Must be between 0 and 255.\n");
        return;
    }

    // Convert RGB to Hex
    sprintf(hexColor, "#%02X%02X%02X", r, g, b);
    printf("Hexadecimal Color Code: %s\n", hexColor);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}