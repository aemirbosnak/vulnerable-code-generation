//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char input[200];

    printf("Enter your text: ");
    gets(input);

    int pos = 0, neg = 0, neutral = 0;

    char *words[] = {"good", "awesome", "happy", "love", "excellent", "nice", "great", "fun"};

    char *p = strtok(input, " ,.");

    while (p != NULL) {
        for (int i = 0; i < 8; i++) {
            if (strcmp(words[i], p) == 0) {
                pos++;
                break;
            }
        }
        if (pos == 0) {
            char *neg_words[] = {"bad", "terrible", "hate", "worst", "fail", "anger", "unhappy", "sad"};
            for (int i = 0; i < 8; i++) {
                if (strcmp(neg_words[i], p) == 0) {
                    neg++;
                    break;
                }
            }
            if (neg == 0) {
                neutral++;
            }
        }
        p = strtok(NULL, " ,.");
    }

    if (pos > neg) {
        printf("Positive sentiment detected.\n");
    } else if (neg > pos) {
        printf("Negative sentiment detected.\n");
    } else {
        printf("Neutral sentiment detected.\n");
    }

    int total = pos + neg + neutral;
    printf("Positive words found: %d (%.1f%%)\n", pos, (float)pos / total * 100);
    printf("Negative words found: %d (%.1f%%)\n", neg, (float)neg / total * 100);
    printf("Neutral words found: %d (%.1f%%)\n", neutral, (float)neutral / total * 100);

    return 0;
}