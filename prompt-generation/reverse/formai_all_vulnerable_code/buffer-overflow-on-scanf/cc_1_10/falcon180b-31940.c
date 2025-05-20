//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define MAX_NUM_WORDS 1000

// Struct to store word and its frequency
typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

// Struct to store a sentence
typedef struct {
    int numWords;
    WordFreq words[MAX_NUM_WORDS];
} Sentence;

// Function to split a sentence into words
void splitSentence(char* sentence, Sentence* s) {
    char* word = strtok(sentence, ",.?!:;\"'");
    int i = 0;

    while (word!= NULL) {
        if (i >= MAX_NUM_WORDS) {
            break;
        }

        strcpy(s->words[i].word, word);
        s->words[i].freq = 1;
        i++;

        word = strtok(NULL, ",.?!:;\"'");
    }

    s->numWords = i;
}

// Function to compare two words (case insensitive)
int compareWords(const void* a, const void* b) {
    WordFreq* w1 = (WordFreq*) a;
    WordFreq* w2 = (WordFreq*) b;

    return strcasecmp(w1->word, w2->word);
}

// Function to sort words by frequency
void sortWords(Sentence* s) {
    qsort(s->words, s->numWords, sizeof(WordFreq), compareWords);
}

// Function to print words and their frequencies
void printWords(Sentence* s) {
    for (int i = 0; i < s->numWords; i++) {
        printf("%s: %d\n", s->words[i].word, s->words[i].freq);
    }
}

// Main function
int main() {
    Sentence s;
    char sentence[MAX_WORD_LEN];

    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);

    splitSentence(sentence, &s);
    sortWords(&s);
    printWords(&s);

    return 0;
}