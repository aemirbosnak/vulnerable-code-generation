//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    // Negative words
    -1, // "bad"
    -1, // "terrible"
    -1, // "worst"

    // Positive words
    1, // "good"
    1, // "great"
    1  // "best"
};

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
    for (int i = 0; i < sizeof(sentiment_scores) / sizeof(int); i++) {
        if (strcmp(word, sentiment_scores[i]) == 0) {
            return sentiment_scores[i];
        }
    }

    // Word not found, return 0
    return 0;
}

// Analyze the sentiment of a given sentence
int analyze_sentiment(char *sentence) {
    // Convert the sentence to lowercase
    char lower_sentence[strlen(sentence) + 1];
    strcpy(lower_sentence, sentence);
    for (int i = 0; i < strlen(lower_sentence); i++) {
        lower_sentence[i] = tolower(lower_sentence[i]);
    }

    // Split the sentence into words
    char *words[strlen(lower_sentence) + 1];
    int num_words = 0;
    char *word = strtok(lower_sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    int sentiment_score = 0;
    for (int i = 0; i < num_words; i++) {
        sentiment_score += get_sentiment_score(words[i]);
    }

    return sentiment_score;
}

// Print the sentiment of a given sentence
void print_sentiment(char *sentence) {
    int sentiment_score = analyze_sentiment(sentence);

    if (sentiment_score > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (sentiment_score < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }
}

int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Print the sentiment of the sentence
    print_sentiment(sentence);

    return 0;
}