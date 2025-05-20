//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 100

typedef struct {
    char word[20];
    int sentiment;
} Word;

Word dictionary[DICTIONARY_SIZE];

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    int i = 0;
    char line[100];

    if (fp == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %d", dictionary[i].word, &dictionary[i].sentiment);
        i++;
    }

    fclose(fp);
}

int get_word_sentiment(char *word) {
    int i;
    for (i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].sentiment;
        }
    }

    return 0; // unknown word
}

int analyze_sentiment(char *text) {
    int word_length, total_sentiment = 0;
    char word[20];

    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            if (word[0] != '\0') {
                word_length = i - (int) (strlen(word) - 1);
                total_sentiment += get_word_sentiment(&word[0]) * word_length;
                memset(word, '\0', sizeof(word));
            }
        } else {
            word[i - (strlen(word) - 1)] = text[i];
        }
    }

    if (strlen(word) > 0) {
        word_length = strlen(word);
        total_sentiment += get_word_sentiment(word) * word_length;
    }

    return total_sentiment;
}

int main() {
    load_dictionary();

    char text[200];
    printf("Enter text for sentiment analysis: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0'; // remove newline character

    int sentiment = analyze_sentiment(text);

    if (sentiment > 0) {
        printf("Positive sentiment: %d\n", sentiment);
    } else if (sentiment < 0) {
        printf("Negative sentiment: %d\n", sentiment);
    } else {
        printf("Neutral sentiment: 0\n");
    }

    return 0;
}