//FormAI DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RGB_to_HEX(int red, int green, int blue);
void HEX_to_RGB(char hex[]);

int main() {
    printf("Welcome to the Color Converter!\n\n");
    printf("What would you like to convert today?\n");
    printf("1. RGB to HEX\n2. HEX to RGB\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int red, green, blue;
            printf("\nEnter the RGB values:\n");
            printf("R:");
            scanf("%d", &red);
            printf("G:");
            scanf("%d", &green);
            printf("B:");
            scanf("%d", &blue);
            RGB_to_HEX(red, green, blue);
            break;
        }
        case 2: {
            char hex[7];
            printf("\nEnter the HEX value:\n");
            scanf("%s", hex);
            HEX_to_RGB(hex);
            break;
        }
        default: {
            printf("\nInvalid choice! Try again.\n");
            break;
        }
    }

    return 0;
}

void RGB_to_HEX(int red, int green, int blue) {
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    printf("\nThe HEX value is: %s\n", hex);
}

void HEX_to_RGB(char hex[]) {
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    printf("\nThe RGB values are: %d, %d, %d\n", r, g, b);
}