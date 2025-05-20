//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DICTIONARY_SIZE 100

// Struct to hold alien words and their corresponding English translations
typedef struct {
    char alien[BUFFER_SIZE];
    char english[BUFFER_SIZE];
} Translation;

Translation dictionary[DICTIONARY_SIZE];
int translationCount = 0;

// Function Prototypes
void loadTranslations(const char* filename);
void translateToAlien(const char* input, char* output);
void translateToEnglish(const char* input, char* output);
void printHelp();

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printHelp();
        return 1;
    }

    // Load translations from the specified file
    loadTranslations("alien_dictionary.txt");

    char output[BUFFER_SIZE];

    // Determine the mode: Alien to English or English to Alien
    if (strcmp(argv[1], "alien") == 0) {
        translateToEnglish(argv[2], output);
    } else if (strcmp(argv[1], "english") == 0) {
        translateToAlien(argv[2], output);
    } else {
        printHelp();
        return 1;
    }

    printf("Translation: %s\n", output);
    return 0;
}

// Function to load translations from a file
void loadTranslations(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dictionary[translationCount].alien, dictionary[translationCount].english) != EOF) {
        translationCount++;
        if (translationCount >= DICTIONARY_SIZE) {
            break;
        }
    }
    fclose(file);
}

// Function to translate English input to Alien language
void translateToAlien(const char* input, char* output) {
    char result[BUFFER_SIZE] = "";
    char* token;
    char* str = strdup(input);

    token = strtok(str, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < translationCount; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                strcat(result, dictionary[i].alien);
                strcat(result, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(result, token);  // Appendix unmatched words as is
            strcat(result, " ");
        }
        token = strtok(NULL, " ");
    }

    free(str);
    strcpy(output, result);
}

// Function to translate Alien input to English language
void translateToEnglish(const char* input, char* output) {
    char result[BUFFER_SIZE] = "";
    char* token;
    char* str = strdup(input);

    token = strtok(str, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < translationCount; i++) {
            if (strcmp(token, dictionary[i].alien) == 0) {
                strcat(result, dictionary[i].english);
                strcat(result, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(result, token);  // Appendix unmatched words as is
            strcat(result, " ");
        }
        token = strtok(NULL, " ");
    }

    free(str);
    strcpy(output, result);
}

// Function to print help information
void printHelp() {
    printf("Usage: translator <mode> <phrase>\n");
    printf("Modes:\n");
    printf("  alien     : Translate from English to Alien language\n");
    printf("  english   : Translate from Alien language to English\n");
    printf("Example:\n");
    printf("  ./translator alien 'hello world'\n");
    printf("  ./translator english 'vhja ofum'\n");
}