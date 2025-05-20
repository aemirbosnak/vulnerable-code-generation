//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

void read_words(FILE* fp, WordFrequency* words, int* num_words) {
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LEN && strlen(word) <= MAX_WORD_LEN) {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
            i++;
        }
        if (i >= MAX_WORDS) {
            break;
        }
    }
    *num_words = i;
}

int compare_words(const void* a, const void* b) {
    WordFrequency* word1 = (WordFrequency*) a;
    WordFrequency* word2 = (WordFrequency*) b;
    return strcmp(word1->word, word2->word);
}

void count_frequencies(WordFrequency* words, int num_words) {
    qsort(words, num_words, sizeof(WordFrequency), compare_words);
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

int is_spam(char* message, WordFrequency* words, int num_words) {
    int spam_count = 0;
    char* tokens = strtok(message, " ");
    while (tokens!= NULL) {
        int i = 0;
        while (i < num_words) {
            if (strcmp(tokens, words[i].word) == 0) {
                spam_count += words[i].frequency;
                break;
            }
            i++;
        }
        tokens = strtok(NULL, " ");
    }
    if (spam_count >= 5) {
        return 1;
    }
    return 0;
}

int main() {
    FILE* fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open words.txt\n");
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    read_words(fp, words, &num_words);
    fclose(fp);

    count_frequencies(words, num_words);

    char message[1000];
    printf("Enter message to check for spam: ");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message, words, num_words)) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}