//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void alienTranslator(char *alienLang, int alienLangLength) {
    char *english;
    int englishIndex = 0;
    int charCount = 1;
    int i;
    int j;

    for(i = 0; i < alienLangLength; i++) {
        for(j = i + 1; j < alienLangLength; j++) {
            if(alienLang[i] != alienLang[j]) {
                break;
            }

            charCount++;
        }

        if(charCount == 1) {
            english = "a";
        } else if(charCount == 2) {
            english = "b";
        } else if(charCount == 3) {
            english = "c";
        } else if(charCount == 4) {
            english = "d";
        } else if(charCount == 5) {
            english = "e";
        } else if(charCount == 6) {
            english = "f";
        } else if(charCount == 7) {
            english = "g";
        } else if(charCount == 8) {
            english = "h";
        } else if(charCount == 9) {
            english = "i";
        } else if(charCount == 10) {
            english = "j";
        } else if(charCount == 11) {
            english = "k";
        } else if(charCount == 12) {
            english = "l";
        } else if(charCount == 13) {
            english = "m";
        } else if(charCount == 14) {
            english = "n";
        } else if(charCount == 15) {
            english = "o";
        } else if(charCount == 16) {
            english = "p";
        } else if(charCount == 17) {
            english = "q";
        } else if(charCount == 18) {
            english = "r";
        } else if(charCount == 19) {
            english = "s";
        } else if(charCount == 20) {
            english = "t";
        } else if(charCount == 21) {
            english = "u";
        } else if(charCount == 22) {
            english = "v";
        } else if(charCount == 23) {
            english = "w";
        } else if(charCount == 24) {
            english = "x";
        } else if(charCount == 25) {
            english = "y";
        } else if(charCount == 26) {
            english = "z";
        }

        printf("%s", english);

        i = j - 1;
        charCount = 1;
    }

    printf("\n");
}

int main() {
    char alienLang[100];
    int alienLangLength;

    printf("Enter the Alien Language: ");
    scanf("%s", &alienLang);

    alienLangLength = strlen(alienLang);

    alienTranslator(alienLang, alienLangLength);

    return 0;
}