//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 50
#define VOCAB_SIZE 10000
#define BUFFER_SIZE 1024

typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment;
} Word;

Word vocab[VOCAB_SIZE];
int num_words = 0;

int init_vocab() {
    FILE *fp = fopen("sentiment_vocab.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open sentiment vocabulary file.\n");
        return 1;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp) != NULL) {
        sscanf(line, "%s %d", vocab[num_words].word, &vocab[num_words].sentiment);
        num_words++;
    }

    fclose(fp);
    return 0;
}

int get_sentiment(char *text) {
    char words[100][MAX_WORD_LENGTH];
    int num_words_in_text = 0;

    char *token = strtok(text, " .,!?");
    while (token != NULL) {
        strcpy(words[num_words_in_text], token);
        num_words_in_text++;
        token = strtok(NULL, " .,!?");
    }

    int total_sentiment = 0;
    for (int i = 0; i < num_words_in_text; i++) {
        int index = -1;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], vocab[j].word) == 0) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            // Unknown word, assume neutral sentiment
            total_sentiment += 0;
        } else {
            total_sentiment += vocab[index].sentiment;
        }
    }

    return total_sentiment;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    if (init_vocab() != 0) {
        return 1;
    }

    int sentiment = get_sentiment(argv[1]);
    printf("Text sentiment: %d\n", sentiment);

    return 0;
}