//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MIN_SCORE 0.8

int getWordFrequency(char* text, int length) {
    int frequency[26] = {0};
    int i;

    for (i = 0; i < length; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            frequency[text[i] - 'a']++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            return i;
        }
    }

    return -1;
}

int calculateScore(char* text) {
    int frequency = getWordFrequency(text, strlen(text));
    float score = 0.0;

    if (frequency == -1) {
        return 0;
    }

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            score += (float)(text[i] - 'a') / frequency;
        }
    }

    return score >= MIN_SCORE? 1 : 0;
}

int main() {
    char text[MAX_LENGTH] = "The quick brown fox jumps over the lazy dog.";
    int score = calculateScore(text);

    if (score == 1) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}