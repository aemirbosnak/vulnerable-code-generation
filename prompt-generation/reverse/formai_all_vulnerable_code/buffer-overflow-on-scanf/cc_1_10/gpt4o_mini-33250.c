//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB values to hexadecimal
void rgbToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to validate RGB values
int validateRGB(int r, int g, int b) {
    return (r >= 0 && r <= 255) && 
           (g >= 0 && g <= 255) && 
           (b >= 0 && b <= 255);
}

// Function to display a menu to the user
void displayMenu() {
    printf("Color Code Converter\n");
    printf("====================\n");
    printf("1. Convert RGB to Hexadecimal\n");
    printf("2. Exit\n");
}

int main() {
    int choice;
    int r, g, b;
    char hex[8]; // To store the hexadecimal color code including the '#' character

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the Red value (0-255): ");
                if (scanf("%d", &r) != 1) {
                    fprintf(stderr, "Invalid input for Red. Please enter an integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                printf("Enter the Green value (0-255): ");
                if (scanf("%d", &g) != 1) {
                    fprintf(stderr, "Invalid input for Green. Please enter an integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                printf("Enter the Blue value (0-255): ");
                if (scanf("%d", &b) != 1) {
                    fprintf(stderr, "Invalid input for Blue. Please enter an integer.\n");
                    while (getchar() != '\n');
                    continue;
                }

                // Validate the RGB values
                if (validateRGB(r, g, b)) {
                    rgbToHex(r, g, b, hex);
                    printf("Hexadecimal Color Code: %s\n", hex);
                } else {
                    fprintf(stderr, "Invalid RGB values. Please ensure they are in the range 0-255.\n");
                }
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                fprintf(stderr, "Invalid choice. Please select 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}