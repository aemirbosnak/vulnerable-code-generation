//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_TRANSLATIONS 50

typedef struct {
    char english[MAX_WORD_LEN];
    char alien[MAX_WORD_LEN];
} Translation;

Translation dictionary[MAX_TRANSLATIONS];
int translationCount = 0;

// Function Declarations
void addTranslation(char *english, char *alien);
void translateWord(char *word);
void displayAllTranslations();
void loadTranslations();
void saveTranslations();
void displayMenu();

int main() {
    loadTranslations();
    char input[MAX_WORD_LEN];
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the integer input

        switch (choice) {
            case 1:
                printf("Enter an English word to translate: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove the newline
                translateWord(input);
                break;
            case 2: {
                char english[MAX_WORD_LEN], alien[MAX_WORD_LEN];
                printf("Enter an English word: ");
                fgets(english, sizeof(english), stdin);
                english[strcspn(english, "\n")] = '\0'; // Remove the newline
                printf("Enter the corresponding Alien word: ");
                fgets(alien, sizeof(alien), stdin);
                alien[strcspn(alien, "\n")] = '\0'; // Remove the newline
                addTranslation(english, alien);
                break;
            }
            case 3:
                displayAllTranslations();
                break;
            case 4:
                saveTranslations();
                printf("Translations saved!\n");
                break;
            case 5:
                printf("Exiting the translator. Goodbye, Earthling!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 5);

    return 0;
}

void addTranslation(char *english, char *alien) {
    if (translationCount < MAX_TRANSLATIONS) {
        strcpy(dictionary[translationCount].english, english);
        strcpy(dictionary[translationCount].alien, alien);
        translationCount++;
        printf("Added: %s -> %s to the dictionary!\n", english, alien);
    } else {
        printf("Dictionary full! Can't add more translations!\n");
    }
}

void translateWord(char *word) {
    for (int i = 0; i < translationCount; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            printf("The alien translation of '%s' is '%s'!\n", word, dictionary[i].alien);
            return;
        }
    }
    printf("Sorry, the word '%s' is not in the dictionary. Please add it!\n", word);
}

void displayAllTranslations() {
    if (translationCount == 0) {
        printf("No translations available in the dictionary. Start adding some!\n");
        return;
    }
    printf("----- Alien Language Dictionary -----\n");
    for (int i = 0; i < translationCount; i++) {
        printf("%s -> %s\n", dictionary[i].english, dictionary[i].alien);
    }
    printf("------------------------------------\n");
}

void loadTranslations() {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        printf("No existing translations found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, "%s %s", dictionary[translationCount].english, dictionary[translationCount].alien) == 2) {
        translationCount++;
    }
    fclose(file);
    printf("Loaded %d translations from file!\n", translationCount);
}

void saveTranslations() {
    FILE *file = fopen("translations.txt", "w");
    for (int i = 0; i < translationCount; i++) {
        fprintf(file, "%s %s\n", dictionary[i].english, dictionary[i].alien);
    }
    fclose(file);
}

void displayMenu() {
    printf("\n-- Alien Language Translator --\n");
    printf("1. Translate an English word\n");
    printf("2. Add a new translation\n");
    printf("3. View all translations\n");
    printf("4. Save translations to file\n");
    printf("5. Exit\n");
}