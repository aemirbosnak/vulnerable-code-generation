//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the alien phrase to translate:\n");

    char alien_phrase[50];
    fgets(alien_phrase, 50, stdin);
    
    printf("Translating...\n");
    printf("Alien phrase: %s", alien_phrase);

    char english_translation[50] = "";

    for(int i=0; i<strlen(alien_phrase); i++) {
        char current_char = alien_phrase[i];
        if(current_char == '0') {
            strcat(english_translation, "a");
        }
        else if(current_char == '1') {
            strcat(english_translation, "b");
        }
        else if(current_char == '2') {
            strcat(english_translation, "c");
        }
        else if(current_char == '3') {
            strcat(english_translation, "d");
        }
        else if(current_char == '4') {
            strcat(english_translation, "e");
        }
        else if(current_char == '5') {
            strcat(english_translation, "f");
        }
        else if(current_char == '6') {
            strcat(english_translation, "g");
        }
        else if(current_char == '7') {
            strcat(english_translation, "h");
        }
        else if(current_char == '8') {
            strcat(english_translation, "i");
        }
        else if(current_char == '9') {
            strcat(english_translation, "j");
        }
        else {
            strcat(english_translation, current_char);
        }
    }

    printf("English translation: %s", english_translation);

    return 0;
}