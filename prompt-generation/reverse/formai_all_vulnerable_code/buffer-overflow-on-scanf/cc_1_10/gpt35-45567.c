//FormAI DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to convert hex color code to RGB color code
void hexToRGB(char hexcode[]) {
    int r, g, b;
    sscanf(hexcode, "#%02x%02x%02x", &r, &g, &b);
    printf("RGB color code: (%d, %d, %d)", r, g, b);
}

// Function to convert RGB color code to hex color code
void RGBToHex(int r, int g, int b) {
    char hexcode[7];
    sprintf(hexcode, "#%02x%02x%02x", r, g, b);
    printf("Hex color code: %s", hexcode);
}

int main() {
    int choice, r, g, b;
    char hexcode[7];

    printf("Color Code Converter\n");
    printf("--------------------\n");
    printf("1. Hex to RGB\n");
    printf("2. RGB to Hex\n");
    printf("Select an option: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter hex color code (without # symbol): ");
            scanf("%s", &hexcode);
            hexToRGB(hexcode);
            break;
        case 2:
            printf("\nEnter R value: ");
            scanf("%d", &r);
            printf("Enter G value: ");
            scanf("%d", &g);
            printf("Enter B value: ");
            scanf("%d", &b);
            RGBToHex(r, g, b);
            break;
        default:
            printf("\nInvalid option selected.");
            break;
    }

    return 0;
}