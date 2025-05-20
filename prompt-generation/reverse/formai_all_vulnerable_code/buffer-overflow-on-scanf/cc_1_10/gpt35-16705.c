//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

// Function to check if a given character is an alien character
int isAlien(char c, char alienChars[], int alienCharsSize){
    int i;
    for(i=0; i<alienCharsSize; i++){
        if(alienChars[i] == c){
            return 1; // The character is an alien character
        }
    }
    return 0; // The character is not an alien character
}

// Function to translate a given alien word to English
void alienToEnglish(char *alienWord, char alienChars[], char *englishWord){
    int i, j, k, len, alienCharsSize;
    char mapping[26][2] = { // Mapping of alien characters to English characters
        {'a', 'e'},
        {'b', 't'},
        {'c', 'h'},
        {'d', 'o'},
        {'e', 'a'},
        {'f', 's'},
        {'g', 'n'},
        {'h', 'c'},
        {'i', 'r'},
        {'j', 'u'},
        {'k', 'y'},
        {'l', 'm'},
        {'m', 'l'},
        {'n', 'g'},
        {'o', 'd'},
        {'p', 'i'},
        {'q', 'j'},
        {'r', 'i'},
        {'s', 'f'},
        {'t', 'b'},
        {'u', 'j'},
        {'v', 'p'},
        {'w', 'z'},
        {'x', 'q'},
        {'y', 'k'},
        {'z', 'w'}
    };
    len = strlen(alienWord);
    alienCharsSize = strlen(alienChars);
    for(i=0; i<len; i++){
        if(isAlien(alienWord[i], alienChars, alienCharsSize)){
            // The character is an alien character, so find the corresponding English character
            for(j=0; j<26; j++){
                if(mapping[j][0] == alienWord[i]){
                    // Found the corresponding English character
                    englishWord[i] = mapping[j][1];
                    break;
                }
            }
        } else {
            // The character is an English character, so copy it to the English word
            englishWord[i] = alienWord[i];
        }
    }
    englishWord[i] = '\0'; // Add the null terminator at the end of the English word
}

int main(){
    char alienWord[100], alienChars[10];
    char englishWord[100];
    printf("Enter an alien word: ");
    scanf("%s", alienWord);
    printf("Enter the list of alien characters: ");
    scanf("%s", alienChars);
    alienToEnglish(alienWord, alienChars, englishWord);
    printf("The English word is: %s\n", englishWord);
    return 0;
}