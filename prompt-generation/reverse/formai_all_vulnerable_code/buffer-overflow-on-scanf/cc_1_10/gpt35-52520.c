//FormAI DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

void printMenu();
void hexToRgb();
void rgbToHex();

int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                hexToRgb();
                break;
            case 2: 
                rgbToHex();
                break;
            case 3: 
                printf("Exiting program...");
                exit(0);
            default: 
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

void printMenu() {
    printf("\n--- Color Code Converter ---\n");
    printf("[1] Convert HEX to RGB\n");
    printf("[2] Convert RGB to HEX\n");
    printf("[3] Exit\n");
    printf("Enter your choice: ");
}

void hexToRgb() {
    char hex[7];
    printf("\nEnter a 6-digit HEX color code (e.g. FFFFFF): ");
    scanf("%s", hex);

    // convert hex to RGB values
    int r = (int)strtol(hex, NULL, 16) >> 16;
    int g = (int)strtol(hex + 2, NULL, 16) >> 8;
    int b = (int)strtol(hex + 4, NULL, 16);

    // print RGB values
    printf("\nRGB value: (%d, %d, %d)\n", r, g, b);
}

void rgbToHex() {
    int r, g, b;
    printf("\nEnter values for Red, Green and Blue between 0 to 255.\n");
    printf("Red: ");
    scanf("%d", &r);
    printf("Green: ");
    scanf("%d", &g);
    printf("Blue: ");
    scanf("%d", &b);
    // check if input is within range
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid input: RGB values should be between 0 to 255.\n");
        return;
    }
    // convert RGB values to hex
    char hex[7];
    sprintf(hex, "%02X%02X%02X", r, g, b);

    // print HEX value
    printf("\nHEX color code: %s\n", hex);
}