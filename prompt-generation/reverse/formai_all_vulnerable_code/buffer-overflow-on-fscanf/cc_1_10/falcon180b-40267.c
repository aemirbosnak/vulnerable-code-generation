//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define THRESHOLD 0.8

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    char *token;
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    // Read in the input file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Count the words in the input file
    while (fscanf(fp, "%s", input)!= EOF) {
        word = strtok(input, " \t\n\r\f");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                exit(1);
            }
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
            word = strtok(NULL, " \t\n\r\f");
        }
    }
    fclose(fp);

    // Calculate the spam score for each word
    for (i = 0; i < num_words; i++) {
        double spam_score = (double)words[i].count / (num_words * 2);
        if (spam_score >= THRESHOLD) {
            printf("%s is a spam word (score: %.2f)\n", words[i].word, spam_score);
        }
    }

    return 0;
}