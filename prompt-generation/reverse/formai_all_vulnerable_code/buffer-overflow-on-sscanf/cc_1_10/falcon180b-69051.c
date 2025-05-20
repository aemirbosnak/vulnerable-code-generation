//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
// Cyberpunk Color Code Converter

#include <stdio.h>
#include <stdlib.h>

// Define color code values
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define BLACK 30

// Function to convert color code to ANSI escape sequence
void colorCodeToANSI(int colorCode) {
    printf("\033[1;%dm", colorCode);
}

// Function to convert ANSI escape sequence to color code
int ANSItoColorCode(char* ansiSequence) {
    int colorCode = 0;
    if (ansiSequence[0] == '\033' && ansiSequence[1] == '[') {
        sscanf(ansiSequence, "\033[1;%dm", &colorCode);
    }
    return colorCode;
}

// Main function
int main() {
    // Print welcome message in red
    colorCodeToANSI(RED);
    printf("Welcome to the Cyberpunk Color Code Converter!\n");
    colorCodeToANSI(WHITE);

    // Get user input
    char input[100];
    printf("Enter a color code (e.g. 31 for red): ");
    scanf("%s", input);

    // Convert input to color code
    int colorCode = ANSItoColorCode(input);

    // Print result in magenta
    colorCodeToANSI(MAGENTA);
    printf("The color code for %s is: %d\n", input, colorCode);
    colorCodeToANSI(WHITE);

    return 0;
}

// End of program