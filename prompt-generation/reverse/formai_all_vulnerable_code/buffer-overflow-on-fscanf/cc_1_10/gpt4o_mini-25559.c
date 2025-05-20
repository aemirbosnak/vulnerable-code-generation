//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_TRANSLATIONS 100

typedef struct {
    char english[MAX_WORD_LEN];
    char cat[MAX_WORD_LEN];
} Translation;

Translation dictionary[MAX_TRANSLATIONS];
int numTranslations = 0;

// Function prototypes
void loadDictionary(char *filename);
void addTranslation(char *english, char *cat);
void translateWord(char *input);
void printDictionary(void);
void freeTranslations(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <dictionary_file>\n", argv[0]);
        return 1;
    }

    loadDictionary(argv[1]);
    char input[MAX_WORD_LEN];

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter English words to translate to Cat (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_WORD_LEN, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline

        if (strcmp(input, "exit") == 0) {
            break;
        }

        translateWord(input);
    }

    freeTranslations();
    return 0;
}

void loadDictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(1);
    }

    while (fscanf(file, "%s %s", dictionary[numTranslations].english, dictionary[numTranslations].cat) == 2) {
        numTranslations++;
        if (numTranslations >= MAX_TRANSLATIONS) {
            printf("Warning: Dictionary size exceeded. Some entries may be ignored.\n");
            break;
        }
    }
    fclose(file);
}

void addTranslation(char *english, char *cat) {
    if (numTranslations < MAX_TRANSLATIONS) {
        strcpy(dictionary[numTranslations].english, english);
        strcpy(dictionary[numTranslations].cat, cat);
        numTranslations++;
    } else {
        printf("Dictionary is full. Cannot add more translations.\n");
    }
}

void translateWord(char *input) {
    for (int i = 0; i < numTranslations; i++) {
        if (strcmp(dictionary[i].english, input) == 0) {
            printf("Cat Translation: %s\n", dictionary[i].cat);
            return;
        }
    }
    printf("Translation not found for: %s\n", input);
}

void printDictionary(void) {
    printf("Current Dictionary:\n");
    for (int i = 0; i < numTranslations; i++) {
        printf("%s -> %s\n", dictionary[i].english, dictionary[i].cat);
    }
}

void freeTranslations(void) {
    // Currently, there is no dynamic memory allocation,
    // but this function is here for potential use in the future.
}