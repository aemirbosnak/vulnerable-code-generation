//FormAI DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

// Define our color struct
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGBColor;

// Declare our asynchronous conversion function
void convert_to_hex_async(RGBColor color);

// Declare our synchronous conversion function
void convert_to_hex(RGBColor color);

int main() {
    // Prompt user for RGB values
    printf("Enter the RGB values (comma-separated): ");
    uint8_t red, green, blue;
    if (scanf("%hhu,%hhu,%hhu", &red, &green, &blue) != 3) {
        printf("Invalid input! Please enter three comma-separated integers.\n");
        return EXIT_FAILURE;
    }

    RGBColor color = {red, green, blue};

    bool async;
    printf("Do you want to convert asynchronously? (y/n): ");
    char input[256];
    if (fgets(input, sizeof input, stdin) == NULL) {
        printf("Error reading input!\n");
        return EXIT_FAILURE;
    }
    char choice = toupper(input[0]);
    if (choice == 'Y') {
        convert_to_hex_async(color);
        async = true;
    } else {
        convert_to_hex(color);
        async = false;
    }

    if (async) {
        printf("Conversion in progress. Press any key to cancel...\n");
        getchar();
    }

    return EXIT_SUCCESS;
}

void convert_to_hex_async(RGBColor color) {
    printf("Starting asynchronous hex conversion...\n");
    // Simulate async process by sleeping for 5 seconds
    sleep(5);
    convert_to_hex(color);
}

void convert_to_hex(RGBColor color) {
    char hexcode[8];
    sprintf(hexcode, "#%02X%02X%02X", color.red, color.green, color.blue);
    printf("Hex code: %s\n", hexcode);
}