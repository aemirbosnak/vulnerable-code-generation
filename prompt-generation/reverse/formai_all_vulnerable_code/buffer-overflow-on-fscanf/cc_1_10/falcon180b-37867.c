//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *english;
    char *alien;
} Word;

int main() {
    FILE *dict;
    char line[100];
    Word words[MAX_WORDS];
    int numWords = 0;
    char input[100];

    // Open dictionary file
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    // Read words from dictionary file
    while (fscanf(dict, "%s %s\n", line, line) == 2) {
        words[numWords].english = strdup(line);
        words[numWords++].alien = strdup(line);
    }
    fclose(dict);

    // Get user input
    printf("Enter a sentence to translate:\n");
    fgets(input, 100, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    char *token = strtok(input, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // Word found, print alien translation
                printf("%s ", words[i].alien);
                break;
            }
        }
        if (i == numWords) {
            // Word not found, print original word
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}