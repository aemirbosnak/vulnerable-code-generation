//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char catLanguage[MAX_LENGTH];
    int i, j, len;
    char input[MAX_LENGTH];

    printf("Enter a word to translate: ");
    scanf("%s", input);

    // Remove any leading/trailing whitespaces
    input[strcspn(input, " \t\n\r")] = '\0';

    // Convert the word to uppercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Translate the word to C Cat Language
    for (i = 0, len = strlen(input); i < len; i++) {
        switch (input[i]) {
            case 'A':
                catLanguage[i] = 'A';
                break;
            case 'B':
                catLanguage[i] = 'B';
                break;
            case 'C':
                catLanguage[i] = 'C';
                break;
            case 'D':
                catLanguage[i] = 'D';
                break;
            case 'E':
                catLanguage[i] = 'E';
                break;
            case 'F':
                catLanguage[i] = 'F';
                break;
            case 'G':
                catLanguage[i] = 'G';
                break;
            case 'H':
                catLanguage[i] = 'H';
                break;
            case 'I':
                catLanguage[i] = 'I';
                break;
            case 'J':
                catLanguage[i] = 'J';
                break;
            case 'K':
                catLanguage[i] = 'K';
                break;
            case 'L':
                catLanguage[i] = 'L';
                break;
            case 'M':
                catLanguage[i] = 'M';
                break;
            case 'N':
                catLanguage[i] = 'N';
                break;
            case 'O':
                catLanguage[i] = 'O';
                break;
            case 'P':
                catLanguage[i] = 'P';
                break;
            case 'Q':
                catLanguage[i] = 'Q';
                break;
            case 'R':
                catLanguage[i] = 'R';
                break;
            case 'S':
                catLanguage[i] = 'S';
                break;
            case 'T':
                catLanguage[i] = 'T';
                break;
            case 'U':
                catLanguage[i] = 'U';
                break;
            case 'V':
                catLanguage[i] = 'V';
                break;
            case 'W':
                catLanguage[i] = 'W';
                break;
            case 'X':
                catLanguage[i] = 'X';
                break;
            case 'Y':
                catLanguage[i] = 'Y';
                break;
            case 'Z':
                catLanguage[i] = 'Z';
                break;
            default:
                catLanguage[i] = 'A';
                break;
        }
    }

    catLanguage[strlen(catLanguage)] = '\0';

    printf("The translated word in C Cat Language is: %s\n", catLanguage);

    return 0;
}