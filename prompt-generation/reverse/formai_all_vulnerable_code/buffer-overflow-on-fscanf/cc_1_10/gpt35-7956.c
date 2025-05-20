//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A data structure for storing a word and its corresponding sentiment score */
typedef struct {
    char word[20];
    int score;
} SentimentWord;

/* A hash table of sentiment words */
SentimentWord hashTable[1000];

/* Returns the hash value for a given word */
int hash(char *word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % 1000;
}

/* Adds a new sentiment word to the hash table */
void addSentimentWord(char *word, int score) {
    int index = hash(word);
    while (hashTable[index].score != 0) {
        index = (index + 1) % 1000;
    }
    strcpy(hashTable[index].word, word);
    hashTable[index].score = score;
}

/* Reads a file of sentiment words and adds them to the hash table */
void readSentimentWords(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    char word[20];
    int score;
    while (fscanf(fp, "%s %d", word, &score) == 2) {
        addSentimentWord(word, score);
    }
    fclose(fp);
}

/* Calculates the sentiment score for a given text */
int calculateSentiment(char *text) {
    int score = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        int index = hash(token);
        while (strcmp(token, hashTable[index].word) != 0) {
            index = (index + 1) % 1000;
            if (hashTable[index].score == 0) {
                break;
            }
        }
        score += hashTable[index].score;
        token = strtok(NULL, " ");
    }
    return score;
}

/* Driver function */
int main(void) {
    readSentimentWords("sentiment_words.txt");

    char text[10000];
    printf("Enter text to be analyzed: ");
    fgets(text, 10000, stdin);

    int score = calculateSentiment(text);
    printf("Sentiment score: %d\n", score);

    return 0;
}