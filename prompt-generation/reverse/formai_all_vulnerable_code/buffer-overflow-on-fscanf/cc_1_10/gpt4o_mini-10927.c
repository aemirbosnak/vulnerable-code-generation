//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000

// Structure to represent the alien language dictionary
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

// Function prototypes
void loadDictionary(const char *filename);
char* translateWord(const char *word);
void translateSentence(const char *sentence);
void toLowerCase(char *str);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <sentence>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the alien dictionary from the specified file
    loadDictionary(argv[1]);

    // Translate the provided sentence
    printf("Translating: \"%s\"\n", argv[2]);
    translateSentence(argv[2]);

    return EXIT_SUCCESS;
}

void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dictionary[dictionarySize].english, dictionary[dictionarySize].alien) == 2) {
        dictionarySize++;
        if (dictionarySize >= MAX_DICTIONARY_SIZE) {
            fprintf(stderr, "Warning: maximum dictionary size reached!\n");
            break;
        }
    }
    fclose(file);
    printf("Loaded %d entries from the dictionary.\n", dictionarySize);
}

char* translateWord(const char *word) {
    char lowerWord[MAX_WORD_LENGTH];
    strcpy(lowerWord, word);
    toLowerCase(lowerWord);

    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(lowerWord, dictionary[i].english) == 0) {
            return dictionary[i].alien;
        }
    }
    return word; // Return the original word if not found
}

void translateSentence(const char *sentence) {
    char tempSentence[MAX_WORD_LENGTH * 10];
    strcpy(tempSentence, sentence);
    
    char *token = strtok(tempSentence, " ");
    while (token != NULL) {
        char *translated = translateWord(token);
        printf("%s ", translated);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}