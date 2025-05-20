//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH];
    int sentiment;
} Word;

Word words[MAX_WORDS];

int setup() {
    FILE *file = fopen("sentiment.txt", "r");
    int i = 0;
    if (file == NULL) {
        printf("Error: Unable to open sentiment file.\n");
        return -1;
    }

    while (fscanf(file, "%s%d", words[i].word, &words[i].sentiment) != EOF) {
        i++;
    }

    fclose(file);
    return i;
}

int analyze(char *input) {
    int sum = 0;
    int i = 0;
    char *token;
    int num_words = 0;

    token = strtok(input, " .,?!");

    while (token != NULL) {
        for (i = 0; i < setup(); i++) {
            if (strcmp(token, words[i].word) == 0) {
                sum += words[i].sentiment;
                num_words++;
                break;
            }
        }
        token = strtok(NULL, " .,?!");
    }

    if (num_words == 0) {
        printf("Error: Unable to identify any words in the input.\n");
        return -1;
    }

    return sum / num_words;
}

int main() {
    char input[MAX_LENGTH];
    int sentiment;

    if (setup() < 0) {
        return 1;
    }

    printf("Enter a sentence: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    sentiment = analyze(input);

    if (sentiment > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}