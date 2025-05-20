//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char str[1000];
    printf("Enter a sentence: ");
    fgets(str, 1000, stdin);

    int len = strlen(str);
    str[len - 1] = '\0';

    int sentiment = sentiment_analysis(str);

    if (sentiment == 0) {
        printf("Neutral\n");
    } else if (sentiment == 1) {
        printf("Positive\n");
    } else if (sentiment == 2) {
        printf("Negative\n");
    }

    return 0;
}

int sentiment_analysis(char *str) {
    int score = 0;
    int i = 0;

    while (str[i] != '\0') {
        char word[20];
        int word_len = 0;

        // Extract words from the sentence
        while (str[i] != ' ' && str[i] != '\0') {
            word[word_len] = str[i];
            word_len++;
            i++;
        }

        // Assign sentiment score for each word
        if (strcmp(word, "happy") == 0) {
            score++;
        } else if (strcmp(word, "sad") == 0) {
            score--;
        } else if (strcmp(word, "good") == 0) {
            score++;
        } else if (strcmp(word, "bad") == 0) {
            score--;
        }

        // Increment i to move to the next word in the sentence
        i++;
    }

    return score;
}