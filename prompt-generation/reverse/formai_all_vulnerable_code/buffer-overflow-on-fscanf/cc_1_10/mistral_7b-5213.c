//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ALPHABET_SIZE 25
#define MAX_INPUT_LENGTH 100

typedef struct AlienDictionary {
    char symbol;
    char english_letter;
} AlienDictionary;

AlienDictionary alien_dictionary[ALIEN_ALPHABET_SIZE];

void load_dictionary() {
    FILE *file = fopen("alien_dictionary.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    int index = 0;
    while (fscanf(file, "%c %c", &alien_dictionary[index].symbol, &alien_dictionary[index].english_letter) != EOF) {
        index++;
    }

    fclose(file);
}

void translate(char *input) {
    int length = strlen(input);
    char output[MAX_INPUT_LENGTH];
    int index;

    for (int i = 0; i < length; i++) {
        index = (int)tolower(input[i]) - 97;
        if (index >= 0 && index < ALIEN_ALPHABET_SIZE) {
            output[i] = alien_dictionary[index].symbol;
        } else {
            output[i] = input[i];
        }
    }

    printf("Alien Translation: %s\n", output);
}

int main() {
    load_dictionary();

    char input[MAX_INPUT_LENGTH];
    printf("Enter English text to translate: ");
    scanf("%s", input);

    translate(input);

    return 0;
}