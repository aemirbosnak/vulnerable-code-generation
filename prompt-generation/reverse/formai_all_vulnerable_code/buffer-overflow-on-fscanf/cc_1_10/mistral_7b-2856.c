//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct { char word[20]; int sentiment; } word_t;

#define NUM_WORDS 1000
word_t words[NUM_WORDS];

int init_words() {
    FILE * fp = fopen("sentiment_words.txt", "r");
    int i = 0;
    if (fp == NULL) return 0;

    while (fscanf(fp, "%s %d", words[i].word, &words[i].sentiment) != EOF) i++;
    fclose(fp);
    return i;
}

int main() {
    int num_words = 0;
    int i, j;
    char text[1000];
    int sum_sentiment = 0;

    num_words = init_words();

    printf("Type your text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    for (i = 0; text[i] != '\0'; i++) {
        text[i] = tolower(text[i]);
    }

    for (i = 0; i < num_words; i++) {
        int start, end;
        start = strspn(text, words[i].word);
        if (start == 0) continue;
        end = start + strlen(words[i].word);
        if (end > strlen(text)) break;
        sum_sentiment += words[i].sentiment;
        memmove(text + start, text + end, strlen(text + end) - strlen(words[i].word) + 1);
        text[strlen(text) - 1] = '\0';
    }

    printf("Sum of sentiment: %d\n", sum_sentiment);

    return 0;
}