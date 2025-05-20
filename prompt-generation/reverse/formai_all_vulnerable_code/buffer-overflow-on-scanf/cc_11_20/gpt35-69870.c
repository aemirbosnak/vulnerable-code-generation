//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_TRANSLATED_LENGTH 50

void translate(char* word, char* translation) {
    int length = strlen(word);
    for(int i=0; i<length; i++) {
        if(word[i] < 'a' || word[i] > 'z') {
            printf("Invalid character found in word: %c\n", word[i]);
            exit(1);
        }
    }
    memset(translation, 0, MAX_TRANSLATED_LENGTH);
    for(int i=length-1, j=0; i>=0; i--, j++) {
        if(word[i] == 'a') {
            translation[j] = 't';
        } else if(word[i] == 'b') {
            translation[j] = 'g';
        } else if(word[i] == 'c') {
            translation[j] = 'w';
        } else if(word[i] == 'd') {
            translation[j] = 'r';
        } else if(word[i] == 'e') {
            translation[j] = 'u';
        } else if(word[i] == 'f') {
            translation[j] = 'q';
        } else if(word[i] == 'g') {
            translation[j] = 'a';
        } else if(word[i] == 'h') {
            translation[j] = 'f';
        } else if(word[i] == 'i') {
            translation[j] = 'b';
        } else if(word[i] == 'j') {
            translation[j] = 'c';
        } else if(word[i] == 'k') {
            translation[j] = 'd';
        } else if(word[i] == 'l') {
            translation[j] = 'e';
        } else if(word[i] == 'm') {
            translation[j] = 'h';
        } else if(word[i] == 'n') {
            translation[j] = 's';
        } else if(word[i] == 'o') {
            translation[j] = 'i';
        } else if(word[i] == 'p') {
            translation[j] = 'j';
        } else if(word[i] == 'q') {
            translation[j] = 'k';
        } else if(word[i] == 'r') {
            translation[j] = 'l';
        } else if(word[i] == 's') {
            translation[j] = 'm';
        } else if(word[i] == 't') {
            translation[j] = 'n';
        } else if(word[i] == 'u') {
            translation[j] = 'o';
        } else if(word[i] == 'v') {
            translation[j] = 'p';
        } else if(word[i] == 'w') {
            translation[j] = 'e';
        } else if(word[i] == 'x') {
            translation[j] = 'v';
        } else if(word[i] == 'y') {
            translation[j] = 'x';
        } else if(word[i] == 'z') {
            translation[j] = 'y';
        }
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    char translation[MAX_TRANSLATED_LENGTH];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter a word to translate: ");
    scanf("%s", input);
    translate(input, translation);
    printf("The translation of '%s' is '%s'\n", input, translation);
    printf("Be careful! The aliens are always watching us.\n");
    printf("Do not attempt to communicate with them unless you are authorized.\n");
    printf("Have a nice day!\n");
    return 0;
}