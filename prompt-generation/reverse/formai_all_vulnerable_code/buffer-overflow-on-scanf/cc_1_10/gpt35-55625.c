//FormAI DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void convertToRGB(char color[8], int r, int g, int b);
void convertToHex(int r, int g, int b);

int main() {
    char choice;
    do {
        printf("Welcome to the Color Code Converter!\n");
        printf("Enter '1' to convert from RGB to Hex, or '2' to convert from Hex to RGB: ");
        scanf("%c", &choice);
        getchar();

        if (choice == '1') {
            int red, green, blue;
            printf("Enter values for Red, Green, and Blue, separated by spaces: ");
            scanf("%d %d %d", &red, &green, &blue);
            getchar();

            convertToHex(red, green, blue);
        }
        else if (choice == '2') {
            char color[8];
            printf("Enter Hex code (with #): ");
            scanf("%s", color);
            convertToRGB(color, strtol(&color[1], NULL, 16) >> 16, strtol(&color[3], NULL, 16) >> 8, strtol(&color[5], NULL, 16));
        }
        else {
            printf("Invalid input. Please try again.\n");
        }

        printf("Enter 'y' to convert again, or any other key to exit: ");
        scanf("%c", &choice);
        getchar();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Color Code Converter! Have a colorful day!\n");

    return 0;
}

void convertToRGB(char color[8], int r, int g, int b) {
    printf("Converting Hex code %s to RGB...\n", color);
    printf("Red: %d\n", r);
    printf("Green: %d\n", g);
    printf("Blue: %d\n", b);
}

void convertToHex(int r, int g, int b) {
    printf("Converting RGB values (%d, %d, %d) to Hex...\n", r, g, b);
    printf("#%02X%02X%02X\n", r, g, b);
}