//Code Llama-13B DATASET v1.0 Category: Cat Language Translator ; Style: retro
/*
 *  C Cat Language Translator
 *  Retro Style
 *
 *  Written by @Coder_Rahul
 *
 *  Version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert input string to purr language
void purr(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') {
            printf("r");
        } else if (str[i] == 'e') {
            printf("w");
        } else if (str[i] == 'i') {
            printf("h");
        } else if (str[i] == 'o') {
            printf("r");
        } else if (str[i] == 'u') {
            printf("w");
        } else {
            printf("%c", str[i]);
        }
    }
}

// Function to convert input string to meow language
void meow(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') {
            printf("m");
        } else if (str[i] == 'e') {
            printf("w");
        } else if (str[i] == 'i') {
            printf("h");
        } else if (str[i] == 'o') {
            printf("w");
        } else if (str[i] == 'u') {
            printf("r");
        } else {
            printf("%c", str[i]);
        }
    }
}

// Function to convert input string to purr and meow language
void purrMeow(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') {
            printf("r");
        } else if (str[i] == 'e') {
            printf("w");
        } else if (str[i] == 'i') {
            printf("h");
        } else if (str[i] == 'o') {
            printf("r");
        } else if (str[i] == 'u') {
            printf("w");
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') {
            printf("m");
        } else if (str[i] == 'e') {
            printf("w");
        } else if (str[i] == 'i') {
            printf("h");
        } else if (str[i] == 'o') {
            printf("w");
        } else if (str[i] == 'u') {
            printf("r");
        } else {
            printf("%c", str[i]);
        }
    }
}

// Main function
int main() {
    char str[100];
    printf("Enter a sentence: ");
    scanf("%s", str);
    purr(str);
    printf("\n");
    meow(str);
    printf("\n");
    purrMeow(str);
    return 0;
}