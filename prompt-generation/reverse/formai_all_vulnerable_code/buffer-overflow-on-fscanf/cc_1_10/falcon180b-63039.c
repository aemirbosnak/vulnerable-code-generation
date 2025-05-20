//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define ALIEN_DICTIONARY_SIZE 200
#define ENGLISH_DICTIONARY_SIZE 200

struct word {
    char alien[MAX_WORD_LENGTH];
    char english[MAX_WORD_LENGTH];
};

void load_alien_dictionary(struct word dictionary[ALIEN_DICTIONARY_SIZE]) {
    FILE *file = fopen("alien_dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open alien_dictionary.txt\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s %s", dictionary[count].alien, dictionary[count].english)!= EOF) {
        count++;
    }
    fclose(file);
}

void load_english_dictionary(struct word dictionary[ENGLISH_DICTIONARY_SIZE]) {
    FILE *file = fopen("english_dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open english_dictionary.txt\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s %s", dictionary[count].english, dictionary[count].alien)!= EOF) {
        count++;
    }
    fclose(file);
}

int main() {
    struct word alien_dictionary[ALIEN_DICTIONARY_SIZE];
    struct word english_dictionary[ENGLISH_DICTIONARY_SIZE];
    load_alien_dictionary(alien_dictionary);
    load_english_dictionary(english_dictionary);
    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to translate: ");
        scanf("%s", input);
        int index = 0;
        while (index < ALIEN_DICTIONARY_SIZE) {
            if (strcmp(input, alien_dictionary[index].english) == 0) {
                printf("%s\n", alien_dictionary[index].alien);
                break;
            }
            index++;
        }
        if (index == ALIEN_DICTIONARY_SIZE) {
            printf("Word not found in alien dictionary.\n");
        }
    }
    return 0;
}