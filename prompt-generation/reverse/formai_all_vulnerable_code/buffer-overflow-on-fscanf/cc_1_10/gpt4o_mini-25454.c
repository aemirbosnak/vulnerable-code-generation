//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_WORD_SIZE 100
#define DICTIONARY_SIZE 128

// Struct for the Cat Language Dictionary
typedef struct {
    char english[MAX_WORD_SIZE];
    char catLanguage[MAX_WORD_SIZE];
} DictionaryEntry;

// Function prototypes
void loadDictionary(DictionaryEntry *dictionary, int *dictionarySize);
void translateToCat(const char *input, DictionaryEntry *dictionary, int dictionarySize);
void toLowerCase(char *str);

int main() {
    DictionaryEntry dictionary[DICTIONARY_SIZE];
    int dictionarySize = 0;

    // Load the dictionary from a file
    loadDictionary(dictionary, &dictionarySize);

    char input[MAX_INPUT_SIZE];

    printf("Welcome to the Cat Language Translator!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("Enter a sentence in English: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Translate to Cat language
        translateToCat(input, dictionary, dictionarySize);
    }

    printf("Thank you for using the Cat Language Translator!\n");
    return 0;
}

// Function to load the dictionary from a text file
void loadDictionary(DictionaryEntry *dictionary, int *dictionarySize) {
    FILE *file = fopen("cat_dict.txt", "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", dictionary[*dictionarySize].english, dictionary[*dictionarySize].catLanguage) != EOF) {
        (*dictionarySize)++;
        if (*dictionarySize >= DICTIONARY_SIZE) {
            break; // Avoid exceeding the dictionary array
        }
    }
    
    fclose(file);
}

// Function to translate the input sentence to Cat language
void translateToCat(const char *input, DictionaryEntry *dictionary, int dictionarySize) {
    char *word;
    char inputCopy[MAX_INPUT_SIZE];
    strcpy(inputCopy, input);
    toLowerCase(inputCopy);

    word = strtok(inputCopy, " ");
    int firstWord = 1;

    printf("Translation in Cat Language: ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < dictionarySize; i++) {
            if (strcmp(word, dictionary[i].english) == 0) {
                if (!firstWord) {
                    printf(" ");
                }
                printf("%s", dictionary[i].catLanguage);
                found = 1;
                break;
            }
        }
        if (!found) {
            if (!firstWord) {
                printf(" ");
            }
            printf("[%s]", word); // Indicating an untranslatable word
        }
        firstWord = 0;
        word = strtok(NULL, " ");
    }
    printf("\n");
}

// Function to convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}