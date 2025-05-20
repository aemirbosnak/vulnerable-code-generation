//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRANSLATIONS 100

typedef struct {
    char* english;
    char* alien;
} Translation;

Translation translations[MAX_TRANSLATIONS];
int translation_count = 0;

// Function to add a new translation
void add_translation(const char* english, const char* alien) {
    if (translation_count < MAX_TRANSLATIONS) {
        translations[translation_count].english = strdup(english);
        translations[translation_count].alien = strdup(alien);
        translation_count++;
        printf("Translation added: %s -> %s\n", english, alien);
    } else {
        printf("Max translation limit reached!\n");
    }
}

// Function to translate English to Alien language
const char* translate_to_alien(const char* english) {
    for (int i = 0; i < translation_count; i++) {
        if (strcmp(translations[i].english, english) == 0) {
            return translations[i].alien;
        }
    }
    return "Translation not found!";
}

// Function to interact with the user
void user_interaction() {
    char input[MAX_WORD_LENGTH];
    printf("Welcome to Alien Language Translator!\n");
    
    while (1) {
        printf("Enter an English word to translate (or 'exit' to quit): ");
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Removing newline character

        if (strcmp(input, "exit") == 0) {
            printf("Exiting translator. Goodbye!\n");
            break;
        }

        const char* translation = translate_to_alien(input);
        printf("Alien Translation: %s\n", translation);
    }
}

// Function to load translations from a file
void load_translations(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open translation file");
        return;
    }

    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];

    while (fscanf(file, "%s %s", english, alien) != EOF) {
        add_translation(english, alien);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <translation_file.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_translations(argv[1]);
    user_interaction();

    // Free allocated memory
    for (int i = 0; i < translation_count; i++) {
        free(translations[i].english);
        free(translations[i].alien);
    }

    return EXIT_SUCCESS;
}