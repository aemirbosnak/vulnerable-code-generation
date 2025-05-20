//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

char* translateAlienLanguage(char alienText[]) {
    char translatedText[MAX_STRING_LENGTH];
    int i, j;
    for(i = 0, j = 0; i < strlen(alienText); i++, j++) {
        if(alienText[i] == 'c') {
            if(i+1 < strlen(alienText) && alienText[i+1] == 'x') {
                translatedText[j] = 'a';
                i++;
            } else if(i+1 < strlen(alienText) && alienText[i+1] == 'q') {
                translatedText[j] = 'e';
                i++;
            } else {
                translatedText[j] = alienText[i];
            }
        } else if(alienText[i] == 'd') {
            if(i+1 < strlen(alienText) && alienText[i+1] == 't') {
                translatedText[j] = 'u';
                i++;
            } else if(i+1 < strlen(alienText) && alienText[i+1] == 'o') {
                translatedText[j] = 'i';
                i++;
            } else {
                translatedText[j] = alienText[i];
            }
        } else if(alienText[i] == 'h') {
            if(i+1 < strlen(alienText) && alienText[i+1] == 'f') {
                translatedText[j] = 'o';
                i++;
            } else if(i+1 < strlen(alienText) && alienText[i+1] == 'n') {
                translatedText[j] = 's';
                i++;
            } else {
                translatedText[j] = alienText[i];
            }
        } else {
            translatedText[j] = alienText[i];
        }
    }
    return strdup(translatedText);
}

int main() {
    char alienText[MAX_STRING_LENGTH];
    printf("Enter the alien language text: ");
    fgets(alienText, MAX_STRING_LENGTH, stdin);
    alienText[strlen(alienText)-1] = '\0';
    char* translatedText = translateAlienLanguage(alienText);
    printf("Translated text: %s\n", translatedText);
    free(translatedText);
    return 0;
}