//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* word;
    int sentiment;
} Rule;

#define NUM_RULES 10

Rule rules[NUM_RULES] = {
    {"happy", 1},
    {"joyful", 1},
    {"excellent", 1},
    {"love", 1},
    {"amazing", 1},

    {"sad", -1},
    {"miserable", -1},
    {"terrible", -1},
    {"hate", -1},
    {"disappointing", -1},
};

int analyze_sentiment(char* text) {
    int total_sentiment = 0;
    char text_copy[100][50]; // assuming max 50 characters per word and 100 words
    int num_words = 0;

    strcpy(text_copy[num_words], strtok(text, " "));
    while (text_copy[num_words++][0] != '\0') {
        for (int i = 0; i < NUM_RULES; i++) {
            if (strcmp(text_copy[num_words - 1], rules[i].word) == 0) {
                total_sentiment += rules[i].sentiment;
                break;
            }
        }

        strcpy(text_copy[num_words], strtok(NULL, " "));
    }

    return total_sentiment / num_words;
}

int main() {
    char input[100];

    while (1) {
        printf("Enter text or type 'quit' to exit: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int sentiment = analyze_sentiment(input);
        if (sentiment > 0) {
            printf("Sentiment: Positive\n");
        } else if (sentiment < 0) {
            printf("Sentiment: Negative\n");
        } else {
            printf("Sentiment: Neutral\n");
        }
    }

    return 0;
}