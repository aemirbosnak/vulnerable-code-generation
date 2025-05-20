//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>

// Function to convert RGB value to HEX format, recursively processing each color channel
void rgbToHex(int r, int g, int b, char *hex, int index) {
    if (index >= 3) {
        return;  // Base case: if all channels have been processed, return
    }

    int colorValue;
    
    // Select the correct color channel and convert to HEX
    if (index == 0) {
        colorValue = r;
    } else if (index == 1) {
        colorValue = g;
    } else {
        colorValue = b;
    }

    // Convert the color value to hexadecimal representation and store it in the hex array
    sprintf(hex + index * 2, "%02X", colorValue);
    
    // Recursive call for the next color channel
    rgbToHex(r, g, b, hex, index + 1);
}

// Function to validate RGB input and return if it's in range
int validateRGB(int value) {
    return (value >= 0 && value <= 255);
}

// Main function to get user input and output HEX color code
int main() {
    int r, g, b;
    char hexColor[7] = {0};  // HEX color code (6 characters + null terminator)

    // Input: Getting RGB values from the user
    printf("Enter RGB color values (0-255) separated by spaces: \n");
    printf("R: "); scanf("%d", &r);
    printf("G: "); scanf("%d", &g);
    printf("B: "); scanf("%d", &b);

    // Validation: Check if the input RGB values are within valid range
    if (!validateRGB(r) || !validateRGB(g) || !validateRGB(b)) {
        printf("Error: RGB values must be between 0 and 255.\n");
        return 1;
    }

    // Convert RGB to HEX using recursive function
    rgbToHex(r, g, b, hexColor, 0);

    // Output: Display the corresponding HEX color code
    printf("HEX Color Code: #%s\n", hexColor);

    return 0;
}