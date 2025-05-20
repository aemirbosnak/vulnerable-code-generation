//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    // Input text
    char text[1000];
    printf("Enter text to analyze: ");
    scanf("%s", text);

    // Convert text to lowercase
    for (int i = 0; text[i]!= '\0'; i++) {
        text[i] = tolower(text[i]);
    }

    // Split text into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(text, " \t\n\r");
    while (word!= NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " \t\n\r");
    }

    // Count positive and negative words
    int positive_words = 0;
    int negative_words = 0;
    for (int i = 0; i < num_words; i++) {
        char *word = words[i];
        int word_length = strlen(word);
        if (word_length > 0) {
            for (int j = 0; j < word_length; j++) {
                if (isalpha(word[j])) {
                    if (word[j] == 'p' || word[j] == 'P') {
                        positive_words++;
                    } else if (word[j] == 'n' || word[j] == 'N') {
                        negative_words++;
                    }
                }
            }
        }
    }

    // Calculate sentiment score
    float positive_score = (float) positive_words / num_words;
    float negative_score = (float) negative_words / num_words;
    float sentiment_score = positive_score - negative_score;

    // Output sentiment score
    printf("Sentiment score: %.2f\n", sentiment_score);

    return 0;
}