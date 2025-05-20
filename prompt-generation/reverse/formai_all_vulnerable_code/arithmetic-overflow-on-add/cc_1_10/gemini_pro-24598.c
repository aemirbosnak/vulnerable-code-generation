//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SPAM_WORDS 10

typedef struct {
    char *word;
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    // Load the spam words
    char *spamWords[MAX_SPAM_WORDS] = {"free", "money", "click", "offer", "win", "prize", "now", "today", "limited", "time"};

    // Load the input text
    char inputText[1000];
    printf("Enter your text: ");
    fgets(inputText, sizeof(inputText), stdin);

    // Tokenize the input text
    char *words[MAX_WORDS];
    char *token;
    int numWords = 0;
    token = strtok(inputText, " ");
    while (token != NULL) {
        words[numWords] = token;
        numWords++;
        token = strtok(NULL, " ");
    }

    // Count the occurrence of each word
    Word wordCounts[MAX_WORDS];
    for (int i = 0; i < numWords; i++) {
        int found = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[i], wordCounts[j].word) == 0) {
                wordCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            wordCounts[numWords].word = words[i];
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    // Sort the word counts
    qsort(wordCounts, numWords, sizeof(Word), compareWords);

    // Check for spam words
    int spamScore = 0;
    for (int i = 0; i < numWords; i++) {
        for (int j = 0; j < MAX_SPAM_WORDS; j++) {
            if (strcmp(wordCounts[i].word, spamWords[j]) == 0) {
                spamScore += wordCounts[i].count;
            }
        }
    }

    // Print the spam score
    printf("Spam score: %d\n", spamScore);

    // Classify the text as spam or not spam
    if (spamScore > 10) {
        printf("This text is likely spam.\n");
    } else {
        printf("This text is not likely spam.\n");
    }

    return 0;
}