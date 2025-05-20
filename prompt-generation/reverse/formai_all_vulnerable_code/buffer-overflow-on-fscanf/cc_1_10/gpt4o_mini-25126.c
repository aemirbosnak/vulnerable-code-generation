//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRANSLATION_LENGTH 100
#define MAX_INPUT_LENGTH 256
#define MAX_WORDS 50

// A structure to hold the translation rules
typedef struct {
    char alienWord[MAX_TRANSLATION_LENGTH];
    char englishWord[MAX_TRANSLATION_LENGTH];
} TranslationRule;

// An array of translation rules
TranslationRule dictionary[MAX_WORDS];
int ruleCount = 0;

// Function prototypes
void loadDictionary(const char* filename);
void translateToAlien(char* input);
void translateToEnglish(char* input);
void addTranslationRule(char* englishWord, char* alienWord);
void displayMenu();
char* trimWhitespaces(char* str);

int main() {
    char input[MAX_INPUT_LENGTH];
    int choice;

    // Load the translation rules
    loadDictionary("alien_dictionary.txt");

    // Display the menu and get user input
    while (1) {
        displayMenu();
        printf("Enter your choice (1-3 or 0 to exit): ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(trimWhitespaces(input));

        switch (choice) {
            case 1:
                printf("Enter English text to translate to Alien: ");
                fgets(input, sizeof(input), stdin);
                translateToAlien(trimWhitespaces(input));
                break;
            case 2:
                printf("Enter Alien text to translate to English: ");
                fgets(input, sizeof(input), stdin);
                translateToEnglish(trimWhitespaces(input));
                break;
            case 3:
                printf("Enter new English word and its Alien translation (e.g., hello ALIEN): ");
                fgets(input, sizeof(input), stdin);
                char* englishWord = strtok(input, " ");
                char* alienWord = strtok(NULL, "\n");
                if (englishWord && alienWord) {
                    addTranslationRule(englishWord, alienWord);
                    printf("Translation rule added successfully!\n");
                } else {
                    printf("Invalid input. Make sure to enter two words.\n");
                }
                break;
            case 0:
                printf("Exiting the translator. Until next time, Earthling!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

// Function to load translation rules from a file
void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open translation dictionary");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", dictionary[ruleCount].englishWord, dictionary[ruleCount].alienWord) == 2) {
        ruleCount++;
        if (ruleCount >= MAX_WORDS) break; // Prevent overflowing the dictionary
    }
    
    fclose(file);
    printf("Loaded %d translation rules from the dictionary.\n", ruleCount);
}

// Function to translate English text to Alien language
void translateToAlien(char* input) {
    char* token = strtok(input, " \n");
    printf("Translated to Alien: ");
    
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ruleCount; i++) {
            if (strcasecmp(token, dictionary[i].englishWord) == 0) {
                printf("%s ", dictionary[i].alienWord);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token); // If no translation, print the original word
        }
        token = strtok(NULL, " \n");
    }
    printf("\n");
}

// Function to translate Alien text to English language
void translateToEnglish(char* input) {
    char* token = strtok(input, " \n");
    printf("Translated to English: ");
    
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ruleCount; i++) {
            if (strcasecmp(token, dictionary[i].alienWord) == 0) {
                printf("%s ", dictionary[i].englishWord);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token); // If no translation, print the original word
        }
        token = strtok(NULL, " \n");
    }
    printf("\n");
}

// Function to add a new translation rule
void addTranslationRule(char* englishWord, char* alienWord) {
    if (ruleCount < MAX_WORDS) {
        strcpy(dictionary[ruleCount].englishWord, englishWord);
        strcpy(dictionary[ruleCount].alienWord, alienWord);
        ruleCount++;
    } else {
        printf("Dictionary is full! Cannot add more translation rules.\n");
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Alien Language Translator Menu ---\n");
    printf("1. Translate English to Alien\n");
    printf("2. Translate Alien to English\n");
    printf("3. Add new translation rule\n");
    printf("0. Exit\n");
}

// Function to trim leading and trailing whitespaces from a string
char* trimWhitespaces(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the string
    *(end + 1) = '\0';

    return str;
}