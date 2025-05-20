//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>

int main() {

    char inputChar;

    printf("Enter a character: ");
    scanf("%c", &inputChar);

    printf("\n");
    printf("The ASCII art for character %c is:\n\n", inputChar);

    switch (inputChar) {
        
        case 'A':
            printf("  /\\ \n");
            printf(" /--\\ \n");
            printf("/    \\ \n");
            break;

        case 'B':
            printf("|---\n");
            printf("|---\\\n");
            printf("|__/\n");
            break;

        case 'C':
            printf("  ___\n");
            printf(" /___\\\n");
            printf("/_____\n");
            break;

        case 'D':
            printf("|---\\\n");
            printf("|    \\\n");
            printf("|___/\n");
            break;
        
        case 'E':
            printf(" _____\n");
            printf("|_____\n");
            printf("|      \n");
            break;

        case 'F':
            printf(" _____\n");
            printf("|_____\n");
            printf("|      \n");
            break;

        case 'G':
            printf(" _____\n");
            printf("|     \n");
            printf("|__--\\\n");
            printf("|____/\n");
            break;

        case 'H':
            printf("|    |\n");
            printf("|----|\n");
            printf("|    |\n");
            break;

        case 'I':
            printf(" _____\n");
            printf("   |\n");
            printf(" __|\n");
            break;
        
        case 'J':
            printf("      |\n");
            printf("      |\n");
            printf("__--__|\n");
            break;

        case 'K':
            printf("|__/ \n");
            printf("|/   \n");
            printf("|\\__ \n");
            break;

        case 'L':
            printf("|      \n");
            printf("|      \n");
            printf("|_____ \n");
            break;

        case 'M':
            printf("/\\    /\\\n");
            printf("|  \\  /  |\n");
            printf("|   \\/   |\n");
            printf("|        |\n");
            printf("|        |\n");
            break;

        case 'N':
            printf("|\\    |\n");
            printf("| \\   |\n");
            printf("|  \\  |\n");
            printf("|   \\ |\n");
            printf("|    \\|\n");
            break;

        case 'O':
            printf("  __ \n");
            printf(" /  \\ \n");
            printf("/____\\\n");
            break;

        case 'P':
            printf("|___\\ \n");
            printf("|----\\\n");
            printf("|____/\n");
            break;

        case 'Q':
            printf("  __ \n");
            printf(" /  \\ \n");
            printf("/____\\\n");
            printf("    / \n");
            printf("   /\n");
            break;

        case 'R':
            printf("|___\\ \n");
            printf("|----\\\n");
            printf("| \\__/ \n");
            break;

        case 'S':
            printf(" ___ \n");
            printf("/    \\\n");
            printf("\\____/\n");
            break;

        case 'T':
            printf("_____ \n");
            printf("   |\n");
            printf("   |\n");
            break;

        case 'U':
            printf("|    |\n");
            printf("|    |\n");
            printf("\\____/\n");
            break;

        case 'V':
            printf("\\      /\n");
            printf(" \\    /\n");
            printf("  \\  /\n");
            printf("   \\/\n");
            break;

        case 'W':
            printf("/\\    /\\\n");
            printf("|  \\  /  |\n");
            printf("|___\\/___|\n");
            printf("|        |\n");
            printf("|        |\n");
            break;

        case 'X':
            printf("\\   /\n");
            printf(" \\ /\n");
            printf(" / \\\n");
            printf("/   \\\n");
            break;

        case 'Y':
            printf("\\   /\n");
            printf(" \\ /\n");
            printf("  |\n");
            break;

        case 'Z':
            printf("_____ \n");
            printf("    /\n");
            printf("  /  \n");
            printf("/____\\\n");
            break;

        default:
            printf("Sorry, the character entered is not in the range A-Z.\n");

    }

    return 0;
}