//FormAI DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function for converting hexadecimal code to RGB code
void hex_to_rgb(char hex_color[], int *red, int *green, int *blue) {
    int hex_number;
    sscanf(hex_color, "%x", &hex_number);
    *red = (hex_number >> 16) & 0xFF;
    *green = (hex_number >> 8) & 0xFF;
    *blue = hex_number & 0xFF;
}

// Function for converting RGB code to hexadecimal code
void rgb_to_hex(int red, int green, int blue, char hex_color[]) {
    sprintf(hex_color, "#%02x%02x%02x", red, green, blue);
}

int main() {
    int red, green, blue;
    char hex_color[7];
    char choice;

    printf("Welcome to the C Color Code Converter\n");
    printf("What would you like to do?\n");
    printf("[1] Convert from hex to RGB\n");
    printf("[2] Convert from RGB to hex\n");
    printf("[Q] Quit the program\n");
    do {
        printf("Choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter hex color code: ");
                scanf(" %s", hex_color);
                hex_to_rgb(hex_color, &red, &green, &blue);
                printf("RGB code: (%d, %d, %d)\n", red, green, blue);
                break;
            case '2':
                printf("Enter red value (0-255): ");
                scanf("%d", &red);
                printf("Enter green value (0-255): ");
                scanf("%d", &green);
                printf("Enter blue value (0-255): ");
                scanf("%d", &blue);
                rgb_to_hex(red, green, blue, hex_color);
                printf("Hex code: %s\n", hex_color);
                break;
            case 'Q':
            case 'q':
                printf("Quitting the program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}