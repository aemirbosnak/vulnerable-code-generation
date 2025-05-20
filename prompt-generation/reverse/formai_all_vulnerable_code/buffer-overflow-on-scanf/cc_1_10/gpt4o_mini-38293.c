//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

// Structure to hold translation pairs
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

/* Global Variables */
Translation translations[MAX_TRANSLATIONS];
int translation_count = 0;

// Function prototypes
void load_translations(const char *filename);
void translate_word(const char *word);
void display_translations();
void add_translation(const char *english, const char *alien);

int main() {
    char input[MAX_WORD_LENGTH];
    int choice;

    load_translations("translations.txt");

    while (1) {
        printf("=== Alien Language Translator ===\n");
        printf("1. Translate a word\n");
        printf("2. Display all translations\n");
        printf("3. Add a new translation\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter an English word: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                strtok(input, "\n"); // Remove newline character
                translate_word(input);
                break;
            case 2:
                display_translations();
                break;
            case 3:
                {
                    char english[MAX_WORD_LENGTH];
                    char alien[MAX_WORD_LENGTH];

                    printf("Enter an English word: ");
                    fgets(english, MAX_WORD_LENGTH, stdin);
                    strtok(english, "\n");

                    printf("Enter the alien translation: ");
                    fgets(alien, MAX_WORD_LENGTH, stdin);
                    strtok(alien, "\n");

                    add_translation(english, alien);
                }
                break;
            case 4:
                printf("Exiting the translator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to load translations from a file
void load_translations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Can't open translations file.\n");
        return;
    }

    while (fscanf(file, "%s %s", translations[translation_count].english, translations[translation_count].alien) != EOF) {
        translation_count++;
        if (translation_count >= MAX_TRANSLATIONS) {
            printf("Translation limit reached!\n");
            break;
        }
    }

    fclose(file);
    printf("Loaded %d translations from %s.\n", translation_count, filename);
}

// Function that translates a word from English to Alien
void translate_word(const char *word) {
    for (int i = 0; i < translation_count; i++) {
        if (strcmp(translations[i].english, word) == 0) {
            printf("The alien translation of '%s' is: %s\n", word, translations[i].alien);
            return;
        }
    }
    printf("Translation not found for '%s'.\n", word);
}

// Function to display all translations
void display_translations() {
    printf("=== All Translations ===\n");
    for (int i = 0; i < translation_count; i++) {
        printf("%s -> %s\n", translations[i].english, translations[i].alien);
    }
}

// Function to add a new translation
void add_translation(const char *english, const char *alien) {
    if (translation_count < MAX_TRANSLATIONS) {
        strcpy(translations[translation_count].english, english);
        strcpy(translations[translation_count].alien, alien);
        translation_count++;
        printf("Added new translation: '%s' -> '%s'\n", english, alien);
    } else {
        printf("Error: Translation limit reached. Can't add more.\n");
    }
}