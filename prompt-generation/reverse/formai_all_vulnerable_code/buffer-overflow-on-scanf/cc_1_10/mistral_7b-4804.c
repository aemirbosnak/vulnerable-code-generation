//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_CHAR 50

// Predefined words for post-apocalyptic sentiment analysis
const char *post_apocalyptic_words[] = {
    "ruins", "ashes", "desolation", "survive", "hope", "scavenger",
    "wasteland", "mutant", "decay", "fight", "apocalypse", "radioactive",
    "abandoned", "post-apocalyptic", "radiation", "survival", "zombie"
};

// Function to check if a word is in the predefined list
int is_post_apocalyptic(char *word) {
    int i;
    for (i = 0; i < sizeof(post_apocalyptic_words) / sizeof(post_apocalyptic_words[0]); i++) {
        if (strcmp(word, post_apocalyptic_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to analyze sentiment based on the presence of post-apocalyptic words
int analyze_sentiment(char *sentence) {
    int i, word_count = 0, negative_count = 0;
    char words[MAX_WORDS][MAX_CHAR];
    char *token = strtok(sentence, " ");

    while (token != NULL && word_count < MAX_WORDS) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }

    for (i = 0; i < word_count; i++) {
        if (is_post_apocalyptic(words[i])) {
            negative_count++;
        }
    }

    return negative_count;
}

// Main function to read input and print sentiment analysis result
int main() {
    char sentence[100];
    int sentiment;

    printf("Enter a sentence in post-apocalyptic style: ");
    scanf("%s", sentence);

    sentiment = analyze_sentiment(sentence);

    if (sentiment > 0) {
        printf("Negative sentiment detected: %d post-apocalyptic words found.\n", sentiment);
    } else {
        printf("No negative sentiment detected.\n");
    }

    return 0;
}