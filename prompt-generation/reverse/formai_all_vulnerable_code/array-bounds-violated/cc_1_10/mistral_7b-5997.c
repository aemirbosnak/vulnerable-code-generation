//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ALPHABET_SIZE 23
#define ALIEN_SYMBOL_SIZE 10

char alien_alphabet[ALIEN_ALPHABET_SIZE];
int alien_digits[ALIEN_ALPHABET_SIZE];

void init_alien_alphabet() {
    for (int i = 0; i < ALIEN_ALPHABET_SIZE; i++) {
        alien_alphabet[i] = 'A' + i;
        alien_digits[i] = i;
    }
}

void translate_alien_to_human(const char *alien_text, char *human_text, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (isdigit(alien_text[i])) {
            human_text[i] = alien_alphabet[alien_digits[alien_text[i] - '0']];
        } else {
            human_text[i] = alien_text[i];
        }
    }
    human_text[length] = '\0';
}

void translate_human_to_alien(const char *human_text, char *alien_text, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (isalpha(human_text[i])) {
            alien_text[i] = alien_alphabet[alien_digits[human_text[i] - 'A']];
        } else {
            alien_text[i] = human_text[i];
        }
    }
    alien_text[length] = '\0';

    int base = 1;
    for (size_t i = length - 1; i >= 0 && base <= ALIEN_ALPHABET_SIZE; i--) {
        size_t digit = 0;
        int sum = 0;
        for (size_t j = i + 1; j < length; j++) {
            sum += alien_digits[alien_text[j] - 'A'] * base;
            base *= ALIEN_ALPHABET_SIZE;
        }
        alien_text[i] = alien_alphabet[sum % ALIEN_ALPHABET_SIZE];
        base /= ALIEN_ALPHABET_SIZE;
    }
}

int main() {
    init_alien_alphabet();

    char alien_text[] = "1Z2A3B4C5D6E7F8G9H0M";
    char human_text[ALIEN_ALPHABET_SIZE * 2];

    translate_alien_to_human(alien_text, human_text, sizeof(alien_text));
    printf("Alien text: %s\n", alien_text);
    printf("Human text: %s\n", human_text);

    char translated_alien_text[ALIEN_ALPHABET_SIZE * 2];

    translate_human_to_alien(human_text, translated_alien_text, sizeof(human_text));
    printf("Human text: %s\n", human_text);
    printf("Translated alien text: %s\n", translated_alien_text);

    return 0;
}