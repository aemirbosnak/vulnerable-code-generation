//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRANSLATIONS 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

typedef struct {
    Translation translations[MAX_TRANSLATIONS];
    int count;
} Translator;

void initializeTranslator(Translator *translator) {
    translator->count = 0;
}

void addTranslation(Translator *translator, const char *english, const char *alien) {
    if (translator->count < MAX_TRANSLATIONS) {
        strncpy(translator->translations[translator->count].english, english, MAX_WORD_LENGTH);
        strncpy(translator->translations[translator->count].alien, alien, MAX_WORD_LENGTH);
        translator->count++;
    } else {
        printf("Cannot add more translations, limit reached.\n");
    }
}

const char* translateToAlien(Translator *translator, const char *english) {
    for (int i = 0; i < translator->count; i++) {
        if (strcmp(translator->translations[i].english, english) == 0) {
            return translator->translations[i].alien;
        }
    }
    return NULL; // Translation not found
}

const char* translateToEnglish(Translator *translator, const char *alien) {
    for (int i = 0; i < translator->count; i++) {
        if (strcmp(translator->translations[i].alien, alien) == 0) {
            return translator->translations[i].english;
        }
    }
    return NULL; // Translation not found
}

void displayTranslations(Translator *translator) {
    printf("\nCurrent Translations:\n");
    for (int i = 0; i < translator->count; i++) {
        printf("%s -> %s\n", translator->translations[i].english, translator->translations[i].alien);
    }
}

void inputTranslations(Translator *translator) {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
    printf("Enter translations (type 'exit' to finish):\n");
    while (1) {
        printf("\nEnglish: ");
        fgets(english, MAX_WORD_LENGTH, stdin);
        english[strcspn(english, "\n")] = '\0'; // Remove newline character

        if (strcmp(english, "exit") == 0) break;

        printf("Alien: ");
        fgets(alien, MAX_WORD_LENGTH, stdin);
        alien[strcspn(alien, "\n")] = '\0'; // Remove newline character

        addTranslation(translator, english, alien);
    }
}

void interactiveTranslator(Translator *translator) {
    char choice;
    char input[MAX_WORD_LENGTH];
    printf("Welcome to the Alien Language Translator!\n");
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Translate from English to Alien\n");
        printf("2. Translate from Alien to English\n");
        printf("3. Display all translations\n");
        printf("4. Input new translations\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case '1':
                printf("Enter English phrase to translate: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline
                {
                    const char *alienTranslation = translateToAlien(translator, input);
                    if (alienTranslation) {
                        printf("Translation: %s\n", alienTranslation);
                    } else {
                        printf("No translation found.\n");
                    }
                }
                break;
            case '2':
                printf("Enter Alien phrase to translate: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline
                {
                    const char *englishTranslation = translateToEnglish(translator, input);
                    if (englishTranslation) {
                        printf("Translation: %s\n", englishTranslation);
                    } else {
                        printf("No translation found.\n");
                    }
                }
                break;
            case '3':
                displayTranslations(translator);
                break;
            case '4':
                inputTranslations(translator);
                break;
            case '5':
                printf("Exiting the translator. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    Translator translator;
    initializeTranslator(&translator);
    interactiveTranslator(&translator);
    return 0;
}