//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRANSLATIONS 100

// Structure to hold the English and Alien word pair
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

// Function prototypes
void loadTranslations(Translation translations[], int *count);
void translateToAlien(char *englishWord, Translation translations[], int count);
void printAvailableWords(Translation translations[], int count);

// Main program
int main() {
    Translation translations[MAX_TRANSLATIONS];
    int count = 0;
    char input[MAX_WORD_LENGTH];

    loadTranslations(translations, &count);
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Type 'exit' to leave the translator.\n");
    
    while (1) {
        printf("\nEnter an English word to translate: ");
        scanf("%s", input);
        
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Farewell!\n");
            break;
        }
        
        translateToAlien(input, translations, count);
        printAvailableWords(translations, count);
    }
    
    return 0;
}

// Load predefined English to Alien translations
void loadTranslations(Translation translations[], int *count) {
    strcpy(translations[*count].english, "hello");
    strcpy(translations[*count].alien, "zqru");
    (*count)++;
    
    strcpy(translations[*count].english, "world");
    strcpy(translations[*count].alien, "taprix");
    (*count)++;
    
    strcpy(translations[*count].english, "friend");
    strcpy(translations[*count].alien, "woktor");
    (*count)++;
    
    strcpy(translations[*count].english, "love");
    strcpy(translations[*count].alien, "prrish");
    (*count)++;
    
    strcpy(translations[*count].english, "peace");
    strcpy(translations[*count].alien, "galor");
    (*count)++;
    
    strcpy(translations[*count].english, "music");
    strcpy(translations[*count].alien, "ynoq");
    (*count)++;
    
    strcpy(translations[*count].english, "star");
    strcpy(translations[*count].alien, "vlyz");
    (*count)++;
    
    strcpy(translations[*count].english, "light");
    strcpy(translations[*count].alien, "zest");
    (*count)++;
    
    strcpy(translations[*count].english, "darkness");
    strcpy(translations[*count].alien, "kralth");
    (*count)++;
}

// Translate an English word to the Alien language
void translateToAlien(char *englishWord, Translation translations[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(translations[i].english, englishWord) == 0) {
            printf("The alien translation of '%s' is '%s'.\n", englishWord, translations[i].alien);
            return;
        }
    }
    printf("Sorry, translation for '%s' is not available.\n", englishWord);
}

// Print available English words for translation
void printAvailableWords(Translation translations[], int count) {
    printf("\nAvailable English words for translation:\n");
  
    for (int i = 0; i < count; i++) {
        printf("- %s\n", translations[i].english);
    }
}