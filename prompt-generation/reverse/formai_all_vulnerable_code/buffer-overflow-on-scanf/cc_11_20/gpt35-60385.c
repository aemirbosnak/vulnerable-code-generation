//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

char paranoid[MAX_LENGTH] = "PARANOID";

void print_ascii_art(char c) {
    switch(c) {
        case 'A':
            printf("  /\\   \n /  \\  \n/----\\ \n/      \\\n");
            break;
        case 'B':
            printf("------\\\n|     _/\n|___  \\\n     \\_/\n");
            break;
        case 'C':
            printf("  /----\n /     \n|      \n \\----\\\n");
            break;
        case 'D':
            printf("-----\\\n|     \\\n|      \\\n\\______/\n");
            break;
        case 'E':
            printf("------\n|      \n|___   \n------\n");
            break;
        case 'F':
            printf("------\n|      \n|___   \n|      \n");
            break;
        case 'G':
            printf("  /----\n /     \n|       \n\\-----\\\n");
            break;
        case 'H':
            printf("/      \\\n|------|\n|      |\n\\      /\n");
            break;
        case 'I':
            printf("------\n  ||  \n  ||  \n------\n");
            break;
        case 'J':
            printf("      /\\\n     /  \\\n|___/    \n \\__/\\\n");
            break;
        case 'K':
            printf("/    \\ \n|___/  \\\n| \\    /\n\\_/\\_/\n");
            break;
        case 'L':
            printf("|      \n|      \n|___   \n------\n");
            break;
        case 'M':
            printf("/\\    /\\\n|  \\  /  |\n|  |\\/|  |\n\\_/    \\_/\n");
            break;
        case 'N':
            printf("/\\    |\n|  \\   |\n|  |\\  |\n\\_/ \\_/\n");
            break;
        case 'O':
            printf("  /\\   \n /  \\  \n|    | \n \\__/  \n");
            break;
        case 'P':
            printf("-----\\\n|     \\\n|___   \n|      \n");
            break;
        case 'Q':
            printf("  /\\   \n /  \\  \n|    | \n \\__X_/\n");
            break;
        case 'R':
            printf("-----\\\n|     \\\n|___   \\\n|     \\\n");
            break;
        case 'S':
            printf(" ______\n/-----\\\n\\     \n \\-----\\\n");
            break;
        case 'T':
            printf("------\n  ||  \n  ||  \n  ||  \n");
            break;
        case 'U':
            printf("/     \\\n|      |\n|      |\n\\______/\n");
            break;
        case 'V':
            printf("/      \\\n|      |\n \\    / \n  \\__/  \n");
            break;
        case 'W':
            printf("/\\    /\\    /\\\n|  |  |  |  |  |\n|  |/\\|  |/\\|  |\n\\_/    \\_/    \\_/\n");
            break;
        case 'X':
            printf("\\    /\n \\  / \n  \\/  \n /  \\ \n/    \\\n");
            break;
        case 'Y':
            printf("\\     /\n \\   / \n  ||   \n  ||   \n  ||   \n");
            break;
        case 'Z':
            printf("------\n    /  \n  /    \n/------\n");
            break;
        default:
            printf("       \n       \n       \n       \n");
    }
}

void to_uppercase(char str[]) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a word to convert to ASCII art: ");
    scanf("%s", input);

    to_uppercase(input);

    int i = 0;
    while (input[i]) {
        char c = input[i];
        if (!isalpha(c)) {
            printf("Invalid character in input!\n");
            return EXIT_FAILURE;
        }
        print_ascii_art(c);
        i++;
    }

    printf("\nPARANOID level: %d\n", strlen(input));

    if (strcmp(input, paranoid) == 0) {
        printf("We are being watched!\n");
    } else {
        printf("We are safe for now.\n");
    }

    return EXIT_SUCCESS;
}