//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 50

typedef struct {
    char *english;
    char *alien;
} Translation;

Translation dictionary[MAX_TRANSLATIONS];
int translationCount = 0;

// Function to initialize the dictionary with translations
void initializeDictionary() {
    /* Example translations from English to a fictional Alien language */
    dictionary[translationCount++] = (Translation){"hello", "zark"};
    dictionary[translationCount++] = (Translation){"world", "glop"};
    dictionary[translationCount++] = (Translation){"my", "frik"};
    dictionary[translationCount++] = (Translation){"name", "xil"};
    dictionary[translationCount++] = (Translation){"is", "ta"};
    dictionary[translationCount++] = (Translation){"friend", "vloop"};
    dictionary[translationCount++] = (Translation){"good", "blarn"};
    dictionary[translationCount++] = (Translation){"bye", "kree"};
    dictionary[translationCount++] = (Translation){"thank", "blig"};
    dictionary[translationCount++] = (Translation){"you", "thrip"};
}

// Function to translate a single word
char *translateWord(const char *word) {
    for (int i = 0; i < translationCount; i++) {
        if (strcmp(dictionary[i].english, word) == 0) {
            return dictionary[i].alien;
        }
    }
    return word; // Return the word itself if no translation is found
}

// Function to translate a sentence
void translateSentence(const char *sentence) {
    char *modifiableSentence = strdup(sentence);
    char *token = strtok(modifiableSentence, " ");
    
    printf("Translation: ");
    while (token != NULL) {
        char *translatedWord = translateWord(token);
        printf("%s ", translatedWord);
        token = strtok(NULL, " ");
    }
    printf("\n");
    free(modifiableSentence);
}

// Function to display menu options
void displayMenu() {
    printf("=== Alien Language Translator ===\n");
    printf("1. Translate a sentence\n");
    printf("2. Add a new translation\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new translation
void addTranslation() {
    if (translationCount >= MAX_TRANSLATIONS) {
        printf("Translation dictionary is full!\n");
        return;
    }
    
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
    
    printf("Enter the English word: ");
    scanf("%s", english);
    printf("Enter the Alien translation: ");
    scanf("%s", alien);
    
    dictionary[translationCount++] = (Translation){strdup(english), strdup(alien)};
    printf("Translation added: %s -> %s\n", english, alien);
}

int main() {
    initializeDictionary();
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                {
                    char sentence[256];
                    printf("Enter a sentence to translate: ");
                    getchar(); // Clear newline character from input buffer
                    fgets(sentence, sizeof(sentence), stdin);
                    sentence[strcspn(sentence, "\n")] = 0; // Remove newline character
                    translateSentence(sentence);
                }
                break;
            case 2:
                addTranslation();
                break;
            case 3:
                printf("Exiting the translator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}