//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char* word;
    int count;
} WordCount;

typedef struct {
    WordCount* words;
    int size;
    int capacity;
} BagOfWords;

BagOfWords* bag_of_words_create() {
    BagOfWords* bag = (BagOfWords*)malloc(sizeof(BagOfWords));
    bag->words = NULL;
    bag->size = 0;
    bag->capacity = 1000;
    bag->words = (WordCount*)malloc(bag->capacity * sizeof(WordCount));
    return bag;
}

void bag_of_words_destroy(BagOfWords* bag) {
    for (int i = 0; i < bag->size; i++) {
        free(bag->words[i].word);
    }
    free(bag->words);
    free(bag);
}

void bag_of_words_add_word(BagOfWords* bag, char* word) {
    for (int i = 0; i < bag->size; i++) {
        if (strcmp(bag->words[i].word, word) == 0) {
            bag->words[i].count++;
            return;
        }
    }
    if (bag->size >= bag->capacity) {
        bag->capacity *= 2;
        bag->words = (WordCount*)realloc(bag->words, bag->capacity * sizeof(WordCount));
    }
    bag->words[bag->size].word = strdup(word);
    bag->words[bag->size].count = 1;
    bag->size++;
}

int main() {
    FILE* file = fopen("text.txt", "r");
    char ch;
    BagOfWords* bag = bag_of_words_create();
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, file);
            char word[100];
            fscanf(file, "%s", word);
            bag_of_words_add_word(bag, word);
        }
    }
    fclose(file);

    for (int i = 0; i < bag->size; i++) {
        printf("%s: %d\n", bag->words[i].word, bag->words[i].count);
    }

    bag_of_words_destroy(bag);
    return 0;
}