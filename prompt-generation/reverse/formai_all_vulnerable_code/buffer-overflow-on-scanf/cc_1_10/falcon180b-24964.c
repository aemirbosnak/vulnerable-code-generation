//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16
#define MAX_COLOR_NAME_LENGTH 20

// Define the color names and their corresponding hexadecimal values
struct color {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[8];
};

static struct color colors[] = {
    {"Black", "000000"},
    {"White", "FFFFFF"},
    {"Red", "FF0000"},
    {"Green", "00FF00"},
    {"Blue", "0000FF"},
    {"Yellow", "FFFF00"},
    {"Cyan", "00FFFF"},
    {"Magenta", "FF00FF"},
    {"Gray", "808080"},
    {"DarkGray", "A9A9A9"},
    {"LightGray", "D3D3D3"},
    {"LightBlue", "ADD8E6"},
    {"LightGreen", "90EE90"},
    {"LightPink", "FFB6C1"},
    {"Orange", "FFA500"},
    {"Purple", "800080"}
};

int main() {
    int numColors = sizeof(colors) / sizeof(struct color);
    char colorName[MAX_COLOR_NAME_LENGTH];
    char hexValue[9];

    // Prompt the user to enter a color name
    printf("Enter a color name: ");
    scanf("%s", colorName);

    // Convert the color name to uppercase
    for (int i = 0; i < strlen(colorName); i++) {
        colorName[i] = toupper(colorName[i]);
    }

    // Search for the color name in the color array
    for (int i = 0; i < numColors; i++) {
        if (strcmp(colors[i].name, colorName) == 0) {
            // Convert the hexadecimal value to uppercase
            for (int j = 0; j < strlen(colors[i].hex); j++) {
                hexValue[j] = toupper(colors[i].hex[j]);
            }
            // Print the color name and hexadecimal value
            printf("The hexadecimal value for %s is %s.\n", colorName, hexValue);
            return 0;
        }
    }

    // If the color name is not found, print an error message
    printf("Invalid color name.\n");
    return 1;
}