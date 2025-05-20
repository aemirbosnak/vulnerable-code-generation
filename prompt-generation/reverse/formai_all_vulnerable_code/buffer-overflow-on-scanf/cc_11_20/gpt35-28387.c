//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <string.h>

void printLetter(char letter, int row);
void printWord(char *word);

int main()
{
    char userInput[50];
    
    printf("Enter a word or phrase to convert to ASCII art:\n");
    scanf("%s", userInput);

    for (int row = 1; row <= 7; row++) {
        for (int i = 0; i < strlen(userInput); i++) {
            printLetter(userInput[i], row);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}

void printLetter(char letter, int row) {
    switch (letter) {
        case 'A':
            printf("  ##  ");
            break;
        case 'B':
            printf("####  ");
            break;
        case 'C':
            printf("##### ");
            break;
        case 'D':
            printf("####  ");
            break;
        case 'E':
            printf("##### ");
            break;
        case 'F':
            printf("##### ");
            break;
        case 'G':
            printf("##### ");
            break;
        case 'H':
            printf("#  #  ");
            break;
        case 'I':
            printf("##### ");
            break;
        case 'J':
            printf("    # ");
            break;
        case 'K':
            printf("#   # ");
            break;
        case 'L':
            printf("#     ");
            break;
        case 'M':
            printf("#    #");
            break;
        case 'N':
            printf("# # # ");
            break;
        case 'O':
            printf("##### ");
            break;
        case 'P':
            printf("####  ");
            break;
        case 'Q':
            printf("##### ");
            break;
        case 'R':
            printf("####  ");
            break;
        case 'S':
            printf("##### ");
            break;
        case 'T':
            printf("##### ");
            break;
        case 'U':
            printf("#   # ");
            break;
        case 'V':
            printf("#   # ");
            break;
        case 'W':
            printf("#   # ");
            break;
        case 'X':
            printf("#   # ");
            break;
        case 'Y':
            printf("#   # ");
            break;
        case 'Z':
            printf("##### ");
            break;
        case ' ':
            for (int i = 0; i < 6; i++) {
                printf(" ");
            }
            break;
        default:
            printf(" ");
            break;
    }
}

void printWord(char *word) {
    for (int row = 1; row <= 7; row++) {
        for (int i = 0; i < strlen(word); i++) {
            printLetter(word[i], row);
            printf(" ");
        }
        printf("\n");
    }
}