//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

void RGBtoHEX(int r, int g, int b);
void HEXtoRGB(char* hex);

int main() {
    int choice, r, g, b;
    char hex[MAX_LENGTH];
    printf("Welcome to the Color Code Converter!\n");

    do {
        printf("What would you like to do?\n"
               "1) Convert RGB to HEX\n"
               "2) Convert HEX to RGB\n"
               "3) Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter RGB values:\n");
                printf("Red: ");
                scanf("%d", &r);
                printf("Green: ");
                scanf("%d", &g);
                printf("Blue: ");
                scanf("%d", &b);
                RGBtoHEX(r, g, b);
                break;
            case 2:
                printf("Enter HEX value (without the '#' symbol):\n");
                scanf("%s", hex);
                HEXtoRGB(hex);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

void RGBtoHEX(int r, int g, int b) {
    char hex[MAX_LENGTH];
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    printf("HEX: %s\n", hex);
}

void HEXtoRGB(char* hex) {
    int r, g, b;
    sscanf(hex, "%02X%02X%02X", &r, &g, &b);
    printf("RGB: %d,%d,%d\n", r, g, b);
}