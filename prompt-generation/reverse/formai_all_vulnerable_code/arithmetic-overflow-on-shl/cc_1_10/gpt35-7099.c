//FormAI DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RGBtoHex(int red, int green, int blue) {
    int hex_num = (red << 16) | (green << 8) | blue;
    return hex_num;
} 

void HexToRGB(int hex_num, int* red, int* green, int* blue) {
    *red = (hex_num >> 16) & 0xFF;
    *green = (hex_num >> 8) & 0xFF;
    *blue = hex_num & 0xFF;
}

int main() {
    int choice;
    int red, green, blue;
    int hex_num;
    char hex_val[9];

    printf("COLOR CODE CONVERTER\n");
    do {
        printf("1. RGB to Hex\n");
        printf("2. Hex to RGB\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("[RGB to Hex Converter]\n");
                printf("Enter red value (0-255): ");
                scanf("%d", &red);
                printf("Enter green value (0-255): ");
                scanf("%d", &green);
                printf("Enter blue value (0-255): ");
                scanf("%d", &blue);
                hex_num = RGBtoHex(red, green, blue);
                sprintf(hex_val, "#%06x", hex_num);
                printf("Hex value: %s\n", hex_val);
                break;

            case 2:
                printf("[Hex to RGB Converter]\n");
                printf("Enter hex value (#000000-#FFFFFF): ");
                scanf("%s", hex_val);
                if (strlen(hex_val) != 7 || hex_val[0] != '#') {
                    printf("Invalid hex value\n");
                    break;
                }
                hex_num = strtol(hex_val+1, NULL, 16);
                HexToRGB(hex_num, &red, &green, &blue);
                printf("RGB value: (%d, %d, %d)\n", red, green, blue);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}