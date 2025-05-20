//Falcon-180B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *token;
    FILE *file;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input);

    // Open input file
    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read input file and count word occurrences
    while ((token = fgets(input, MAX_WORD_LENGTH, file))!= NULL) {
        for (i = 0; i < strlen(token); i++) {
            if (isalpha(token[i])) {
                token[i] = tolower(token[i]);
            } else {
                token[i] = '\0';
            }
        }
        numWords++;
        if (numWords > MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words[numWords-1].word, token);
        words[numWords-1].count = 1;
    }
    fclose(file);

    // Sort words alphabetically
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print word count
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}