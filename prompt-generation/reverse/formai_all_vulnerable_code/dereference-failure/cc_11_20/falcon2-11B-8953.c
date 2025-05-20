//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate alien language to English
void translateAlienLanguage(char* alienLanguage) {
    int len = strlen(alienLanguage);
    char* englishTranslation = malloc(len * sizeof(char));

    for (int i = 0; i < len; i++) {
        if (alienLanguage[i] == 'a') {
            englishTranslation[i] = 'A';
        } else if (alienLanguage[i] == 'b') {
            englishTranslation[i] = 'B';
        } else if (alienLanguage[i] == 'c') {
            englishTranslation[i] = 'C';
        } else if (alienLanguage[i] == 'd') {
            englishTranslation[i] = 'D';
        } else if (alienLanguage[i] == 'e') {
            englishTranslation[i] = 'E';
        } else if (alienLanguage[i] == 'f') {
            englishTranslation[i] = 'F';
        } else if (alienLanguage[i] == 'g') {
            englishTranslation[i] = 'G';
        } else if (alienLanguage[i] == 'h') {
            englishTranslation[i] = 'H';
        } else if (alienLanguage[i] == 'i') {
            englishTranslation[i] = 'I';
        } else if (alienLanguage[i] == 'j') {
            englishTranslation[i] = 'J';
        } else if (alienLanguage[i] == 'k') {
            englishTranslation[i] = 'K';
        } else if (alienLanguage[i] == 'l') {
            englishTranslation[i] = 'L';
        } else if (alienLanguage[i] =='m') {
            englishTranslation[i] = 'M';
        } else if (alienLanguage[i] == 'n') {
            englishTranslation[i] = 'N';
        } else if (alienLanguage[i] == 'o') {
            englishTranslation[i] = 'O';
        } else if (alienLanguage[i] == 'p') {
            englishTranslation[i] = 'P';
        } else if (alienLanguage[i] == 'q') {
            englishTranslation[i] = 'Q';
        } else if (alienLanguage[i] == 'r') {
            englishTranslation[i] = 'R';
        } else if (alienLanguage[i] =='s') {
            englishTranslation[i] = 'S';
        } else if (alienLanguage[i] == 't') {
            englishTranslation[i] = 'T';
        } else if (alienLanguage[i] == 'u') {
            englishTranslation[i] = 'U';
        } else if (alienLanguage[i] == 'v') {
            englishTranslation[i] = 'V';
        } else if (alienLanguage[i] == 'w') {
            englishTranslation[i] = 'W';
        } else if (alienLanguage[i] == 'x') {
            englishTranslation[i] = 'X';
        } else if (alienLanguage[i] == 'y') {
            englishTranslation[i] = 'Y';
        } else if (alienLanguage[i] == 'z') {
            englishTranslation[i] = 'Z';
        }
    }

    printf("%s\n", englishTranslation);
    free(englishTranslation);
}

int main() {
    char alienLanguage[] = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    translateAlienLanguage(alienLanguage);
    return 0;
}