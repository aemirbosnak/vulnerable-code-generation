//FormAI DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

void print_menu();
void color_conversion_menu();
void hex_to_rgb();
void rgb_to_hex();

int main() {
    int option;
    do {
        print_menu();
        scanf("%d", &option);
        switch(option) {
            case 1:
                color_conversion_menu();
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while(option != 2);
    return 0;
}

void print_menu() {
    printf("---- COLOR CODE CONVERTER ----\n");
    printf("1. Color Conversion\n");
    printf("2. Exit\n");
    printf("Enter your option: ");
}

void color_conversion_menu() {
    int option;
    do {
        printf("---- COLOR CONVERSION MENU ----\n");
        printf("1. Convert HEX to RGB\n");
        printf("2. Convert RGB to HEX\n");
        printf("3. Go back\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                hex_to_rgb();
                break;
            case 2:
                rgb_to_hex();
                break;
            case 3:
                printf("Going back to main menu...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while(option != 3);
}

void hex_to_rgb() {
    char hex[7];
    int r, g, b;
    printf("Enter a 6-digit HEX code without # symbol: ");
    scanf("%s", hex);
    r = strtol(hex, NULL, 16) >> 16;
    g = (strtol(hex, NULL, 16) >> 8) & 0xFF;
    b = strtol(hex, NULL, 16) & 0xFF;
    printf("RGB value for #%s is %d, %d, %d\n", hex, r, g, b);
}

void rgb_to_hex() {
    int r, g, b;
    char hex[7];
    printf("Enter R value (0-255): ");
    scanf("%d", &r);
    printf("Enter G value (0-255): ");
    scanf("%d", &g);
    printf("Enter B value (0-255): ");
    scanf("%d", &b);
    snprintf(hex, 7, "%02X%02X%02X", r, g, b);
    printf("Hex code for RGB(%d,%d,%d) is #%s\n", r, g, b, hex);
}