//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 10

int main() {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int line_length, word_length;
    int line_count = 0;
    int word_count = 0;
    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        line_length = strlen(line);
        line[line_length - 1] = '\0'; // remove newline character
        line_count++;

        // split line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            word_length = strlen(token);
            strncpy(word, token, word_length);
            word[word_length] = '\0';
            token = strtok(NULL, " ");
            word_count++;

            // check if word is positive, negative, or neutral
            if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
                positive_count++;
            } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
                negative_count++;
            } else {
                neutral_count++;
            }
        }
    }

    // calculate sentiment score
    float sentiment_score = (float)positive_count / word_count;

    // print results
    printf("Sentiment Score: %f\n", sentiment_score);
    printf("Positive Words: %d\n", positive_count);
    printf("Negative Words: %d\n", negative_count);
    printf("Neutral Words: %d\n", neutral_count);
    printf("Total Words: %d\n", word_count);

    return 0;
}