//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ALPHABET_SIZE 26

char alien_alphabet[ALIEN_ALPHABET_SIZE] = {'&', '*', '+', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int get_alien_index(char symbol) {
    for (int i = 0; i < ALIEN_ALPHABET_SIZE; ++i) {
        if (alien_alphabet[i] == symbol) {
            return i;
        }
    }

    return -1;
}

void translate(const char* source, char* destination) {
    int source_length = strlen(source);
    int destination_length = 0;

    for (int i = 0; i < source_length; ++i) {
        int source_symbol_index = get_alien_index(source[i]);
        int destination_symbol_index;

        if (isalpha(source[i])) {
            destination_symbol_index = source_symbol_index + 3;

            if (destination_symbol_index > ALIEN_ALPHABET_SIZE - 1) {
                destination_symbol_index -= ALIEN_ALPHABET_SIZE;
            }

            destination[destination_length++] = alien_alphabet[destination_symbol_index];
        } else {
            destination[destination_length++] = source[i];
        }
    }

    destination[destination_length] = '\0';
}

int main() {
    char source[100], destination[100];

    printf("Enter English text: ");
    scanf("%s", source);

    translate(source, destination);

    printf("Alien Text: %s\n", destination);

    return 0;
}