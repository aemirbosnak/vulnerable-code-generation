//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    char input[MAX_WORDS][MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i, j, k;

    printf("Enter a string to count words:\n");
    fgets(input[0], MAX_WORD_LEN, stdin);

    // Split input string into words
    for (i = 0; input[0][i]!= '\0'; i++) {
        if (isspace(input[0][i])) {
            input[0][i] = '\0';
            numWords++;
        }
    }

    // Count occurrences of each word
    for (i = 1; i < numWords; i++) {
        strcpy(input[i], input[0] + i);
        for (j = 0; input[i][j]!= '\0'; j++) {
            input[i][j] = tolower(input[i][j]);
        }
    }

    for (i = 0; i < numWords; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (strcmp(input[i], input[j]) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    // Print word counts
    for (i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}