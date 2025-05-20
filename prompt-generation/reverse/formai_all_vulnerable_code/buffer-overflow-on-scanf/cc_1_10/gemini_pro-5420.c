//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defines the number of emotions to analyze for
#define NUM_EMOTIONS 6

// Define the emotions to analyze for
char *emotions[] = {
    "joy",
    "sadness",
    "anger",
    "fear",
    "surprise",
    "disgust"
};

// Define the minimum and maximum values for each emotion
int min_values[] = {
    0,
    0,
    0,
    0,
    0,
    0
};
int max_values[] = {
    10,
    10,
    10,
    10,
    10,
    10
};

// Function to analyze the sentiment of a string
int analyze_sentiment(char *string) {
    // Initialize the emotion scores
    int emotion_scores[NUM_EMOTIONS];
    for (int i = 0; i < NUM_EMOTIONS; i++) {
        emotion_scores[i] = 0;
    }

    // Tokenize the string into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(string, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Count the occurrences of each emotion word
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < NUM_EMOTIONS; j++) {
            if (strcmp(words[i], emotions[j]) == 0) {
                emotion_scores[j]++;
            }
        }
    }

    // Calculate the average emotion score
    int average_emotion_score = 0;
    for (int i = 0; i < NUM_EMOTIONS; i++) {
        average_emotion_score += emotion_scores[i];
    }
    average_emotion_score /= NUM_EMOTIONS;

    // Return the average emotion score
    return average_emotion_score;
}

// Main function
int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Analyze the sentiment of the string
    int sentiment_score = analyze_sentiment(input);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    // Determine the emotion based on the sentiment score
    char *emotion = NULL;
    for (int i = 0; i < NUM_EMOTIONS; i++) {
        if (sentiment_score >= min_values[i] && sentiment_score <= max_values[i]) {
            emotion = emotions[i];
            break;
        }
    }

    // Print the emotion
    printf("Emotion: %s\n", emotion);

    return 0;
}