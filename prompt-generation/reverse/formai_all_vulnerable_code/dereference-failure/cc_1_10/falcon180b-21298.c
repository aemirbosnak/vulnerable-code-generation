//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct WordFrequency *wordA = (struct WordFrequency *)a;
    struct WordFrequency *wordB = (struct WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    struct WordFrequency *wordFrequencyTable = NULL;
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Tokenize the sentence
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Check if the word is already in the frequency table
        struct WordFrequency *wordFrequency = bsearch(token, wordFrequencyTable, wordCount, sizeof(struct WordFrequency), compareWords);

        // If the word is not in the frequency table, add it
        if (wordFrequency == NULL) {
            wordFrequency = (struct WordFrequency *)malloc(sizeof(struct WordFrequency));
            strcpy(wordFrequency->word, token);
            wordFrequency->frequency = 1;
            wordFrequencyTable = (struct WordFrequency *)realloc(wordFrequencyTable, sizeof(struct WordFrequency) * (wordCount + 1));
            wordFrequencyTable[wordCount] = *wordFrequency;
            wordCount++;
        } else {
            // If the word is already in the frequency table, increment its frequency
            wordFrequency->frequency++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Sort the frequency table by word
    qsort(wordFrequencyTable, wordCount, sizeof(struct WordFrequency), compareWords);

    // Print the frequency table
    printf("Word\tFrequency\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].frequency);
    }

    return 0;
}