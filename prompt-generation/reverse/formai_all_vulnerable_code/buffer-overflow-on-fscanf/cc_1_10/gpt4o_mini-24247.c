//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_TRANSLATIONS 50
#define MAX_CAT_TRANSLATION_LENGTH 100
#define MAX_COMMAND_LENGTH 30

typedef struct {
    char english[MAX_COMMAND_LENGTH];
    char cat[MAX_CAT_TRANSLATION_LENGTH];
} Translation;

Translation translations[MAX_TRANSLATIONS];
int translation_count = 0;

void load_translations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open translation file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%[^:]:%[^\n]\n", translations[translation_count].english, translations[translation_count].cat) != EOF) {
        translation_count++;
        if (translation_count >= MAX_TRANSLATIONS) break;
    }

    fclose(file);
}

void translate(const char *input) {
    int found = 0;
    for (int i = 0; i < translation_count; i++) {
        if (strcmp(input, translations[i].english) == 0) {
            printf("Cat Language: %s\n", translations[i].cat);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Cat Language: unknown command\n");
    }
}

void display_menu() {
    printf("Welcome to the Cat Language Translator!\n");
    printf("Type an English command to see how a cat might respond:\n");
    printf("Available commands: \n");
    for (int i = 0; i < translation_count; i++) {
        printf(" - %s\n", translations[i].english);
    }
    printf("Type 'exit' to quit the translator.\n");
}

int main() {
    char input[MAX_INPUT];

    load_translations("translations.txt");
    
    display_menu();

    while (1) {
        printf("Your command: ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0; // Remove the trailing newline

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Goodbye!\n");
            break;
        }

        translate(input);
    }

    return 0;
}