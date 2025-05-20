//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wa = (Word *)a;
    Word *wb = (Word *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    // Get the input text from the user.
    char *text = malloc(1000);
    printf("Enter the text to be analyzed: ");
    scanf("%[^\n]", text);

    // Tokenize the text into words.
    char *words[MAX_WORDS];
    int numWords = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each word.
    Word counts[MAX_WORDS];
    for (int i = 0; i < numWords; i++) {
        int found = 0;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(words[i], counts[j].word) == 0) {
                counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            counts[numWords].word = words[i];
            counts[numWords++].count = 1;
        }
    }

    // Sort the words by their counts.
    qsort(counts, numWords, sizeof(Word), compareWords);

    // Print the words and their counts.
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }

    // Free the allocated memory.
    free(text);
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }

    return 0;
}