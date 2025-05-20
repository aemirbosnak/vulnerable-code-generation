//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to translate English to Alien language
void translateToAlien(char *input) {
    char *vowels = "aeiouAEIOU";
    char *alienVowels = "zrtylpZRTYLP";
    char *consonants = "bcdfghjklmnpqrstvwxBCDFGHJKLMNPQRSTVWX";
    char *alienConsonants = "bcdfghjklmnpqrstvwxBCDFGHJKLMNPQRSTVWX";
    int len = strlen(input);
    char *output = malloc(len + 1);
    strcpy(output, "");
    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            if (strchr(vowels, tolower(input[i]))) {
                char alienVowel = alienVowels[rand() % strlen(alienVowels)];
                sprintf(&output[strlen(output)], "%c", alienVowel);
            } else {
                char alienConsonant = alienConsonants[rand() % strlen(alienConsonants)];
                sprintf(&output[strlen(output)], "%c", alienConsonant);
            }
        } else {
            sprintf(&output[strlen(output)], "%c", input[i]);
        }
    }
    printf("Alien translation: %s\n", output);
}

int main() {
    srand(time(NULL));
    char input[100];
    printf("Enter a sentence to translate to Alien language: ");
    fgets(input, 100, stdin);
    reverseString(input);
    translateToAlien(input);
    return 0;
}