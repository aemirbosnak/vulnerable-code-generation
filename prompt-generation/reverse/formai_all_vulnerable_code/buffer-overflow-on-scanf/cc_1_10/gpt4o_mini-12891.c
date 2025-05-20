//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

// Structure to hold a word translation
typedef struct {
    char english[MAX_LENGTH];
    char alien[MAX_LENGTH];
} Translation;

// Functions prototype
void initializeTranslations(Translation translations[]);
void translateWord(Translation translations[], const char *input);
void displayTranslations(Translation translations[]);

int main() {
    Translation translations[MAX_WORDS];
    char input[MAX_LENGTH];

    // Initialize the translations
    initializeTranslations(translations);

    printf("Welcome to the Alien Language Translator!\n");
    printf("Type a word in English to translate to Alien or type 'exit' to quit:\n");

    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Farewell!\n");
            break;
        }

        translateWord(translations, input);
    }

    return 0;
}

// Function to initialize the translations
void initializeTranslations(Translation translations[]) {
    // Sample translations
    strcpy(translations[0].english, "hello");
    strcpy(translations[0].alien, "gzrath");

    strcpy(translations[1].english, "friend");
    strcpy(translations[1].alien, "qwibble");

    strcpy(translations[2].english, "earth");
    strcpy(translations[2].alien, "xylop");

    strcpy(translations[3].english, "space");
    strcpy(translations[3].alien, "flarg");

    strcpy(translations[4].english, "food");
    strcpy(translations[4].alien, "zurg");

    // More translations can be added here...
}

// Function to translate a word
void translateWord(Translation translations[], const char *input) {
    int found = 0;

    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(translations[i].english, input) == 0) {
            printf("The alien translation of '%s' is '%s'.\n", input, translations[i].alien);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sorry, the word '%s' is not in the dictionary.\n", input);
    }
}

// Function to display all translations
void displayTranslations(Translation translations[]) {
    printf("Available translations:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(translations[i].english) > 0) {
            printf(" - %s -> %s\n", translations[i].english, translations[i].alien);
        }
    }
}