//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
    char *ascii_art = malloc(9);
    switch (c) {
        case 'A':
            strcpy(ascii_art, " __ \n|  |\n|  |");
            break;
        case 'B':
            strcpy(ascii_art, " __ \n|__|\n|__|");
            break;
        case 'C':
            strcpy(ascii_art, " ___ \n|__  |\n|_| |");
            break;
        case 'D':
            strcpy(ascii_art, " __ \n|  |\n|__|");
            break;
        case 'E':
            strcpy(ascii_art, "__  \n|  | \n|__| ");
            break;
        case 'F':
            strcpy(ascii_art, "__  \n|  | \n|  | ");
            break;
        case 'G':
            strcpy(ascii_art, " ___ \n|__  |\n|__| |");
            break;
        case 'H':
            strcpy(ascii_art, " _  _\n| |_| |\n|  _  |");
            break;
        case 'I':
            strcpy(ascii_art, "   \n _ \n| |");
            break;
        case 'J':
            strcpy(ascii_art, "   \n _ \n| |");
            break;
        case 'K':
            strcpy(ascii_art, " __ \n|  |\n|_| \\");
            break;
        case 'L':
            strcpy(ascii_art, "__  \n|  | \n|__| ");
            break;
        case 'M':
            strcpy(ascii_art, " _  _  \n| || | \n| || |");
            break;
        case 'N':
            strcpy(ascii_art, " _  _ \n| || | \n|_||_|");
            break;
        case 'O':
            strcpy(ascii_art, " ___ \n|__  |\n|__| |");
            break;
        case 'P':
            strcpy(ascii_art, " __ \n|  |\n|_| \\");
            break;
        case 'Q':
            strcpy(ascii_art, " ___ \n|__  |\n|__| |");
            break;
        case 'R':
            strcpy(ascii_art, " __ \n|  |\n|_|_\\");
            break;
        case 'S':
            strcpy(ascii_art, " ___ \n|__  |\n _| |");
            break;
        case 'T':
            strcpy(ascii_art, " __ \n|  |\n|  |");
            break;
        case 'U':
            strcpy(ascii_art, " _  _ \n| || | \n| || |");
            break;
        case 'V':
            strcpy(ascii_art, "   \n  _\n /_\\");
            break;
        case 'W':
            strcpy(ascii_art, " _  _  \n| || | \n|_||_|");
            break;
        case 'X':
            strcpy(ascii_art, " __ \n/  \\ \n\\__/ ");
            break;
        case 'Y':
            strcpy(ascii_art, " __ \n|  |\n \\/ ");
            break;
        case 'Z':
            strcpy(ascii_art, " ___ \n|__ \\ \n|_|  \\");
            break;
        default:
            strcpy(ascii_art, "X");
            break;
    }
    return ascii_art;
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
    int len = strlen(str);
    char *ascii_art = malloc(9 * len + 1);
    for (int i = 0; i < len; i++) {
        strcat(ascii_art, char_to_ascii(str[i]));
    }
    return ascii_art;
}

// Function to print a string in ASCII art
void print_ascii(char *str) {
    char *ascii_art = string_to_ascii(str);
    printf("%s\n", ascii_art);
    free(ascii_art);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    print_ascii(str);
    return 0;
}