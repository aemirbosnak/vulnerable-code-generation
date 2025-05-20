//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50

typedef struct Word {
    char word[WORD_LEN];
    int sentiment;
} Word;

void load_sentiment_file(const char *filename, Word words[]) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    char word[WORD_LEN];
    int sentiment;

    if (file == NULL) {
        perror("Error opening sentiment file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%d", word, &sentiment);
        strcpy(words[strlen(words)].word, word);
        words[strlen(words)].sentiment = sentiment;
    }

    fclose(file);
}

int analyze_sentiment(const char *text, Word words[]) {
    int sentiment_score = 0;
    int num_words = 0;
    char word[WORD_LEN];

    char *token = strtok(strdup(text), " .,?!:;-");

    while (token != NULL) {
        strcpy(word, token);
        for (int i = 0; i < strlen(words); i++) {
            if (strcasecmp(words[i].word, word) == 0) {
                sentiment_score += words[i].sentiment;
                num_words++;
                break;
            }
        }
        token = strtok(NULL, " .,?!:;-");
    }

    if (num_words == 0) {
        return 0;
    }

    return sentiment_score / num_words;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Word words[MAX_WORDS];
    load_sentiment_file("sentiment.txt", words);

    const char *text = argv[1];
    int sentiment_score = analyze_sentiment(text, words);

    printf("Sentiment score: %d\n", sentiment_score);

    if (sentiment_score > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment_score < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return EXIT_SUCCESS;
}