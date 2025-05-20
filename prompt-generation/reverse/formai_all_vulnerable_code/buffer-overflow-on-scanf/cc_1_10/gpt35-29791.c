//FormAI DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>

// Function to convert RGB to hexadecimal color code
void RGBtoHex(int red, int green, int blue) {
    int hexVal;
    char hexCode[7];

    // Convert red to hex code
    sprintf(hexCode, "%02X", red);
    hexVal = strlen(hexCode);

    // Concatenate green to hex code
    sprintf(hexCode + hexVal, "%02X", green);
    hexVal = strlen(hexCode);

    // Concatenate blue to hex code
    sprintf(hexCode + hexVal, "%02X", blue);

    // Print hexadecimal color code
    printf("The hexadecimal color code for RGB (%d,%d,%d) is #%s\n", red, green, blue, hexCode);
}

// Function to convert hexadecimal color code to RGB
void HexToRGB(char hexCode[]) {
    int red, green, blue;

    // Convert first two characters of hex code to red
    sscanf(hexCode, "%2X", &red);

    // Convert next two characters of hex code to green
    sscanf(hexCode + 2, "%2X", &green);

    // Convert last two characters of hex code to blue
    sscanf(hexCode + 4, "%2X", &blue);

    // Print RGB values
    printf("The RGB values for #%s are (%d,%d,%d)\n", hexCode, red, green, blue);
}

int main() {
    int option, red, green, blue;
    char hexCode[7];

    // Menu for user to choose conversion type
    printf("Choose an option:\n");
    printf("1. Convert RGB to hexadecimal color code\n");
    printf("2. Convert hexadecimal color code to RGB\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            // Ask user for RGB values
            printf("Enter values for red, green, and blue (0-255): ");
            scanf("%d %d %d", &red, &green, &blue);

            // Call function to convert RGB to hex
            RGBtoHex(red, green, blue);
            break;
        case 2:
            // Ask user for hex code
            printf("Enter hexadecimal color code (i.e. FF0000): ");
            scanf("%s", hexCode);

            // Call function to convert hex to RGB
            HexToRGB(hexCode);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}