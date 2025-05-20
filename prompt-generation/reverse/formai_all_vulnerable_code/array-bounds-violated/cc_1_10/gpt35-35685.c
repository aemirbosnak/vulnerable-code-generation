//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 7 // Maximum length of a color code, including '#'
#define BUFFER_SIZE 10 // Size of color buffer

void convertToRGB(char* color);
void convertToHex(char* rgb);

int main() {
    char color[MAX_LENGTH];
    char choice;

    printf("Enter a hex color code including the # symbol (#RRGGBB): ");
    fgets(color, BUFFER_SIZE, stdin); // Read user input

    // Remove newline character at the end of the string
    if (color[strlen(color) - 1] == '\n') {
        color[strlen(color) - 1] = '\0';
    }

    printf("What would you like to convert this color to? (r/g/b/h) ");
    scanf("%c", &choice);

    switch (choice) {
        case 'r':
        case 'g':
        case 'b':
            convertToRGB(color);
            break;
        case 'h':
            convertToHex(color);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

void convertToRGB(char* color) {
    // Convert hex values to decimal numbers
    int red = (int)strtol(&color[1], NULL, 16);
    int green = (int)strtol(&color[3], NULL, 16);
    int blue = (int)strtol(&color[5], NULL, 16);

    switch (*color) { // Output the requested color channel
        case 'r':
            printf("Red: %d\n", red);
            break;
        case 'g':
            printf("Green: %d\n", green);
            break;
        case 'b':
            printf("Blue: %d\n", blue);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void convertToHex(char* rgb) {
    // Convert decimal values to hex numbers
    char red[3];
    char green[3];
    char blue[3];

    sprintf(red, "%02X", atoi(&rgb[1]));
    sprintf(green, "%02X", atoi(&rgb[3]));
    sprintf(blue, "%02X", atoi(&rgb[5]));

    // Output hex conversion
    printf("Hex: #%s%s%s\n", red, green, blue);
}