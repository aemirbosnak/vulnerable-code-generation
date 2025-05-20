//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>

// function to convert RGB to HEX
void rgbToHex(int r, int g, int b) {
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    printf("%s", hex);
}

// function to convert HEX to RGB
void hexToRgb(char hex[]) {
    int r, g, b;
    sscanf(hex, "#%02X%02X%02X", &r, &g, &b);
    printf("RGB: %d %d %d\n", r, g, b);
}

int main() {
    int choice;

    // loop until user decides to quit
    do {
        printf("\n\n");
        printf("1. Convert RGB to HEX\n");
        printf("2. Convert HEX to RGB\n");
        printf("3. Quit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the values of Red, Green and Blue (0-255): ");
            int r, g, b;
            scanf("%d %d %d", &r, &g, &b);
            rgbToHex(r, g, b);
            break;

        case 2:
            printf("Enter the HEX value: ");
            char hex[7];
            scanf("%s", hex);
            hexToRgb(hex);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}