//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define FILE_NAME "input.txt"

struct Word {
    char word[WORD_LENGTH];
    int sentiment_score;
};

struct Word words[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp;
    char line[100];
    char word[WORD_LENGTH];
    int score;

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %d", word, &score);

        strcpy(words[num_words].word, word);
        words[num_words].sentiment_score = score;

        num_words++;
    }

    fclose(fp);
}

void preprocess(char text[]) {
    int i, j;
    int text_length = strlen(text);

    for (i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
        } else if (text[i] == ' ') {
            i++; // Move to next character after space
            while (isspace(text[i])) {
                i++; // Remove consecutive spaces
            }
            text[i - 1] = ' '; // Replace the last space with a single space
        }
    }

    text[text_length] = '\0'; // Add null terminator
}

int analyze_sentiment(char text[]) {
    int i, score = 0;

    preprocess(text);

    for (i = 0; i < num_words; i++) {
        if (strstr(text, words[i].word) != NULL) {
            score += words[i].sentiment_score;
            break;
        }
    }

    return score;
}

int main() {
    char text[1000];
    int sentiment_score;

    load_dictionary();

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    sentiment_score = analyze_sentiment(text);

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}