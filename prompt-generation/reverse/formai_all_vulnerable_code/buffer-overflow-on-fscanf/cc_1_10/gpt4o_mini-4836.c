//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Structure to hold Alien language words and their translations
typedef struct {
    char alien[MAX_WORD_LENGTH];
    char english[MAX_WORD_LENGTH];
} Translation;

// Function prototypes
void loadTranslations(Translation translations[], int *count);
void translateText(Translation translations[], int count, const char *input, char *output);
void displayTranslations(Translation translations[], int count);
void addTranslation(Translation translations[], int *count);
void saveTranslations(Translation translations[], int count);
void clearInputBuffer();

int main() {
    Translation translations[MAX_WORDS];
    int translationCount = 0;
    int choice;
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];

    loadTranslations(translations, &translationCount);

    do {
        printf("=== Alien Language Translator ===\n");
        printf("1. Translate Text\n");
        printf("2. Add Translation\n");
        printf("3. Display Translations\n");
        printf("4. Save Translations\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Enter text to translate (max %d characters): ", MAX_INPUT_LENGTH);
                fgets(input, MAX_INPUT_LENGTH, stdin);
                translateText(translations, translationCount, input, output);
                printf("Translated text: %s\n", output);
                break;
            case 2:
                addTranslation(translations, &translationCount);
                break;
            case 3:
                displayTranslations(translations, translationCount);
                break;
            case 4:
                saveTranslations(translations, translationCount);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void loadTranslations(Translation translations[], int *count) {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        perror("Could not open translations.txt for reading");
        return;
    }

    while (fscanf(file, "%s %s", translations[*count].alien, translations[*count].english) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Loaded %d translations from translations.txt\n", *count);
}

void translateText(Translation translations[], int count, const char *input, char *output) {
    char word[MAX_WORD_LENGTH];
    char translated[MAX_INPUT_LENGTH] = "";
    int i, wordLength;

    // Reset the output string
    output[0] = '\0';
    
    // Tokenize the input and translate each word
    char *token = strtok((char *)input, " \n");
    while (token != NULL) {
        strcpy(word, token);
        int found = 0;

        // Search for the word in the translations
        for (i = 0; i < count; i++) {
            if (strcmp(translations[i].alien, word) == 0) {
                strcat(translated, translations[i].english);
                strcat(translated, " ");
                found = 1;
                break;
            }
        }
        
        if (!found) {
            strcat(translated, word);
            strcat(translated, " "); // Keep unknown words
        }

        token = strtok(NULL, " \n");
    }

    // Copy translated text to output
    strcpy(output, translated);
}

void displayTranslations(Translation translations[], int count) {
    printf("Current Translations:\n");
    for (int i = 0; i < count; i++) {
        printf("%s -> %s\n", translations[i].alien, translations[i].english);
    }
}

void addTranslation(Translation translations[], int *count) {
    if (*count >= MAX_WORDS) {
        printf("Translation list is full!\n");
        return;
    }

    printf("Enter alien word: ");
    scanf("%s", translations[*count].alien);
    printf("Enter English translation: ");
    scanf("%s", translations[*count].english);
    (*count)++;
    printf("Translation added!\n");
}

void saveTranslations(Translation translations[], int count) {
    FILE *file = fopen("translations.txt", "w");
    if (file == NULL) {
        perror("Could not open translations.txt for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", translations[i].alien, translations[i].english);
    }
    fclose(file);
    printf("Saved %d translations to translations.txt\n", count);
}

void clearInputBuffer() {
    while (getchar() != '\n');
}