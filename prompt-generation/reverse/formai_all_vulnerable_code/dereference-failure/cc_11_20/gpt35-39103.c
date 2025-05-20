//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alienLanguageTranslator(char* alienLanguageCode) {
    char* englishTranslation = malloc(strlen(alienLanguageCode) * sizeof(char));
    int i;
    for (i = 0; alienLanguageCode[i] != '\0'; i++) {
        switch (alienLanguageCode[i]) {
            case 'k':
                englishTranslation[i] = 'a';
                break;
            case 'p':
                englishTranslation[i] = 'b';
                break;
            case 'r':
                englishTranslation[i] = 'c';
                break;
            case 'j':
                englishTranslation[i] = 'd';
                break;
            case 'f':
                englishTranslation[i] = 'e';
                break;
            case 'e':
                englishTranslation[i] = 'f';
                break;
            case 'w':
                englishTranslation[i] = 'g';
                break;
            case 'l':
                englishTranslation[i] = 'h';
                break;
            case 't':
                englishTranslation[i] = 'i';
                break;
            case 'o':
                englishTranslation[i] = 'j';
                break;
            case 'g':
                englishTranslation[i] = 'k';
                break;
            case 'h':
                englishTranslation[i] = 'l';
                break;
            case 'a':
                englishTranslation[i] = 'm';
                break;
            case 'q':
                englishTranslation[i] = 'n';
                break;
            case 'x':
                englishTranslation[i] = 'o';
                break;
            case 's':
                englishTranslation[i] = 'p';
                break;
            case 'u':
                englishTranslation[i] = 'q';
                break;
            case 'z':
                englishTranslation[i] = 'r';
                break;
            case 'y':
                englishTranslation[i] = 's';
                break;
            case 'd':
                englishTranslation[i] = 't';
                break;
            case 'm':
                englishTranslation[i] = 'u';
                break;
            case 'c':
                englishTranslation[i] = 'v';
                break;
            case 'v':
                englishTranslation[i] = 'w';
                break;
            case 'b':
                englishTranslation[i] = 'x';
                break;
            case 'n':
                englishTranslation[i] = 'y';
                break;
            case 'i':
                englishTranslation[i] = 'z';
                break;
            case ' ':
                englishTranslation[i] = ' ';
                break;
            default:
                printf("Invalid character received: %c\n", alienLanguageCode[i]);
                exit(EXIT_FAILURE);
        }
    }
    englishTranslation[i+1] = '\0';

    return englishTranslation;
}

int main() {
    char alienCode[200];

    printf("Please enter the alien language code:\n");
    fgets(alienCode, 200, stdin);

    char* englishTranslation = alienLanguageTranslator(alienCode);

    printf("English Translation: %s\n", englishTranslation);

    free(englishTranslation);

    return 0;
}