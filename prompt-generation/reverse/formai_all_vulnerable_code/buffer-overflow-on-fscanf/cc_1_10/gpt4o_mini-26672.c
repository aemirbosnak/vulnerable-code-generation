//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

// Structure to hold alien language translations
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

// Function Prototypes
void loadTranslations(Translation translations[], int *count);
void translateToAlien(const Translation translations[], int count, const char *input, char *output);
void displayTranslation(const char *input, const char *output);

int main() {
    Translation translations[MAX_WORDS];
    int translationCount = 0;
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];

    // Load translations from file
    loadTranslations(translations, &translationCount);

    // User input loop
    while (1) {
        printf("\nEnter a sentence to translate into Alien language (or type 'exit' to quit): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Translate input
        translateToAlien(translations, translationCount, input, output);
        displayTranslation(input, output);
    }

    return 0;
}

void loadTranslations(Translation translations[], int *count) {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open translations.txt for reading\n");
        exit(EXIT_FAILURE);
    }

    // Load translations until EOF or MAX_WORDS limit
    while ((*count < MAX_WORDS) && (fscanf(file, "%s %s", translations[*count].english, translations[*count].alien) == 2)) {
        (*count)++;
    }

    fclose(file);
}

void translateToAlien(const Translation translations[], int count, const char *input, char *output) {
    char *token;
    char translatedSentence[MAX_INPUT_LENGTH] = "";
    char tempWord[MAX_WORD_LENGTH];
    int found;

    // Tokenize the input into words
    strcpy(tempWord, input);
    token = strtok(tempWord, " ");

    while (token != NULL) {
        found = 0;
        
        // Check for translation in the list
        for (int i = 0; i < count; i++) {
            if (strcmp(token, translations[i].english) == 0) {
                strcat(translatedSentence, translations[i].alien);
                strcat(translatedSentence, " ");
                found = 1;
                break;
            }
        }

        // If no translation found, keep the original word
        if (!found) {
            strcat(translatedSentence, token);
            strcat(translatedSentence, " ");
        }

        token = strtok(NULL, " ");
    }

    // Remove trailing space and set output
    translatedSentence[strcspn(translatedSentence, " ")] = '\0';  // Remove last space
    strcpy(output, translatedSentence);
}

void displayTranslation(const char *input, const char *output) {
    printf("\nOriginal Sentence: %s", input);
    printf("\nTranslated to Alien: %s\n", output);
}