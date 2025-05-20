//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat_language[MAX_WORD_LENGTH];
} Translation;

Translation translations[MAX_TRANSLATIONS];
int translation_count = 0;

// Function to add a translation to the array
void add_translation(const char *english, const char *cat_language) {
    if (translation_count < MAX_TRANSLATIONS) {
        strncpy(translations[translation_count].english, english, MAX_WORD_LENGTH);
        strncpy(translations[translation_count].cat_language, cat_language, MAX_WORD_LENGTH);
        translation_count++;
        printf("Added: '%s' -> '%s'\n", english, cat_language);
    } else {
        printf("Translation limit reached!\n");
    }
}

// Function to find the cat language translation for a given English word
const char* translate_to_cat(const char *word) {
    for (int i = 0; i < translation_count; i++) {
        if (strcmp(translations[i].english, word) == 0) {
            return translations[i].cat_language;
        }
    }
    return "Meow"; // Default response if no translation is found
}

// Function to read translations from a file
void load_translations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    
    char english[MAX_WORD_LENGTH];
    char cat_language[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s %s", english, cat_language) == 2) {
        add_translation(english, cat_language);
    }
    
    fclose(file);
}

// Function to display all translations
void display_translations() {
    printf("Translations:\n");
    for (int i = 0; i < translation_count; i++) {
        printf("'%s' -> '%s'\n", translations[i].english, translations[i].cat_language);
    }
}

// Main function
int main() {
    load_translations("translations.txt"); // Load translations from a file
    display_translations(); // Display loaded translations
    
    char input[MAX_WORD_LENGTH];
    
    printf("Enter an English word to translate to Cat Language (or 'exit' to quit): ");
    
    while (1) {
        printf("> ");
        scanf("%s", input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        const char* cat_translation = translate_to_cat(input);
        printf("Cat Language: %s\n", cat_translation);
    }

    printf("Thank you for using the C Cat Language Translator!\n");
    return 0;
}