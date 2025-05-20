//Falcon2-11B DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to generate ASCII art
void generateArt(char *input, int width, int height, int x, int y) {
    // Check if the input string is empty
    if (strlen(input) == 0) {
        return;
    }

    // Check if the current position is within the boundary
    if (x >= width || y >= height) {
        return;
    }

    // Check if the current character is a space
    if (isspace(input[0])) {
        return;
    }

    // Check if the current character is uppercase or lowercase
    if (islower(input[0])) {
        // Draw the lowercase character
        printf("  /|\\\n");
    } else if (isupper(input[0])) {
        // Draw the uppercase character
        printf("  / \\\n");
    }

    // Recursively call the function with the next character
    generateArt(input + 1, width, height, x + 1, y);

    // Move to the next position
    printf(" | ");
    x++;
}

// Main function
int main() {
    char input[100];
    int width, height;
    int x, y;

    // Get the input string
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Get the width and height of the ASCII art
    printf("Enter the width: ");
    scanf("%d", &width);
    printf("Enter the height: ");
    scanf("%d", &height);

    // Generate the ASCII art
    generateArt(input, width, height, 0, 0);

    // Print a new line
    printf("\n");

    return 0;
}