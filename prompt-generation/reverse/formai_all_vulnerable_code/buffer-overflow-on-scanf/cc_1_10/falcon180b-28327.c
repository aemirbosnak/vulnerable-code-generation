//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORD_LEN 50
#define MAX_MESSAGE_LEN 1000
#define NUM_FEATURES 10000
#define ALPHA 0.01
#define BETA 0.01
#define GAMMA 0.01
#define THRESHOLD 0.5

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct {
    int num_words;
    WordCount words[NUM_FEATURES];
} MessageFeatures;

int CompareWords(const void* a, const void* b) {
    WordCount* word1 = (WordCount*)a;
    WordCount* word2 = (WordCount*)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    char filename[MAX_MESSAGE_LEN];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    MessageFeatures* features = (MessageFeatures*)malloc(sizeof(MessageFeatures));
    features->num_words = 0;

    char message[MAX_MESSAGE_LEN];
    while (fgets(message, MAX_MESSAGE_LEN, fp)!= NULL) {
        int num_words = 0;
        char word[MAX_WORD_LEN];
        char* token = strtok(message, " ");
        while (token!= NULL) {
            strcpy(word, token);
            num_words++;
            token = strtok(NULL, " ");
        }

        features->num_words = num_words;
        qsort(features->words, NUM_FEATURES, sizeof(WordCount), CompareWords);

        int i = 0;
        for (i = 0; i < num_words && i < NUM_FEATURES; i++) {
            strcpy(features->words[i].word, word);
            features->words[i].count = 1;
        }
    }

    free(features);
    fclose(fp);

    return 0;
}