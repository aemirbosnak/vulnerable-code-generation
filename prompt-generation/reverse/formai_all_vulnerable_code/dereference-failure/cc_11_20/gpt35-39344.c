//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate alien language 
char* translate(char* alienLanguage)
{
    int len = strlen(alienLanguage);
    char* english = malloc(len+1);
    int i;

    // Convert each character of alien language to English
    for(i=0; i<len; i++){
        char letter = alienLanguage[i];
        switch(letter){
            case 'm': english[i] = 'a'; break;
            case 'p': english[i] = 'b'; break;
            case 'l': english[i] = 'c'; break;
            case 'e': english[i] = 'd'; break;
            case 'o': english[i] = 'e'; break;
            case 'i': english[i] = 'f'; break;
            case 'a': english[i] = 'g'; break;
            case 'y': english[i] = 'h'; break;
            case 'q': english[i] = 'i'; break;
            case 'u': english[i] = 'j'; break;
            case 'r': english[i] = 'k'; break;
            case 'w': english[i] = 'l'; break;
            case 's': english[i] = 'm'; break;
            case 'd': english[i] = 'n'; break;
            case 'f': english[i] = 'o'; break;
            case 'g': english[i] = 'p'; break;
            case 'h': english[i] = 'q'; break;
            case 'j': english[i] = 'r'; break;
            case 'k': english[i] = 's'; break;
            case 'z': english[i] = 't'; break;
            case 'x': english[i] = 'u'; break;
            case 'c': english[i] = 'v'; break;
            case 'v': english[i] = 'w'; break;
            case 'b': english[i] = 'x'; break;
            case 'n': english[i] = 'y'; break;
            default: english[i] = letter;
        }
    }

    // Add null character at the end of string
    english[i] = '\0';
    
    // Return translated string
    return english;
}

int main(){
    char alienLanguage[100];
    printf("Enter the Alien Language to be translated: ");
    scanf("%s", &alienLanguage);
    char* english = translate(alienLanguage);
    printf("Your translated Alien Language is: %s\n", english);
    return 0;
}