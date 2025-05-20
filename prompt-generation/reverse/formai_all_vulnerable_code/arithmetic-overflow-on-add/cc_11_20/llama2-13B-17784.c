//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 10000

int main() {
    char text[MAX_LENGTH];
    int word_count = 0;
    int i = 0;

    // Ask user for text
    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    // Count words
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            word_count++;
        }
    }

    // Print results
    printf("Word count: %d\n", word_count);

    // Frequency analysis
    int freq[10];
    for (i = 0; i < 10; i++) {
        freq[i] = 0;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            continue;
        }

        freq[text[i] - 'a']++;
    }

    for (i = 0; i < 10; i++) {
        printf("%c: %d\n", 'a' + i, freq[i]);
    }

    // Sentiment analysis
    int positive = 0, negative = 0, neutral = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            continue;
        }

        if (text[i] == 'p' || text[i] == 'P') {
            positive++;
        } else if (text[i] == 'n' || text[i] == 'N') {
            negative++;
        } else {
            neutral++;
        }
    }

    printf("Sentiment: %d positive, %d negative, %d neutral\n", positive, negative, neutral);

    // Text summary
    char summary[50];
    int j = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            continue;
        }

        summary[j++] = text[i];
    }

    summary[j] = '\0';

    printf("Summary: %s\n", summary);

    return 0;
}