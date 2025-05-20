//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} translation_t;

int load_translations(translation_t translations[MAX_WORDS]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    int count = 0;

    file = fopen("translations.txt", "r");

    if (file == NULL) {
        printf("Error: could not open translations file.\n");
        return -1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        if (count >= MAX_WORDS) {
            printf("Error: too many translations in file.\n");
            fclose(file);
            return -1;
        }

        char *token = strtok(line, ",");
        strcpy(translations[count].english, token);

        token = strtok(NULL, ",");
        strcpy(translations[count].alien, token);

        count++;
    }

    fclose(file);

    return count;
}

int main() {
    translation_t translations[MAX_WORDS];
    int num_translations;

    num_translations = load_translations(translations);

    if (num_translations <= 0) {
        return -1;
    }

    printf("Alien Language Translator\n");
    printf("Enter a sentence to translate or type 'quit' to exit:\n");

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "quit") == 0) {
            break;
        }

        int i;
        for (i = 0; i < num_translations; i++) {
            if (strcmp(translations[i].english, input) == 0) {
                printf("%s -> %s\n", input, translations[i].alien);
                break;
            }
        }

        if (i == num_translations) {
            printf("Unknown word: %s\n", input);
        }
    }

    return 0;
}