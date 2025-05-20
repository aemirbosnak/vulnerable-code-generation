//FormAI DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>

// function declarations
void hexToRGB(char[]);
void RGBTohex(int[], char[]);

int main() {
    int choice;
    char hex[7];
    int RGB[3];

    printf("Welcome to the Color Code Converter!\n");

    // menu of options
    do {
        printf("\nChoose an option:\n");
        printf("1. Convert hexadecimal to RGB\n");
        printf("2. Convert RGB to hexadecimal\n");
        printf("3. Quit\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the hexadecimal color code (with '#' symbol): ");
                scanf("%s", hex);
                hexToRGB(hex);
                break;
            case 2:
                printf("\nEnter the values for red, green, and blue (0-255):\n");
                scanf("%d %d %d", &RGB[0], &RGB[1], &RGB[2]);
                RGBTohex(RGB, hex);
                printf("The hexadecimal color code is: %s\n", hex);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
        }
    } while(choice != 3);

    return 0;
}

// function to convert hex color code to RGB
void hexToRGB(char hex[]) {
    int red, green, blue;
    sscanf(hex, "#%02x%02x%02x", &red, &green, &blue);
    printf("The RGB values are: (%d, %d, %d)\n", red, green, blue);
}

// function to convert RGB values to hex color code
void RGBTohex(int RGB[], char hex[]) {
    sprintf(hex, "#%02x%02x%02x", RGB[0], RGB[1], RGB[2]);
}