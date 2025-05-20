//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <string.h>

// Constants for alien language translation
#define VOWELS "aeiouy"
#define CONSONANTS "bcdfghjklmnpqrstvwxz"

// Function to check if a character is a vowel
int isVowel(char c) {
    int i;
    for(i=0; i<strlen(VOWELS); i++) {
        if(c == VOWELS[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is a consonant
int isConsonant(char c) {
    int i;
    for(i=0; i<strlen(CONSONANTS); i++) {
        if(c == CONSONANTS[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to translate a string from alien language to English
void translateToEnglish(char str[]) {
    int i, len;
    len = strlen(str);

    // Loop through each character in the string
    for(i=0; i<len; i++) {
        if(isVowel(str[i])) {
            // If the character is a vowel, print the last consonant
            int j = i-1;
            while(j>=0 && !isConsonant(str[j])) {
                j--;
            }
            if(j >= 0) {
                printf("%c", str[j]);
            }
        } else if(isConsonant(str[i])) {
            // If the character is a consonant, print the next vowel
            int j = i+1;
            while(j<len && !isVowel(str[j])) {
                j++;
            }
            if(j < len) {
                printf("%c", str[j]);
            }
        } else {
            // If the character is neither a vowel nor a consonant, print it as is
            printf("%c", str[i]);
        }
    }

    printf("\n");
}

// Main function to test the translator
int main() {
    char str[100];

    // Prompt the user to input the alien language string
    printf("Enter an alien language string: ");
    fgets(str, 100, stdin);

    // Remove the trailing newline character from the input string
    str[strlen(str)-1] = '\0';

    // Translate the string to English and print the result
    printf("Translated to English: ");
    translateToEnglish(str);

    return 0;
}