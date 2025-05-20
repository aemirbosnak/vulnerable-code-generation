//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 20

typedef enum {
    UPPERCASE,
    LOWERCASE
} LetterCase;

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    LetterCase desiredCase;
} WordConfig;

void printUsage() {
    printf("Usage: text-processor [flags] [input-file]\n"
           "Flags:\n"
           "  -u  Convert all words to uppercase\n"
           "  -l  Convert all words to lowercase\n"
           "  -c <word>:<U|L>  Convert specific word to uppercase or lowercase\n");
}

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    LetterCase defaultCase = LOWERCASE;
    WordConfig wordsConfig[MAX_LINE_LENGTH];
    int numWordConfigs = 0;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0) {
            defaultCase = UPPERCASE;
        } else if (strcmp(argv[i], "-l") == 0) {
            defaultCase = LOWERCASE;
        } else if (strcmp(argv[i], "-c") == 0) {
            if (i + 1 < argc) {
                char *delimiters = ":";
                char *wordToken = strtok(argv[i + 1], delimiters);
                char *caseToken = strtok(NULL, delimiters);

                if (wordToken != NULL && caseToken != NULL) {
                    WordConfig config;
                    strncpy(config.word, wordToken, MAX_WORD_LENGTH);
                    config.length = strlen(wordToken);
                    config.desiredCase = (*caseToken == 'U') ? UPPERCASE : LOWERCASE;
                    wordsConfig[numWordConfigs++] = config;
                }

                i++;    // Skip next argument since we have already processed it
            }
        } else {
            // Assume remaining arguments are input files
            if (file != NULL) {
                printf("Error: Only one input file allowed\n");
                printUsage();
                return 1;
            }

            file = fopen(argv[i], "r");
            if (file == NULL) {
                printf("Error: Could not open input file '%s'\n", argv[i]);
                return 1;
            }
        }
    }

    if (file == NULL) {
        // Read input from stdin
        file = stdin;
    }

    // Process text
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lineNumber++;

        // Split line into words
        char *delimiters = " \t\n\r";   // Space, tab, newline, carriage return
        char *wordToken = strtok(line, delimiters);

        while (wordToken != NULL) {
            // Look for word in list of word configurations
            LetterCase wordCase = defaultCase;
            for (int i = 0; i < numWordConfigs; i++) {
                WordConfig config = wordsConfig[i];
                if (config.length == strlen(wordToken) && strcasecmp(wordToken, config.word) == 0) {
                    wordCase = config.desiredCase;
                }
            }

            // Convert word to desired case
            if (wordCase == UPPERCASE) {
                int i = 0;
                while (wordToken[i] != '\0') {
                    wordToken[i] = toupper(wordToken[i]);
                    i++;
                }
            } else {    // LOWERCASE
                int i = 0;
                while (wordToken[i] != '\0') {
                    wordToken[i] = tolower(wordToken[i]);
                    i++;
                }
            }

            // Print word
            printf("%s ", wordToken);

            // Move to next word
            wordToken = strtok(NULL, delimiters);
        }
    }

    if (file != stdin) {
        fclose(file);
    }

    return 0;
}