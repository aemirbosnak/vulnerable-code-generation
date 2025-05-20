//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* ToCatLanguage(char* englishStr){
    char* catLanguage = malloc(strlen(englishStr) * 5);
    //Memory Allocation
    int catIndex = 0;
    for(int i=0; i < strlen(englishStr); i++){
        switch(englishStr[i]){
            //For vowels
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            //For double letters
            case 'b':
            case 'c':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                catLanguage[catIndex] = englishStr[i];
                catIndex++;
                break;
            //For consonants
            default:
                catLanguage[catIndex] = englishStr[i];
                catIndex++;
                catLanguage[catIndex] = 'a';
                catIndex++;
                catLanguage[catIndex] = englishStr[i];
                catIndex++;
                break;
        }
    }
    catLanguage[catIndex] = '\0';
    return catLanguage;
}

int main(){
    char englishString[100];
    printf("Enter an English word or sentence: ");
    fgets(englishString, 100, stdin);
    englishString[strlen(englishString) - 1] = '\0';
    //Remove new line character
    char* catLanguage = ToCatLanguage(englishString);
    printf("\nCat Language Translation: %s", catLanguage);
    free(catLanguage);
    return 0;
}