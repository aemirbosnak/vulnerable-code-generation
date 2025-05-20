//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n=====================\n");
    printf(" C Color Code Converter \n");
    printf("=====================\n");
    printf("1. RGB to HEX \n");
    printf("2. HEX to RGB \n");
    printf("3. Exit \n");
    printf("=====================\n");
    printf("Select an option: ");
}

void rgbToHex(int r, int g, int b) {
    printf("RGB(%d, %d, %d) -> HEX: #%02X%02X%02X\n", r, g, b, r, g, b);
}

void hexToRgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex + 1, "%02X%02X%02X", &r, &g, &b) == 3) {
        printf("HEX: %s -> RGB(%d, %d, %d)\n", hex, r, g, b);
    } else {
        printf("Invalid HEX format! Please use: #RRGGBB\n");
    }
}

int main() {
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int r, g, b;
            printf("Enter RGB values (0-255): \n");
            printf("R: ");
            scanf("%d", &r);
            printf("G: ");
            scanf("%d", &g);
            printf("B: ");
            scanf("%d", &b);

            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                printf("Invalid RGB values! Each value should be in the range of 0 to 255.\n");
            } else {
                rgbToHex(r, g, b);
            }
        } else if (choice == 2) {
            char hex[8];
            printf("Enter HEX value (format: #RRGGBB): ");
            scanf("%s", hex);
            hexToRgb(hex);
        } else if (choice == 3) {
            printf("Exiting the Color Code Converter. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please select a valid option from the menu.\n");
        }
    }
    return 0;
}