//FormAI DATASET v1.0 Category: Color Code Converter ; Style: active
#include <stdio.h>
#include <string.h>

void print_header() {
    printf("+------------------------------------------------+\n");
    printf("|         C Color Code Converter Program         |\n");
    printf("+------------------------------------------------+\n");
}

void print_menu() {
    printf("\nPlease select an option:\n");
    printf("(1) Convert RGB to Hex code\n");
    printf("(2) Convert Hex code to RGB\n");
    printf("(3) Exit\n");
}

int get_choice() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void rgb_to_hex() {
    int r, g, b;
    char hex[7];

    printf("\nEnter the RGB values (0-255):\n");
    printf("R: ");
    scanf("%d", &r);
    printf("G: ");
    scanf("%d", &g);
    printf("B: ");
    scanf("%d", &b);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("\nInvalid RGB values entered.\n");
        return;
    }

    sprintf(hex, "#%02X%02X%02X", r, g, b);

    printf("\nHex code: %s\n", hex);
}

void hex_to_rgb() {
    char hex[7];
    int r, g, b;

    printf("\nEnter the Hex code (with the '#' symbol):\n");
    scanf("%s", hex);

    if (strlen(hex) != 7 || hex[0] != '#') {
        printf("\nInvalid Hex code entered.\n");
        return;
    }

    sscanf(hex+1, "%02x%02x%02x", &r, &g, &b);

    printf("\nRGB values: %d, %d, %d\n", r, g, b);
}

int main() {
    int choice;

    print_header();

    do {
        print_menu();

        choice = get_choice();

        switch (choice) {
            case 1:
                rgb_to_hex();
                break;
            case 2:
                hex_to_rgb();
                break;
            case 3:
                printf("\nThank you for using C Color Code Converter.\n");
                break;
            default:
                printf("\nInvalid choice entered. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}