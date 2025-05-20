//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void rgbToHex(int r, int g, int b, char* hexCode);
void hexToRgb(char* hexCode, int* r, int* g, int* b);

int main()
{
    int choice;
    char code[10];
    int r, g, b;
    char hexCode[8];

    while (1) {
        printf("Color code converter\n");
        printf("1. Convert RGB to HEX\n");
        printf("2. Convert HEX to RGB\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter RGB values (separated by spaces): ");
                scanf("%d %d %d", &r, &g, &b);
                rgbToHex(r, g, b, hexCode);
                printf("Hex code: %s\n", hexCode);
                break;

            case 2:
                printf("Enter Hex code (without #): ");
                scanf("%s", code);
                hexToRgb(code, &r, &g, &b);
                printf("RGB values: %d %d %d\n", r, g, b);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

// function to convert RGB values to Hex code
void rgbToHex(int r, int g, int b, char* hexCode)
{
    sprintf(hexCode, "%02X%02X%02X", r, g, b);
}

// function to convert Hex code to RGB values
void hexToRgb(char* hexCode, int* r, int* g, int* b)
{
    char* ptr;
    *r = strtol(hexCode, &ptr, 16);
    *g = strtol(ptr, &ptr, 16);
    *b = strtol(ptr, NULL, 16);
}