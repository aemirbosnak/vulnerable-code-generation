//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <string.h>

int sentiment_analysis(char *sentence) {
    int pos_words = 0;
    int neg_words = 0;

    char *positive[] = {"good", "great", "excellent", "fantastic", "love"};
    char *negative[] = {"bad", "terrible", "awful", "hate", "dislike"};

    // Tokenize sentence into words
    char *word = strtok(sentence, " ");

    while (word != NULL) {
        // Check if word is in positive or negative list
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, positive[i]) == 0) {
                pos_words++;
            }
            if (strcmp(word, negative[i]) == 0) {
                neg_words++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Calculate sentiment score
    int score = pos_words - neg_words;

    // Return sentiment score
    return score;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character from sentence if present
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    // Calculate sentiment score of sentence
    int score = sentiment_analysis(sentence);

    // Output sentiment score
    printf("Sentiment score of sentence is: %d\n", score);

    // Determine sentiment label
    if (score > 0) {
        printf("Positive sentiment\n");
    } else if (score < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}