//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>

/**
 * Function to print ASCII art of given character
 *
 * @param c the character to be converted into ASCII art
 */
void printAsciiArt(char c) {
    switch (c) {
        case 'A':
            printf("  /\\  \n");
            printf(" /  \\ \n");
            printf("/    \\\n");
            printf("/------\\\n");
            printf("/        \\\n");
            printf("/          \\\n");
            break;
        case 'B':
            printf("/-----\\ \n");
            printf("|      \\\n");
            printf("|-------\\\n");
            printf("|       |\n");
            printf("|------/\n");
            printf("|      /\n");
            printf("\\-----/\n");
            break;
        case 'C':
            printf("  /-----\\ \n");
            printf(" /       \\\n");
            printf("/         \\\n");
            printf("\\         /\n");
            printf(" \\       /\n");
            printf("  \\-----/\n");
            break;
        case 'D':
            printf("/-----\\ \n");
            printf("|      \\\n");
            printf("|       \\\n");
            printf("|       /\n");
            printf("|------/\n");
            printf("|      \\\n");
            printf("\\-----/\n");
            break;
        case 'E':
            printf("/------\\\n");
            printf("|       \n");
            printf("|------\\\n");
            printf("|       \n");
            printf("|------\\\n");
            printf("|       \n");
            printf("\\------/\n");
            break;
        default:
            printf("invalid character\n");
    }
}

int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printAsciiArt(c);
    return 0;
}