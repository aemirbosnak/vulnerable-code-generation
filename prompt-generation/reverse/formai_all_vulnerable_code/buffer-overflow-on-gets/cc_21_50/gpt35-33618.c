//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Touring
#include <stdio.h>

int main() {
    char text[100];
    printf("Enter the text to convert to ASCII art: ");
    gets(text);
    printf("\n\n");

    for (int i = 0; i < strlen(text); i++) {
        switch (text[i]) {
            case 'a':
                printf("   /\\   \n");
                printf("　 /  \\  \n");
                printf(" /    \\ \n");
                printf("/------\\ \n");
                break;
            case 'b':
                printf(" /-----\\ \n");
                printf("|       \\\n");
                printf("|------/|\n");
                printf("|______/ \n");
                break;
            case 'c':
                printf("  /-----\\\n");
                printf(" /       \n");
                printf("|         \n");
                printf(" \\-----/ \n");
                break;
            case 'd':
                printf(" \\-----/ \n");
                printf(" |     | \n");
                printf(" |     | \n");
                printf(" /-----\\ \n");
                break;
            case 'e':
                printf(" /-----\\\n");
                printf(" |       \n");
                printf(" |-----\\\n");
                printf(" \\-----/ \n");
                break;
            case 'f':
                printf(" /-----\\\n");
                printf(" |       \n");
                printf(" |-------\n");
                printf(" \\       \n");
                break;
            case 'g':
                printf("  /-----\\\n");
                printf(" /       \n");
                printf("|   --   \n");
                printf(" \\-----\\_\n");
                break;
            case 'h':
                printf(" |     |\n");
                printf(" |-----|\n");
                printf("|       |\n");
                printf("|       |\n");
                break;
            case 'i':
                printf("||\n");
                printf("||\n");
                printf("||\n");
                printf("||\n");
                break;
            case 'j':
                printf("         /\\\n");
                printf("        || \n");
                printf("        || \n");
                printf(" \\_____/ | \n");
                break;
            case 'k':
                printf("|/    / \n");
                printf("|\\   /  \n");
                printf("| \\_/__ \n");
                printf("|      \\\n");
                break;
            case 'l':
                printf("|      \n");
                printf("|      \n");
                printf("|      \n");
                printf("|______\n");
                break;
            case 'm':
                printf("|\\     /||\n");
                printf("| \\---/ ||\n");
                printf("|     | ||\n");
                printf("|     | ||\n");
                break;
            case 'n':
                printf("|\\    |\n");
                printf("| \\   |\n");
                printf("|  \\  |\n");
                printf("|   \\_|\n");
                break;
            case 'o':
                printf("  /---\\ \n");
                printf(" /     \\ \n");
                printf("|       |\n");
                printf(" \\-----/ \n");
                break;
            case 'p':
                printf("/-----\\ \n");
                printf("|      \\\n");
                printf("|------/\n");
                printf("|      \n");
                break;
            case 'q':
                printf("  /---\\  \n");
                printf(" /     \\ \n");
                printf("|   O   |\n");
                printf(" \\-----\\_\n");
                break;
            case 'r':
                printf("/-----\\ \n");
                printf("|      \\\n");
                printf("| \\___/|\n");
                printf("|      \\\n");
                break;
            case 's':
                printf("  /----\\\n");
                printf(" /      \\\n");
                printf(" \\------/\n");
                printf("  \\----/ \n");
                break;
            case 't':
                printf(" ______\n");
                printf("|      |\n");
                printf("|      |\n");
                printf("|______|\n");
                break;
            case 'u':
                printf("|       |\n");
                printf("|       |\n");
                printf("|       |\n");
                printf(" \\-----/ \n");
                break;
            case 'v':
                printf("\\        /\n");
                printf(" \\      / \n");
                printf("  \\____/  \n");
                printf("   \\__/   \n");
                break;
            case 'w':
                printf("|         |\n");
                printf("|         |\n");
                printf("|  /\\ /\\  |\n");
                printf(" \\/  \\/   \n");
                break;
            case 'x':
                printf("\\    /\n");
                printf(" \\  / \n");
                printf("  \\/  \n");
                printf("  /\\  \n");
                break;
            case 'y':
                printf("\\     /\n");
                printf(" \\   / \n");
                printf("  \\_/  \n");
                printf("  ||   \n");
                break;
            case 'z':
                printf("\\-----/\n");
                printf("    /  \n");
                printf("  /    \n");
                printf("/-----\\\n");
                break;
            case ' ':
                printf("\n\n\n\n");
                break;
            case ',':
                printf("   ,\n");
                printf("  / \\\n");
                printf(" (_'\n");
                break;
            case '.':
                printf("   .\n");
                printf("     \n");
                printf("     \n");
                break;
            default:
                printf("Unknown character.\n");
        }
        printf("\n");
    }

    return 0;
}