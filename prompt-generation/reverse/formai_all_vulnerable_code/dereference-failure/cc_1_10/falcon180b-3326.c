//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct Word words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            words[i].word[strlen(words[i].word) - 1] = '\0';
            i++;
        } else {
            strcat(words[i].word, &ch);
        }
    }
    words[i].word[strlen(words[i].word) - 1] = '\0';
    i++;
}

void count_words(struct Word words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            words[i].count = 1;
        }
    }
}

void analyze_sentiment(struct Word words[MAX_WORDS], int num_words, double *pos, double *neg, double *neu) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, "happy") == 0) {
            (*pos)++;
        } else if (strcmp(words[i].word, "sad") == 0) {
            (*neg)++;
        } else {
            (*neu)++;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    struct Word words[MAX_WORDS];
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(file, words);
    count_words(words);

    double pos = 0, neg = 0, neu = 0;
    analyze_sentiment(words, num_words, &pos, &neg, &neu);

    printf("Positive words: %d\n", pos);
    printf("Negative words: %d\n", neg);
    printf("Neutral words: %d\n", neu);

    fclose(file);
    return 0;
}