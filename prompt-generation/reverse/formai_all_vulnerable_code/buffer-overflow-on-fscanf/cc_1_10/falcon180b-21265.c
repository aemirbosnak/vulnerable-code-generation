//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *dictionary;
    char line[MAX_WORD_LENGTH];
    WordPair words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open the dictionary file
    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Read the words from the dictionary
    while (fscanf(dictionary, "%s", line)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            fclose(dictionary);
            return 1;
        }
        words[numWords].english[0] = toupper(line[0]);
        strcpy(words[numWords].english + 1, &line[1]);
        words[numWords].alien[0] = '\0';
        numWords++;
    }

    // Close the dictionary file
    fclose(dictionary);

    // Translate the input text
    printf("Enter some text to translate:\n");
    fgets(line, MAX_WORD_LENGTH, stdin);
    line[strcspn(line, "\n")] = '\0';

    // Split the input text into words
    char *token = strtok(line, ",.!?;:");
    while (token!= NULL) {
        // Look up each word in the dictionary
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // Found a match, translate the word
                printf("%s -> %s\n", token, words[i].alien);
                break;
            }
        }

        // If the word is not found, print an error message
        if (i == numWords) {
            printf("Error: unknown word \"%s\".\n", token);
        }

        // Get the next word
        token = strtok(NULL, ",.!?;:");
    }

    return 0;
}