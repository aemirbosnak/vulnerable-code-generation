//FormAI DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color code structure
typedef struct {
    int red;
    int green;
    int blue;
} Color;

// Function declarations
void display_menu();
void convert_to_hex();
void convert_to_rgb();

// Main function
int main() {
    int choice;
    printf("Welcome to the Color Code Converter!\n");

    do {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                convert_to_hex();
                break;
            case 2:
                convert_to_rgb();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

// Display menu function
void display_menu() {
    printf("Please choose an option:\n");
    printf("1. Convert RGB values to Hexadecimal code\n");
    printf("2. Convert Hexadecimal code to RGB values\n");
    printf("3. Exit program\n");
}

// Convert RGB to Hex function
void convert_to_hex() {
    Color color;

    printf("Enter the RGB values (each separated by a space): ");
    scanf("%d %d %d", &color.red, &color.green, &color.blue);

    printf("The Hex code is: #%02x%02x%02x\n", color.red, color.green, color.blue);
}

// Convert Hex to RGB function
void convert_to_rgb() {
    char hex_code[7];
    Color color;

    printf("Enter the Hexadecimal code (without the #): ");
    scanf("%s", hex_code);

    if(strlen(hex_code) != 6) {
        printf("Invalid Hex code, please try again.\n");
        return;
    }

    // Convert Hex code to RGB values
    sscanf(hex_code, "%02x%02x%02x", &color.red, &color.green, &color.blue);

    printf("The RGB values are: %d %d %d\n", color.red, color.green, color.blue);
}