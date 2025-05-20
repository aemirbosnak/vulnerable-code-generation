//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to print the ASCII art for the given character
void printCharacterArt(char character) {
    switch (character) {
        case 'A':
        case 'a':
            printf("     /\\ \n");
            printf("    /  \\ \n");
            printf("   /____\\ \n");
            printf("  /      \\ \n");
            printf(" /        \\ \n");
            break;
        case 'B':
        case 'b':
            printf(" ____  \n");
            printf("|    \\ \n");
            printf("|____/ \n");
            printf("|    \\ \n");
            printf("|____/ \n");
            break;
        case 'C':
        case 'c':
            printf("  ____  \n");
            printf(" /      \n");
            printf("|       \n");
            printf("|       \n");
            printf(" \\ ____ \n");
            break;
        // Add more cases for other characters.
        // We can use online ASCII art generators for this purpose.
        default:
            printf("   \n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("   \n");
            break;
    }
}

// Function to generate ASCII art for the given string
void generateAsciiArt(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        printCharacterArt(string[i]);
    }
}

int main() {
    char inputString[100];

    // Ask user for input
    printf("Enter a string to generate ASCII art: ");
    scanf("%s", inputString);

    generateAsciiArt(inputString);

    return 0;
}