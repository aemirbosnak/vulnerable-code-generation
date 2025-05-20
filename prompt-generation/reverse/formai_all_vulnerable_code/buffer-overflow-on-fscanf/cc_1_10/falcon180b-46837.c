//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORDS];
    char translation[MAX_WORDS];
} WordPair;

int main() {
    // Load dictionary
    WordPair dictionary[MAX_WORDS];
    FILE *fp = fopen("dictionary.txt", "r");
    int numWords = 0;
    while (fscanf(fp, "%s %s", dictionary[numWords].word, dictionary[numWords].translation)!= EOF) {
        numWords++;
    }
    fclose(fp);

    // Prompt user for input
    char input[MAX_WORDS];
    printf("Enter a sentence in English:\n");
    fgets(input, MAX_WORDS, stdin);

    // Tokenize input
    char *token = strtok(input, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        WordPair *match = NULL;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                match = &dictionary[i];
                break;
            }
        }
        if (match!= NULL) {
            // Replace word with translation
            printf("%s ", match->translation);
        } else {
            // Word not found, leave as is
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}