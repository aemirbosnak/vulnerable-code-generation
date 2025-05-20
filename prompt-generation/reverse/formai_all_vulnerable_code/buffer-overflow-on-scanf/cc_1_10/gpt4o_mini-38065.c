//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
#define MAX_ASCII_LENGTH 512

void printAsciiArt(char character);
void printWelcomeMessage();
void clearScreen();

int main() {
    char input[MAX_INPUT_LENGTH];
    char continueGenerating = 'y';

    clearScreen();
    printWelcomeMessage();

    while (continueGenerating == 'y' || continueGenerating == 'Y') {
        printf("\nEnter a character to convert into ASCII art: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input (if exists)
        input[strcspn(input, "\n")] = 0; 

        if (strlen(input) != 1) {
            printf("Please enter a single character only.\n");
        } else {
            printAsciiArt(input[0]);
        }

        printf("\nWould you like to generate ASCII art for another character? (y/n): ");
        scanf(" %c", &continueGenerating);
        getchar(); // To consume newline left by scanf
        clearScreen();
    }

    printf("Thank you for using the ASCII art generator. Goodbye!\n");
    return 0;
}

void printAsciiArt(char character) {
    printf("\nASCII Art for '%c':\n", character);
    switch (character) {
        case 'A':
        case 'a':
            printf("    A    \n");
            printf("   A A   \n");
            printf("  AAAAA  \n");
            printf(" A     A \n");
            printf("A       A\n");
            break;
        case 'B':
        case 'b':
            printf("BBBBBB  \n");
            printf("B     B \n");
            printf("BBBBBB  \n");
            printf("B     B \n");
            printf("BBBBBB  \n");
            break;
        case 'C':
        case 'c':
            printf("  CCCCC\n");
            printf(" C\n");
            printf("C\n");
            printf(" C\n");
            printf("  CCCCC\n");
            break;
        case 'D':
        case 'd':
            printf("DDDDDD  \n");
            printf("D     D \n");
            printf("D     D \n");
            printf("D     D \n");
            printf("DDDDDD  \n");
            break;
        case 'E':
        case 'e':
            printf("EEEEEE\n");
            printf("E\n");
            printf("EEEEEE\n");
            printf("E\n");
            printf("EEEEEE\n");
            break;
        // Additional cases for more characters can be added here
        default:
            printf("Character '%c' is not supported for ASCII art!\n", character);
            break;
    }
}

void printWelcomeMessage() {
    printf("====================================\n");
    printf("      ASCII Art Generator           \n");
    printf("====================================\n");
    printf("Enter a single character to see its ASCII representation.\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // Escape sequence to clear the terminal screen
}