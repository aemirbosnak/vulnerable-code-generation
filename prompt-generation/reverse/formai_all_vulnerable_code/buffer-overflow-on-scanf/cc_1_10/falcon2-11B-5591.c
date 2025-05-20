//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
//A peaceful Sentiment analysis tool example program in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

// Define the sentiment analysis tool
void sentiment_analysis(char* text) {
    int len = strlen(text);
    int positive = 0, negative = 0, neutral = 0;

    // Count the number of positive, negative, and neutral words in the text
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            if (text[i] >= 'a' && text[i] <= 'z') {
                if (islower(text[i])) {
                    if (isupper(text[i + 1])) {
                        positive++;
                    } else if (isupper(text[i - 1])) {
                        negative++;
                    } else if (isupper(text[i + 1]) && isupper(text[i - 1])) {
                        neutral++;
                    }
                }
            }
        }
    }

    // Calculate the overall sentiment score
    float positive_score = positive / (positive + negative + neutral);
    float negative_score = negative / (positive + negative + neutral);
    float neutral_score = neutral / (positive + negative + neutral);

    float sentiment_score = (positive_score - negative_score) / 2;

    // Output the sentiment analysis result
    printf("Sentiment Analysis Result: %s\n", (sentiment_score > 0.5)? "Positive" : "Negative");
}

int main() {
    char text[1000];
    printf("Enter the text to be analyzed: ");
    scanf("%s", text);

    sentiment_analysis(text);

    return 0;
}