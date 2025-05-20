//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void rgbToHex(int r, int g, int b) {
    printf("RGB(%d, %d, %d) in HEX is: #%02X%02X%02X\n", r, g, b, r, g, b);
}

void hexToRgb(char* hex) {
    int r, g, b;
    if (sscanf(hex + 1, "%02X%02X%02X", &r, &g, &b) == 3) {
        printf("HEX %s in RGB is: RGB(%d, %d, %d)\n", hex, r, g, b);
    } else {
        printf("Invalid HEX code format!\n");
    }
}

int main() {
    int choice;
    char hex[10];
    int r, g, b;

    printf("Welcome to the Color Code Converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-3): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // clear the buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter RGB values separated by spaces (r g b): ");
                if (scanf("%d %d %d", &r, &g, &b) != 3) {
                    printf("Invalid input! Please enter three integers.\n");
                    while(getchar() != '\n'); // clear the buffer
                    continue;
                }
                if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                    printf("RGB values must be between 0 and 255!\n");
                } else {
                    rgbToHex(r, g, b);
                }
                break;
            case 2:
                printf("Enter HEX value (e.g. #RRGGBB): ");
                scanf("%s", hex);
                if (hex[0] != '#' || (strlen(hex) != 7 && strlen(hex) != 4)) {
                    printf("Invalid HEX code format! Must start with '#' and be 7 or 4 characters long.\n");
                } else {
                    hexToRgb(hex);
                }
                break;
            case 3:
                printf("Exiting the Color Code Converter. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select 1, 2 or 3.\n");
        }
    }

    return 0;
}