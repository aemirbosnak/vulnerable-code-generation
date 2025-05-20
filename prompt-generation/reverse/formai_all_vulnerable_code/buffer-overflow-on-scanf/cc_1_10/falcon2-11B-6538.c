//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    char alienLanguage[100];
    int length = 0;

    printf("Enter the alien language to be translated: ");
    scanf("%[^ ]", alienLanguage);

    length = strlen(alienLanguage);

    if (length == 0) {
        printf("Invalid alien language\n");
        return 1;
    }

    char translatedLanguage[length];
    char translatedLetter[length];

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < length) {
        if (j < 26) {
            translatedLetter[i] = 'A';
            translatedLetter[i] += j;
            i++;
            j++;
        } else {
            translatedLetter[i] = 'a';
            translatedLetter[i] += j;
            j = 0;
            i++;
        }
    }

    for (i = 0; i < length; i++) {
        if (alienLanguage[i] == translatedLetter[i]) {
            translatedLanguage[k] = alienLanguage[i];
            k++;
        } else {
            translatedLanguage[k] = translatedLetter[i];
            k++;
        }
    }

    translatedLanguage[k] = '\0';

    printf("Translated language: %s\n", translatedLanguage);

    return 0;
}