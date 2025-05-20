//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char str[1000];
    printf("Enter a sentence: ");
    gets(str);

    int sentiment = sentiment_analysis(str);

    if (sentiment == 0) {
        printf("Neutral\n");
    } else if (sentiment == 1) {
        printf("Positive\n");
    } else if (sentiment == -1) {
        printf("Negative\n");
    }

    return 0;
}

int sentiment_analysis(char *str) {
    int i, sentiment = 0, positive_words = 0, negative_words = 0;

    char *positive_words_arr[] = {"happy", "joy", "good", "excellent", "great", "wonderful", "marvelous"};
    int positive_words_arr_size = sizeof(positive_words_arr) / sizeof(char *);

    char *negative_words_arr[] = {"sad", "sadness", "bad", "terrible", "awful", "hate", "despisable"};
    int negative_words_arr_size = sizeof(negative_words_arr) / sizeof(char *);

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    for (i = 0; i < positive_words_arr_size; i++) {
        if (strstr(str, positive_words_arr[i]) != NULL) {
            positive_words++;
        }
    }

    for (i = 0; i < negative_words_arr_size; i++) {
        if (strstr(str, negative_words_arr[i]) != NULL) {
            negative_words++;
        }
    }

    if (positive_words > negative_words) {
        sentiment = 1;
    } else if (negative_words > positive_words) {
        sentiment = -1;
    }

    return sentiment;
}