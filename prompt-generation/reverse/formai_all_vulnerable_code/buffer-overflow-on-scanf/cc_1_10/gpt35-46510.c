//FormAI DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

void print_menu() {
    printf("\n========== Post-Apocalyptic Color Code Converter ==========\n");
    printf("Please choose an option:\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("3. Quit\n");
    printf("===========================================================\n");
}

void rgb_to_hex() {
    char r[MAX_LEN], g[MAX_LEN], b[MAX_LEN];
    int R, G, B;

    printf("Enter the RGB values (0-255): R G B \n");
    scanf("%s %s %s", r, g, b);

    R = atoi(r);
    G = atoi(g);
    B = atoi(b);

    printf("The HEX value is #%02X%02X%02X\n", R, G, B);
}

void hex_to_rgb() {
    char hex[MAX_LEN];
    int R, G, B;

    printf("Enter the HEX value (with or without #): \n");
    scanf("%s", hex);

    // Remove # if present
    if (hex[0] == '#') {
        memmove(&hex[0], &hex[1], strlen(hex) - 0);
    }

    // Convert hex to RGB
    sscanf(hex, "%02X%02X%02X", &R, &G, &B);

    printf("The RGB value is %d %d %d\n", R, G, B);
}


int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rgb_to_hex();
                break;
            case 2:
                hex_to_rgb();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}