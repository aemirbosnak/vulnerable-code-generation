//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to translate English to Alien language
void translate(char* english_word, char* alien_word) {
    int length = strlen(english_word);

    // Base case: if the English word is a single character,
    // translate it to the corresponding Alien character
    if (length == 1) {
        switch (english_word[0]) {
            case 'a':
            case 'A':
                strcpy(alien_word, "zog");
                break;
            case 'b':
            case 'B':
                strcpy(alien_word, "plugh");
                break;
            case 'c':
            case 'C':
                strcpy(alien_word, "xyzzy");
                break;
            default:
                strcpy(alien_word, "");
        }
        return;
    }

    // Recursive case: divide the English word into two halves
    // and recursively translate each half
    char* first_half = malloc(MAX_WORD_LENGTH);
    char* second_half = malloc(MAX_WORD_LENGTH);
    int half_length = length / 2;

    strncpy(first_half, english_word, half_length);
    first_half[half_length] = '\0';

    strncpy(second_half, english_word + half_length, length - half_length);
    second_half[length - half_length] = '\0';

    translate(first_half, alien_word);
    translate(second_half, alien_word + strlen(alien_word));

    free(first_half);
    free(second_half);
}

int main() {
    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];

    printf("Enter an English word to translate: ");
    scanf("%s", english_word);

    translate(english_word, alien_word);

    printf("Alien translation: %s\n", alien_word);

    return 0;
}