//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_ALPHABET_SIZE 26
#define ENGLISH_ALPHABET_SIZE 26

typedef struct alien_alphabet {
    char english_letter;
    char alien_letter;
} alien_alphabet;

alien_alphabet alien_alphabet_table[ALIEN_ALPHABET_SIZE] = {
    {'A', 'Q'}, {'B', 'W'}, {'C', 'E'}, {'D', 'R'}, {'E', 'T'}, {'F', 'Y'},
    {'G', 'U'}, {'H', 'I'}, {'I', 'O'}, {'J', 'P'}, {'K', 'A'}, {'L', 'S'},
    {'M', 'D'}, {'N', 'F'}, {'O', 'G'}, {'P', 'H'}, {'Q', 'L'}, {'R', 'Z'},
    {'S', 'X'}, {'T', 'C'}, {'U', 'K'}, {'V', 'J'}, {'W', 'V'}, {'X', 'N'},
    {'Y', 'M'}, {'Z', 'B'}, {' ', ' '}
};

void translate_english_to_alien(const char *english, char *alien, int length) {
    for (int i = 0; i < length; ++i) {
        int index = (int)english[i] - 65;
        if (index < 0 || index > ENGLISH_ALPHABET_SIZE) {
            alien[i] = english[i];
            continue;
        }
        alien[i] = alien_alphabet_table[index].alien_letter;
    }
}

void print_alien_phrase(const char *alien) {
    for (int i = 0; alien[i] != '\0'; ++i) {
        putchar(alien[i]);
    }
    putchar('\n');
}

int main() {
    char input[100];
    char output[100];

    printf("Enter an English phrase: ");
    scanf("%s", input);

    int length = strlen(input);
    translate_english_to_alien(input, output, length);

    printf("Alien translation: ");
    print_alien_phrase(output);

    return 0;
}