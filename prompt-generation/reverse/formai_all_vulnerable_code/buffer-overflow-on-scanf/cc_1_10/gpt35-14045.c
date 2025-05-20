//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* C Color Code Converter Example Program */

void hex_to_rgb(char *hex_code, int *r, int *g, int *b);
void rgb_to_hex(int r, int g, int b, char *hex_code);

int main()
{
    int choice;
    char input_code[7];
    int red, green, blue;
    char output_code[7];

    printf("Welcome to the C Color Code Converter Program!\n");
    printf("What would you like to do?\n");
    printf("1. Convert Hex Color Code to RGB\n");
    printf("2. Convert RGB to Hex Color Code\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Please enter the Hex Code to convert it to RGB: ");
        scanf("%s", input_code);
        hex_to_rgb(input_code, &red, &green, &blue);
        printf("RGB Color Code: %d, %d, %d\n", red, green, blue);
    }
    else if (choice == 2) {
        printf("Please enter the RGB values (separated by spaces) to convert it to Hex Color Code: ");
        scanf("%d%d%d", &red, &green, &blue);
        rgb_to_hex(red, green, blue, output_code);
        printf("Hex Color Code: %s\n", output_code);
    }
    else {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }

    return 0;
}

/* Converts Hex Code to RGB */
void hex_to_rgb(char *hex_code, int *r, int *g, int *b) {
    char *ptr;
    long hex_num;

    hex_num = strtol(hex_code, &ptr, 16);

    *r = (hex_num >> 16) & 0xFF;
    *g = (hex_num >> 8) & 0xFF;
    *b = (hex_num) & 0xFF;
}

/* Converts RGB to Hex Code */
void rgb_to_hex(int r, int g, int b, char *hex_code) {
    sprintf(hex_code, "#%02X%02X%02X", r, g, b);
}