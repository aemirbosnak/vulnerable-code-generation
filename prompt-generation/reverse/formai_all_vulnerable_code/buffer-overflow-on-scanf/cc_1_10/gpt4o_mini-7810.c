//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORMAT_RGB 1
#define FORMAT_HEX 2

// Function prototypes
void convertRGBToHex(int r, int g, int b);
void convertHexToRGB(const char* hex);
void displayMenu();
int getInputFormat();
void getRGBValues(int *r, int *g, int *b);
int isValidHex(const char *hex);
void toUpperCase(char *str);

int main() {
    int choice;
    int r, g, b;
    char hex[7];

    while (1) {
        displayMenu(); 
        choice = getInputFormat();

        switch (choice) {
            case FORMAT_RGB:
                printf("Enter RGB values (0-255) separated by spaces: ");
                getRGBValues(&r, &g, &b);
                convertRGBToHex(r, g, b);
                break;

            case FORMAT_HEX:
                printf("Enter a HEX color code (e.g., #FF5733): ");
                scanf("%s", hex);
                if (isValidHex(hex)) {
                    convertHexToRGB(hex);
                } else {
                    printf("Invalid HEX color code format.\n");
                }
                break;

            default:
                printf("Exiting program.\n");
                return 0;
        }
    }
}

// Function to display the menu for the user
void displayMenu() {
    printf("\nColor Code Converter\n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    printf("0. Exit\n");
    printf("Choose an option (1-2 or 0 to exit): ");
}

// Function to get the input format choice from the user
int getInputFormat() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to prompt the user for RGB values and capture them
void getRGBValues(int *r, int *g, int *b) {
    scanf("%d %d %d", r, g, b);
    // Basic validation for RGB values
    if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255) {
        printf("RGB values must be in the range of 0 to 255.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to convert RGB values to a HEX color code
void convertRGBToHex(int r, int g, int b) {
    printf("RGB(%d, %d, %d) in HEX is: #%02X%02X%02X\n", r, g, b, r, g, b);
}

// Function to convert a HEX color code to RGB values
void convertHexToRGB(const char* hex) {
    int r, g, b;

    // Parse the hex string, stripping out the '#'
    if (hex[0] == '#') {
        sscanf(hex + 1, "%02X%02X%02X", &r, &g, &b);
    } else {
        sscanf(hex, "%02X%02X%02X", &r, &g, &b);
    }

    printf("HEX %s in RGB is: (%d, %d, %d)\n", hex, r, g, b);
}

// Function to validate the HEX color code format
int isValidHex(const char *hex) {
    if (strlen(hex) != 7 && strlen(hex) != 6) {
        return 0;
    }
    if (hex[0] == '#') {
        return strspn(hex + 1, "0123456789ABCDEFabcdef") == 6;
    } else {
        return strspn(hex, "0123456789ABCDEFabcdef") == 6;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (; *str; ++str) {
        *str = toupper((unsigned char)*str);
    }
}