//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void tokenize(char *input, char **tokens) {
    char *word = strtok(input, " ");
    int i = 0;

    while (word!= NULL) {
        if (i >= MAX_TOKENS) {
            break;
        }

        tokens[i] = word;
        i++;

        word = strtok(NULL, " ");
    }

    tokens[i] = NULL;
}

int isSpam(char *input) {
    WordCount *wordCounts = malloc(sizeof(WordCount) * 26);
    int numWords = 0;
    int spamCount = 0;

    char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
    tokenize(input, tokens);

    for (int i = 0; i < MAX_TOKENS; i++) {
        char *word = tokens[i];

        if (strlen(word) > MAX_WORD_LENGTH) {
            continue;
        }

        char firstLetter = tolower(word[0]);

        if (firstLetter < 'a' || firstLetter > 'z') {
            continue;
        }

        wordCounts[firstLetter - 'a'].word = word;
        wordCounts[firstLetter - 'a'].count = 1;
        numWords++;
    }

    qsort(wordCounts, 26, sizeof(WordCount), compareStrings);

    for (int i = 0; i < 26; i++) {
        WordCount *wordCount = &wordCounts[i];

        if (wordCount->word == NULL) {
            continue;
        }

        if (wordCount->count > 2) {
            spamCount++;
        }
    }

    free(tokens);
    free(wordCounts);

    return spamCount > 0;
}

int main() {
    char input[1000];

    printf("Enter some text to check for spam:\n");
    fgets(input, sizeof(input), stdin);

    if (isSpam(input)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}