//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Define the maximum length of the alien language as 50 characters
#define MAX_LENGTH 50

// Define the structure of the C Alien Language Translator
typedef struct {
    char alien[MAX_LENGTH];
    char english[MAX_LENGTH];
} AlienLanguage;

// Define a function to get user input for the alien and English language pair
AlienLanguage getLanguagePair() {
    AlienLanguage languagePair;
    printf("Enter the alien language: ");
    fgets(languagePair.alien, MAX_LENGTH, stdin);
    languagePair.alien[strcspn(languagePair.alien, "\n")] = 0;
    printf("Enter the English translation: ");
    fgets(languagePair.english, MAX_LENGTH, stdin);
    languagePair.english[strcspn(languagePair.english, "\n")] = 0;
    return languagePair;
}

// Define the main function to operate the C Alien Language Translator
int main() {
    int numPairs, i, j, input;
    AlienLanguage languagePairs[MAX_LENGTH];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("How many language pairs would you like to enter? ");
    scanf("%d", &numPairs);
    getchar();  // Consume the newline character
    for (i = 0; i < numPairs; i++) {
        languagePairs[i] = getLanguagePair();
    }
    printf("Language pairs entered:\n");
    for (i = 0; i < numPairs; i++) {
        printf("%s -> %s\n", languagePairs[i].alien, languagePairs[i].english);
    }
    printf("Enter a phrase in alien language or English (0 to exit): ");
    while (1) {
        input = getchar();
        if (input == '0') {
            break;
        }
        char phrase[MAX_LENGTH];
        i = 0;
        // Check if the input is a number (i.e. English phrase)
        if (isdigit((unsigned char) input)) {
            scanf("%s", phrase);
            // Search for the English phrase in the languagePairs array
            for (j = 0; j < numPairs; j++) {
                if (strcmp(languagePairs[j].english, phrase) == 0) {
                    printf("%s ", languagePairs[j].alien);
                    break;
                }
            }
            if (j == numPairs) {
                printf("Phrase not found in dictionary. ");
            }
        }
        // Input is a non-number (i.e. alien phrase)
        else {
            phrase[i++] = input;
            while ((input = getchar()) != '\n') {
                phrase[i++] = input;
            }
            phrase[i] = '\0';
            // Search for the alien phrase in the languagePairs array
            for (j = 0; j < numPairs; j++) {
                if (strcmp(languagePairs[j].alien, phrase) == 0) {
                    printf("%s ", languagePairs[j].english);
                    break;
                }
            }
            if (j == numPairs) {
                printf("Phrase not found in dictionary. ");
            }
        }
        printf("Enter another phrase (0 to exit): ");
        getchar();  // Consume the newline character
    }
    printf("Exiting the C Alien Language Translator.\n");
    return 0;
}