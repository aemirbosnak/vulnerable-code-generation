//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"bored", -1},
    {"confused", 0}
};

int load_sentiments() {
    FILE *file = fopen(SENTIMENT_FILE, "r");
    if (file == NULL) {
        printf("Error loading sentiment file.\n");
        return -1;
    }

    char line[MAX_SENTENCE_LENGTH];
    while (fgets(line, MAX_SENTENCE_LENGTH, file)!= NULL) {
        char *sentiment_name = strtok(line, ",");
        int value = atoi(strtok(NULL, ","));

        for (int i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(sentiment_name, sentiments[i].name) == 0) {
                sentiments[i].value = value;
                break;
            }
        }
    }

    fclose(file);
    return 0;
}

int analyze_sentence(char *sentence) {
    int total_value = 0;

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        for (int i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcasecmp(token, sentiments[i].name) == 0) {
                total_value += sentiments[i].value;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return total_value;
}

int main() {
    if (load_sentiments()!= 0) {
        return -1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to analyze: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int value = analyze_sentence(sentence);
    if (value > 0) {
        printf("The sentence is positive.\n");
    } else if (value < 0) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}