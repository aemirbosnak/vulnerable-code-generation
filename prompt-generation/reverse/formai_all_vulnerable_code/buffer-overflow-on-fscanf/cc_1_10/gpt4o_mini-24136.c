//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100

typedef struct {
    char alien[MAX_WORD_LENGTH];
    char english[MAX_WORD_LENGTH];
} Translation;

Translation dictionary[MAX_DICTIONARY_SIZE];
int dict_count = 0;

void add_translation(const char *alien, const char *english) {
    if (dict_count >= MAX_DICTIONARY_SIZE) {
        fprintf(stderr, "Dictionary is full. Cannot add more translations.\n");
        return;
    }
    strcpy(dictionary[dict_count].alien, alien);
    strcpy(dictionary[dict_count].english, english);
    dict_count++;
}

char* translate_to_english(const char *alien) {
    for (int i = 0; i < dict_count; i++) {
        if (strcmp(dictionary[i].alien, alien) == 0) {
            return dictionary[i].english;
        }
    }
    return "UNKNOWN"; // Not found
}

char* translate_to_alien(const char *english) {
    for (int i = 0; i < dict_count; i++) {
        if (strcmp(dictionary[i].english, english) == 0) {
            return dictionary[i].alien;
        }
    }
    return "UNKNOWN"; // Not found
}

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening dictionary file.\n");
        exit(1);
    }

    char alien[MAX_WORD_LENGTH];
    char english[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %s", alien, english) == 2) {
        add_translation(alien, english);
    }
    fclose(file);
}

void display_usage() {
    printf("Usage: alien_translate <alien_word|english_word>\n");
    printf("Enter 'exit' to quit.\n");
}

int main(int argc, char *argv[]) {
    // Load translations from a dictionary file
    load_dictionary("dictionary.txt");

    char input[MAX_WORD_LENGTH];
    display_usage();

    while (1) {
        printf("Enter a word: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Determine if the input is in alien or English
        char *translation = translate_to_english(input);
        if (strcmp(translation, "UNKNOWN") != 0) {
            printf("Translation (Alien -> English): %s\n", translation);
            continue;
        }

        translation = translate_to_alien(input);
        if (strcmp(translation, "UNKNOWN") != 0) {
            printf("Translation (English -> Alien): %s\n", translation);
            continue;
        }

        printf("Translation not found for: %s\n", input);
    }

    return 0;
}