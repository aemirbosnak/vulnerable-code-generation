//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
/* The Case of the Color Code Conversion */

#include <stdio.h>
#include <string.h>

// Constants for color codes
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Function to check if color code is valid
int isValid(char* code) {
    int len = strlen(code);
    if (len != 7 || code[0] != '#' ) {
        return 0;
    }
    for (int i = 1; i < len; i++) {
        if ((code[i] < '0' || code[i] > '9') && 
            (code[i] < 'A' || code[i] > 'F') &&
            (code[i] < 'a' || code[i] > 'f')) {
            return 0;
        }
    }
    return 1;
}

// Function to convert color code to corresponding color
char* convertColor(char* code) {
    if (strcmp(code, "#000000") == 0) {
        return BLACK;
    } else if (strcmp(code, "#FF0000") == 0) {
        return RED;
    } else if (strcmp(code, "#00FF00") == 0) {
        return GREEN;
    } else if (strcmp(code, "#FFFF00") == 0) {
        return YELLOW;
    } else if (strcmp(code, "#0000FF") == 0) {
        return BLUE;
    } else if (strcmp(code, "#FF00FF") == 0) {
        return MAGENTA;
    } else if (strcmp(code, "#00FFFF") == 0) {
        return CYAN;
    } else if (strcmp(code, "#FFFFFF") == 0) {
        return WHITE;
    } else {
        return NULL;
    }
}

// Main function
int main() {
    // Introduction to the case
    printf("It was a foggy morning in London when I received a call from a client who needed help with a color code conversion.\n");
    printf("A wealthy businessman named Mr. John Smith had recently hired a web developer to build a website for his company.\n");
    printf("The developer had sent him a color code for the background, but Mr. Smith had no idea what it meant.\n");
    printf("He had heard that I was a detective with a special talent for solving coding puzzles and so he had come to me for help.\n");
    printf("After listening to his story, I agreed to take the case and set out to find the solution.\n\n");

    // Get input from user
    char code[8];
    printf("Please enter the color code you wish to convert: ");
    scanf("%s", code);

    // Check if color code is valid
    if (!isValid(code)) {
        printf("Invalid color code. Please try again.\n");
        return 0;
    }

    // Convert color code to corresponding color
    char* color = convertColor(code);

    // Check if color code was found
    if (color == NULL) {
        printf("Color code not found. Please try again.\n");
        return 0;
    }

    // Display the result
    printf("The color corresponding to code %s is %s.\n", code, color);
    printf("Case solved. Another job well done by the great detective Sherlock Holmes!");

    return 0;
}