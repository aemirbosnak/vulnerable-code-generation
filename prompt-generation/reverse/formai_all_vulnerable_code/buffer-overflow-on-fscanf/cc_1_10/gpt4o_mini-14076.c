//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_TRANSLATIONS 128

// Cat Language Dictionary
typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Translation;

Translation dictionary[MAX_TRANSLATIONS];
int translation_count = 0;

// Function prototypes
void load_dictionary(const char *filename);
void translate_to_cat(const char *input);
void add_translation(const char *english, const char *cat);
void display_dictionary();

int main() {
    char input[MAX_INPUT_LENGTH];
    const char *dict_file = "cat_dictionary.txt";

    printf("Welcome to the Cat Language Translator!\n");
    load_dictionary(dict_file);

    while (1) {
        printf("Enter a sentence in English (or type 'exit' to quit): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        translate_to_cat(input);
    }

    display_dictionary();
    return 0;
}

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dictionary[translation_count].english, dictionary[translation_count].cat) != EOF) {
        translation_count++;
    }

    fclose(file);
}

void translate_to_cat(const char *input) {
    char *token;
    char temp_input[MAX_INPUT_LENGTH];
    strcpy(temp_input, input);
    
    printf("Cat Translation: ");
    token = strtok(temp_input, " ");

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < translation_count; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].cat);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token); // If not found, return the original word
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void add_translation(const char *english, const char *cat) {
    if (translation_count < MAX_TRANSLATIONS) {
        strcpy(dictionary[translation_count].english, english);
        strcpy(dictionary[translation_count].cat, cat);
        translation_count++;
    } else {
        printf("Translation limit reached!\n");
    }
}

void display_dictionary() {
    printf("\nCurrent Cat Language Dictionary:\n");
    for (int i = 0; i < translation_count; i++) {
        printf("%s -> %s\n", dictionary[i].english, dictionary[i].cat);
    }
}