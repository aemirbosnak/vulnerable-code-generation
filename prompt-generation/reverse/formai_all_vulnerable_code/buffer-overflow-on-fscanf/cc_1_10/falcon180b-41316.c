//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50
#define SPAM_THRESHOLD 0.8

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWordFrequency(const void *a, const void *b) {
    WordFrequency *w1 = (WordFrequency *) a;
    WordFrequency *w2 = (WordFrequency *) b;
    return strcmp(w1->word, w2->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    FILE *file;
    int i, j, wordCount, totalWords, spamCount;
    WordFrequency *wordFrequencies;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    wordCount = 0;
    totalWords = 0;
    spamCount = 0;

    while (fscanf(file, "%s", input)!= EOF) {
        totalWords++;
        if (strcasecmp(input, "spam") == 0) {
            spamCount++;
        }
    }

    fclose(file);

    if (spamCount == 0 || spamCount == totalWords) {
        printf("Invalid input file.\n");
        exit(1);
    }

    spamCount = (int) (spamCount * SPAM_THRESHOLD);

    wordFrequencies = (WordFrequency *) malloc(MAX_WORDS * sizeof(WordFrequency));
    if (wordFrequencies == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    memset(wordFrequencies, 0, MAX_WORDS * sizeof(WordFrequency));

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", input)!= EOF) {
        if (strcasecmp(input, "spam") == 0) {
            wordCount++;
        } else {
            strcpy(word, input);
            for (i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            wordFrequencies[wordCount].word = strdup(word);
            wordFrequencies[wordCount].count = 1;
            wordCount++;
        }
    }

    fclose(file);

    qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compareWordFrequency);

    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);

    return 0;
}