//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256
#define DICTIONARY_SIZE 5

// A structure to hold the English words and their Cat Language translations.
typedef struct {
    char english[MAX_LENGTH];
    char catLanguage[MAX_LENGTH];
} DictionaryEntry;

// The grand library of translations
DictionaryEntry dictionary[DICTIONARY_SIZE];

// Function to initialize the dictionary with translations
void initializeDictionary() {
    strcpy(dictionary[0].english, "hello");
    strcpy(dictionary[0].catLanguage, "meow");

    strcpy(dictionary[1].english, "food");
    strcpy(dictionary[1].catLanguage, "nomnom");

    strcpy(dictionary[2].english, "friend");
    strcpy(dictionary[2].catLanguage, "purr");

    strcpy(dictionary[3].english, "sleep");
    strcpy(dictionary[3].catLanguage, "zzz");

    strcpy(dictionary[4].english, "play");
    strcpy(dictionary[4].catLanguage, "chase");
}

// Function to translate a given English word to Cat Language
void translateToCatLanguage(const char* englishWord) {
    int found = 0;
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(dictionary[i].english, englishWord) == 0) {
            printf("In Cat Language, '%s' translates to '%s'.\n", englishWord, dictionary[i].catLanguage);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Alas! Thou hast summoned a word that doth not exist in our Cat Language realm.\n");
    }
}

// Function to prompt the user for input until they choose to exit
void promptForTranslation() {
    char input[MAX_LENGTH];

    printf("Welcome, noble traveler, to the Cat Language Translator!\n");
    printf("Speak thy word in English and let us hear its feline form.\n");
    printf("Type 'exit' to leave the magical realm.\n\n");

    while (1) {
        printf("Enter an English word: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Fare thee well, dear adventurer!\n");
            break;
        }
        
        translateToCatLanguage(input);
        printf("\n"); // Add spacing between entries
    }
}

int main() {
    // Initialize the dictionary of translations
    initializeDictionary();

    // Begin the enchanted conversation
    promptForTranslation();

    return 0;
}