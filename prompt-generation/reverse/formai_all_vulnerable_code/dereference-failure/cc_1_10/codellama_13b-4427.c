//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
/*
 * Sentiment Analysis Tool
 *
 * Analyzes a piece of text and determines the sentiment of it.
 *
 * Usage: ./sentiment_analysis <text>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024

typedef struct {
    char* text;
    int len;
} Sentence;

Sentence* split_sentences(char* text) {
    Sentence* sentences = malloc(sizeof(Sentence) * 1024);
    int sentence_count = 0;
    char* sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[sentence_count].text = sentence;
        sentences[sentence_count].len = strlen(sentence);
        sentence_count++;
        sentence = strtok(NULL, ".");
    }
    return sentences;
}

void analyze_sentence(Sentence* sentence) {
    int len = sentence->len;
    char* text = sentence->text;
    int positive_count = 0;
    int negative_count = 0;
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ') {
            continue;
        }
        if (text[i] == '+' || text[i] == ':') {
            positive_count++;
        } else if (text[i] == '-' || text[i] == ':') {
            negative_count++;
        }
    }
    if (positive_count > negative_count) {
        printf("Positive sentiment: %d\n", positive_count);
    } else if (negative_count > positive_count) {
        printf("Negative sentiment: %d\n", negative_count);
    } else {
        printf("Neutral sentiment: %d\n", positive_count);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./sentiment_analysis <text>\n");
        return 1;
    }
    Sentence* sentences = split_sentences(argv[1]);
    for (int i = 0; i < sentences->len; i++) {
        analyze_sentence(&sentences[i]);
    }
    return 0;
}