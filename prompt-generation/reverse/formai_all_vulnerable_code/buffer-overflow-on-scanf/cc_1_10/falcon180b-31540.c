//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define PINK 5
#define CYAN 6
#define WHITE 7

// Function to convert the color code to its corresponding color name
char* colorCodeToName(int colorCode) {
    switch(colorCode) {
        case BLACK:
            return "Black";
        case RED:
            return "Red";
        case GREEN:
            return "Green";
        case YELLOW:
            return "Yellow";
        case BLUE:
            return "Blue";
        case PINK:
            return "Pink";
        case CYAN:
            return "Cyan";
        case WHITE:
            return "White";
        default:
            return "Invalid color code";
    }
}

// Function to convert the color name to its corresponding color code
int nameToColorCode(char* name) {
    if(strcmp(name, "Black") == 0)
        return BLACK;
    else if(strcmp(name, "Red") == 0)
        return RED;
    else if(strcmp(name, "Green") == 0)
        return GREEN;
    else if(strcmp(name, "Yellow") == 0)
        return YELLOW;
    else if(strcmp(name, "Blue") == 0)
        return BLUE;
    else if(strcmp(name, "Pink") == 0)
        return PINK;
    else if(strcmp(name, "Cyan") == 0)
        return CYAN;
    else if(strcmp(name, "White") == 0)
        return WHITE;
    else
        return -1;
}

// Function to display the color code and its corresponding color name
void displayColorCode(int colorCode) {
    printf("Color code: %d\n", colorCode);
    printf("Color name: %s\n", colorCodeToName(colorCode));
}

// Main function
int main() {
    // Declare variables
    char input[100];
    int colorCode;

    // Get user input
    printf("Enter a color code: ");
    scanf("%s", input);

    // Convert the input to a color code
    colorCode = nameToColorCode(input);

    // Display the color code and its corresponding color name
    if(colorCode!= -1)
        displayColorCode(colorCode);
    else
        printf("Invalid input\n");

    return 0;
}